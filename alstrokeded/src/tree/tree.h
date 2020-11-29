#ifndef TREE_H
#define TREE_H

#include "../constant/adt.h"
/* Definisi PohonBiner */
/* Pohon Biner kosong P = Nil */

BinTree Tree(TRElType Akar, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi
berhasil*/

BinTree AlokasiT(TRElType X);
/* { Mengirimkan address hasil alokasi sebuah elemen X }
{ Jika alokasi berhasil, maka address tidak nil, dan misalnya
menghasilkan P, maka Info(P)=X, Left(P)=Nil, Right(P)=Nil 
{ Jika alokasi gagal, mengirimkan Nil } */

void DealokasiT(taddress P);
/* I.S. P terdefinisi 
* F.S. P dikembalikan ke sistem 
* Melakukan dealokasi/pengembalian address P */

boolean IsTreeEmpty(BinTree P);
/* Mengirimkan true jika P adalah pohon biner yang kosong */
boolean IsTreeOneElmt(BinTree P);
/*  Mengirimkan true jika P tidak kosong dan hanya terdiri atas 1 elemen  */
boolean IsUnerLeftT(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong, P adalah pohon unerleft:
hanya mempunyai subpohon kiri */
boolean IsUnerRightT(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong, P adalah pohon unerright:
hanya mempunyai subpohon kanan */
boolean isBinerT(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong, P adalah pohon biner:
mempunyai subpohon kiri dan subpohon kanan */

int NbElmtT(BinTree P);
/* Pohon Biner mungkin kosong. Mengirim jumlah elemen dari pohon */
int NbDaun(BinTree P);
/*  Prekondisi: Pohon Biner tidak mungkin kosong.
Mengirimkan banyaknya daun pohon */
int TinggiT(BinTree P);
/* Pohon Biner mungkin kosong.
Mengirim “height”, yaitu tinggi dari pohon  */

/* Print pohon */
void PrintTree(BinTree P, int h);

/* tree P1 = tree P2 ga ya hm*/
void BetterPrintTree(BinTree P, int h, int lv);
boolean isTreeEqual(BinTree P1, BinTree P2);
#endif