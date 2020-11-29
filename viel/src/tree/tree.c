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
}

void DealokasiT(taddress * P) {
    free(*P);
}

boolean IsTreeEmpty(BinTree P){
    return Akar(P) == Nil;
}

boolean IsOneElmtT(BinTree P){
    if (IsTreeEmpty(P)){
        return false;
    }
    return (Left(P)==Nil && Right(P)==Nil);
}

boolean IsUnerLeftT(BinTree P){
    return (Left(P)!=Nil && Right(P)==Nil);
}
boolean IsUnerRightT(BinTree P){
    return (Left(P)==Nil && Right(P)!=Nil);
}
boolean isBinerT(BinTree P) {
    return Left(P) != Nil && Right(P) != Nil;
}

int NbElmtT(BinTree P){
    if (IsOneElmtT(P)){
        return 1;
    }
    else{
        if (IsUnerLeft(P)) return NbElmtT(Left(P)) + 1;
        else if(IsUnerRight(P)) return NbElmtT(Right(P)) + 1;
        else return NbElmtT(Left(P)) + 1 + NbElmt(Right(P));
    }
}

int NbDaun(BinTree P){
    if (IsOneElmtT(P)){
        return 1;
    } else {
        if (IsUnerLeftT(P)) return(NbDaun(Left(P)));
        else if (IsUnerRightT(P)) return(NbDaun(Right(P)));
        return (NbDaun(Left(P)) + NbDaun(Right(P)));
    }
}

int TinggiT(BinTree P){
/* Pohon Biner mungkin kosong.
Mengirim “height”, yaitu tinggi dari pohon  */
    if (IsTreeEmpty(P)){
        return 0;
    } else {
        return (1 + max(TinggiT(Left(P)),TinggiT(Right(P))));
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
            return (Search(Left(P), X) || Search(Right(P),X));       
        }
    }
} 

boolean SearchDaun(BinTree P, TRElType X){
    if (IsOneElmtT(P)){
        return (Akar(P) == X);
    }
    else{
        if (Search(Left(P),X)){
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
            return 1 + Level(Left(P),X);
        }
        else{
            return 1 + Level(Right(P),X);
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
            Left(*P) = Y;
        }
        else {
            Right(*P) = Y;
        }
    }
    else {
        if (SearchDaun(Left(*P), X) && Kiri) {
            AddDaun(Left(*P), X, Y, Kiri);
        }
        else {
            AddDaun(Right(*P), X, Y, Kiri);
        }
    }
}

void DelDaun(BinTree *P, TRElType X){
/* { I.S. P tidak kosong, minimum 1 daun bernilai X }
{ F.S. Semua daun yang bernilai X dihapus dari P }
 */
    if (IsOneElmtT(*P) && Akar(*P) == X) *P = Nil;
    else{
        if (IsOneElmtT(Left(*P))){
            if (Akar(*P) == X){
                BinTree temp, Del;
                Del = Left(*P);
                Dealokasi(&Del);
                temp = Left(*P);
            
            }
        }
        
    }
}

void printUpTree(BinTree P) {
    //TODO realisasi
}

boolean isTreeEqual(BinTree P1, BinTree P2) {
    if (IsTreeEmpty(P1) && IsTreeEmpty(P2)) return true;
    if (Akar(P1) != Akar(P2)) return false;
    if (IsUnerLeft(P1) && IsUnerLeft(P2)) return isTreeEqual(Left(P1), Left(P2));
    else if (IsUnerRight(P1) && IsUnerRight(P2)) return isTreeEqual(Right(P1), Right(P2));
    else if (IsBiner(P1) && IsBiner(P2)) return isTreeEqual(Left(P1), Left(P2)) && isTreeEqual(Right(P1), Right(P2));
    else return false;
}