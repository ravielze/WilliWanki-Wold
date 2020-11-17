#ifndef ARRAY_H
#define ARRAY_H

#include "../boolean.h"

typedef struct
{
    int *T;
    int NEff;
    int MaxEl;
} TabItem;

void MakeList(TabItem *T, int maxel);
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
void Dealokasi(TabItem *T);
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

/* *** SELEKTOR LAIN *** */

int NbElmt(TabItem T);
/* Mengirimkan banyaknya elemen efektif tabel */

int MaxElement(TabItem T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

#endif