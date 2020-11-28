#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

BinTree Tree(infotype Akar, BinTree L, BinTree R){
    BinTree P = (address)malloc(sizeof(Node));
    Akar(P) = Akar;
    Left(P) = L;
    Right(P) = P;

    return P;
}

address AlokasiT(infotype X){
    address P = (address)malloc(sizeof(Node));
    Akar(P) = X;
}

void DealokasiT(address * P) {
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

boolean SearchT(BinTree P, infotype X){
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

boolean SearchDaun(BinTree P, infotype X){
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

int LevelT(BinTree P, infotype X){
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

void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri) {
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

void DelDaun(BinTree *P, infotype X){
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