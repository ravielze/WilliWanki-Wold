#include "tree.h"

BinTree Tree(TRElType Akar, BinTree L, BinTree R){
    BinTree result = AlokasiT(Akar);
    if (result != Nil){
        Left(result) = L;
        Right(result) = R;
    }
    return result;
}

taddress AlokasiT(TRElType X){
    taddress result;
    result = (taddress) malloc (sizeof(BinTree));
    if (result != Nil){
        Akar(result) = X;
        Left(result) = Nil;
        Right(result) = Nil;
    }
    return result;
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

void BetterPrintTree(BinTree P, int h, int lv){
    if(!IsTreeEmpty(P)){
        int i;
        for(i = 0; i < h*lv; i++){
            printf(" ");
        }
        printf("%d\n", Akar(P));
        BetterPrintTree(Left(P), h, lv+1);
        BetterPrintTree(Right(P), h, lv+1);
    }
}

void PrintTree(BinTree P, int h){
    if (!IsTreeEmpty(P) ){
        printf("%d\n", Akar(P) );
        if (Left(P) != Nil) for (int i = 0; i < h; i++) printf(" ");
        PrintTree(Left(P), h*2);
        if (Right(P) != Nil) for (int i = 0; i < h; i++) printf(" ");
        PrintTree(Right(P), h*2);
    }
}

// boolean isTreeEqual(BinTree P1, BinTree P2) {
//     // if (IsTreeEmpty(P1) && IsTreeEmpty(P2)) return true;
//     // if (Akar(P1) != Akar(P2)) return false;
//     // if (IsUnerLeftT(P1) && IsUnerLeftT(P2)) return isTreeEqual(Left(P1), Left(P2));
//     // else if (IsUnerRightT(P1) && IsUnerRightT(P2)) return isTreeEqual(Right(P1), Right(P2));
//     // else if (IsBinerT(P1) && IsBinerT(P2)) return (isTreeEqual(Left(P1), Left(P2) ) && isTreeEqual(Right(P1), Right(P2) ) );
//     // else return false;
//     // return true;
// }