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

void DealokasiT(taddress * P);
/* I.S. P terdefinisi 
* F.S. P dikembalikan ke sistem 
* Melakukan dealokasi/pengembalian address P */

boolean IsTreeEmpty(BinTree P);
/* Mengirimkan true jika P adalah pohon biner yang kosong */
boolean IsOneElmtT(BinTree P);
/*  Mengirimkan true jika P tidak kosong dan hanya terdiri atas 1 elemen  */
boolean IsUnerLeft(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong, P adalah pohon unerleft:
hanya mempunyai subpohon kiri */
boolean IsUnerRight(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong, P adalah pohon unerright:
hanya mempunyai subpohon kanan */
boolean isBiner(BinTree P);
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
boolean SearchT(BinTree P, TRElType X);
boolean SearchDaun(BinTree P, TRElType X);

int LevelT(BinTree P, TRElType X);
/* { Mengirimkan level dari node X yang merupakan salah satu daun
dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak
kosong dan elemen-elemennya unik. }
*/

void AddDaun(BinTree *P, TRElType X, TRElType Y, boolean Kiri);
/* I.S. P tidak kosong, X adalah daun Pohon Biner P 
F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika
Kiri), atau sebagai anak Kanan X (jika not Kiri). Jika ada lebih
dari satu daun bernilai X, Y ditambahkan pada daun paling kiri. */

void DelDaun(BinTree *P, TRElType X);
/* I.S. P tidak kosong, minimum 1 daun bernilai X 
F.S. Semua daun yang bernilai X dihapus dari P */

/* tree P1 = tree P2 ga ya hm*/
boolean isTreeEqual(BinTree P1, BinTree P2);
#endif