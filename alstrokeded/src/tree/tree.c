#include "tree.h"

BinTree Tree(TRElType Akar, BinTree L, BinTree R){
    BinTree P = (taddress)malloc(sizeof(TRNode));
    Akar(P) = Akar;
    Left(P) = L;
    Right(P) = P;

    return P;
}

taddress AlokasiT(TRElType X){
    taddress P = (taddress)malloc(sizeof(TRNode));
    Akar(P) = X;
    Left(P) = Nil;
    Right(P) = Nil;

    return P;
}

void DealokasiT(taddress P) {
    free(P);
}

boolean IsTreeEmpty(BinTree P){
    return (P == Nil);
}

boolean IsTreeOneElmt(BinTree P){
    if (IsTreeEmpty(P)){
        return false;
    }
    return (Left(P)==Nil && Right(P)==Nil);
}

boolean IsUnerLeftT(BinTree P){
    if (IsTreeEmpty(P)){
        return false;
    }
    else{
        return ((Left(P) != Nil) && (Right(P) == Nil));
    }
}
boolean IsUnerRightT(BinTree P){
    if (IsTreeEmpty(P)){
        return false;
    }
    else{
        return ((Left(P) == Nil) && (Right(P) != Nil));
    }
}
boolean IsBinerT(BinTree P) {
    if (IsTreeEmpty(P)){
        return false;
    }
    else{
        return ((Left(P) != Nil) && (Right(P) != Nil));
    }
}

int NbElmtT(BinTree P){
    if (IsTreeEmpty(P)){
        return 0;
    }
    else{
        return (1 + NbElmtT(Left(P)) + NbElmtT(Right(P)));
    }
}

int NbDaun(BinTree P){
    if (IsTreeEmpty(P)){
        return 0;
    }
    else if (IsTreeOneElmt(P)){
        return 1;
    }
    else{
        return (NbDaun(Left(P)) + NbDaun(Right(P)));
    }
}

int TinggiT(BinTree P){
    /* Pohon Biner mungkin kosong.
    Mengirim “height”, yaitu tinggi dari pohon  */
    if (IsTreeEmpty(P)){
        return 0;
    }
    else{
        if (TinggiT(Left(P)) >= TinggiT(Right(P))){
            return (1 + TinggiT(Left(P)));
        }
        else{
            return (1 + TinggiT(Right(P)));
        }
    }
}

boolean SearchT(BinTree P, TRElType X){
    if(IsTreeEmpty(P)){
        return false;
    }
    else{
        if (Akar(P) == X){
            return true;
        }
        else{
            return (SearchT(Left(P), X) || SearchT(Right(P),X));       
        }
    }
} 

boolean SearchDaun(BinTree P, TRElType X){
    if (IsTreeOneElmt(P)){
        return (Akar(P) == X);
    }
    else{
        if (SearchT(Left(P),X)){
            return SearchDaun(Left(P),X);
        }
        else{
            return SearchDaun(Right(P),X);
        }
    }
}

int LevelT(BinTree P, TRElType X){
    /* { Mengirimkan level dari node X yang merupakan salah satu daun
    dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak
    kosong dan elemen-elemennya unik. }
    */
    if (Akar(P) == X){
        return 1;
    }
    else{
        if (SearchDaun(Left(P),X)){
            return 1 + LevelT(Left(P),X);
        }
        else{
            return 1 + LevelT(Right(P),X);
        }
    }
}

void AddDaun(BinTree *P, TRElType X, TRElType Y, boolean Kiri) {
    /* { I.S. P tidak kosong, X adalah daun Pohon Biner P }
    { F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika
    Kiri), atau sebagai anak Kanan X (jika not Kiri). Jika ada lebih
    dari satu daun bernilai X, Y ditambahkan pada daun paling kiri. }
    */
    if (Akar(*P) == X) {
        if (Kiri) {
            Left(*P) = AlokasiT(Y);
        }
        else {
            Right(*P) = AlokasiT(Y);
        }
    }
    else {
        if (SearchDaun(Left(*P), X) && Kiri) {
            AddDaun(&(Left(*P)), X, Y, Kiri);
        }
        else {
            AddDaun(&(Right(*P)), X, Y, Kiri);
        }
    }
}

void DelDaun(BinTree *P, TRElType X){
    /* { I.S. P tidak kosong, minimum 1 daun bernilai X }
    { F.S. Semua daun yang bernilai X dihapus dari P }
    */
    if (IsTreeOneElmt(*P) && (Akar(*P) == X)){
        taddress PTemp = *P;
        *P = Nil;
        DealokasiT(PTemp);
    }
    else{
        if (IsUnerLeftT(*P)){
            DelDaun(&Left(*P),X);
        }
        else if (IsUnerRightT(*P)){
            DelDaun(&Right(*P),X);
        }
        else if (IsBinerT(*P)){
            DelDaun(&Left(*P),X);
            DelDaun(&Right(*P),X);
        }
    }
}

void printUpTree(BinTree P, int h) {
    if (!IsTreeEmpty(P) ){
      printf("%d\n", Akar(P) );
      if (Left(P) != Nil) for (int i = 0; i < h; i++) printf(" ");
      printUpTree(Left(P), h*2);
      if (Right(P) != Nil) for (int i = 0; i < h; i++) printf(" ");
      printUpTree(Right(P), h*2);
  }
}

boolean isTreeEqual(BinTree P1, BinTree P2) {
    if (IsTreeEmpty(P1) && IsTreeEmpty(P2)) return true;
    if (Akar(P1) != Akar(P2)) return false;
    if (IsUnerLeftT(P1) && IsUnerLeftT(P2)) return isTreeEqual(Left(P1), Left(P2));
    else if (IsUnerRightT(P1) && IsUnerRightT(P2)) return isTreeEqual(Right(P1), Right(P2));
    else if (IsBinerT(P1) && IsBinerT(P2)) return isTreeEqual(Left(P1), Left(P2)) && isTreeEqual(Right(P1), Right(P2));
    else return false;
}