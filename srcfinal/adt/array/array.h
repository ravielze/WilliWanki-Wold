#ifndef ARRAY_H
#define ARRAY_H

#define infotype int
#define Nil NULL
#include "../boolean.h"

typedef struct {
    infotype *TI;
    int Neff;
    int MaxEl;
} ARRAYLIST;

#define TI(T) (T).TI
#define ItemOf(T, i) (T).TI[(i)]
#define Neff(T) (T).Neff
#define MaxEl(T) (T).MaxEl

void CreateEmptyAL(ARRAYLIST * arr, int maxel);
void DealokasiAL(ARRAYLIST * arr);
boolean IsALFull(ARRAYLIST arr);
boolean IsALEmpty(ARRAYLIST arr);
void InsertFirstAL(ARRAYLIST *arr, int X);
void InsertLastAL(ARRAYLIST * arr, int X);
infotype DeleteFirstAL(ARRAYLIST *arr);
infotype DeleteLastAL(ARRAYLIST *arr);
void InsertNAL(ARRAYLIST *arr, int idx, int X);
infotype DeleteNAL(ARRAYLIST *arr, int idx);

infotype SearchN(ARRAYLIST arr, int X);
// Ini nyari X ada ga di Search, kalau ada, return infotype, kalau ga ada, return apa kek
boolean Search(ARRAYLIST arr, int X);
// Ini nyari apakah X ada di ArrayList
int SearchIdx(ARRAYLIST arr, int X);

#endif