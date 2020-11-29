#ifndef POINT_H
#define POINT_H

#include "../constant/adt.h"

/* *** Konstruktor membentuk POINT *** */
/* Membentuk sebuah POINT dari komponen-komponennya */
void MakePoint (POINT * P, int X, int Y);

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */

/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
void TulisPoint (POINT P);

/* *** Kelompok operasi relasional terhadap POINT *** */
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean PEQ (POINT P1, POINT P2);
/* Mengirimkan true jika P1 tidak sama dengan P2 */
boolean PNEQ (POINT P1, POINT P2);

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
/* Mengirim salinan P dengan absis ditambah satu */
POINT PNextX (POINT P);
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT PNextY (POINT P);
#endif