#ifndef ARRAY_MAT_H
#define ARRAY_MAT_H
#include "../material/material.h"

#define infotype MATERIAL
#define Nil NULL
#include "../boolean.h"

typedef struct {
    infotype *TI;
    int Neff;
    int MaxEl;
} ARRAYLISTMAT; 

#define TI(T) (T).TI
#define ItemOf(T, i) (T).TI[(i)]
#define Neff(T) (T).Neff
#define MaxEl(T) (T).MaxEl

void CreateEmptyMAT(ARRAYLISTMAT * arr, int maxel);
void DealokasiMAT(ARRAYLISTMAT * arr);
boolean IsMATFull(ARRAYLISTMAT arr);
boolean IsMATEmpty(ARRAYLISTMAT arr);
void InsertFirstMAT(ARRAYLISTMAT *arr, infotype X);
void InsertLastMAT(ARRAYLISTMAT * arr, infotype X);
infotype DeleteFirstMAT(ARRAYLISTMAT *arr);
infotype DeleteLastMAT(ARRAYLISTMAT *arr);
void InsertNMAT(ARRAYLISTMAT *arr, int idx, infotype X);
infotype DeleteNMAT(ARRAYLISTMAT *arr, int idx);

infotype SearchNMAT(ARRAYLISTMAT arr, infotype X);
// Ini nyari X ada ga di Search, kalau ada, return infotype, kalau ga ada, return -999
boolean SearchMAT(ARRAYLISTMAT arr, infotype X);
// Ini nyari apakah X ada di ArrayList
int SearchIdxMAT(ARRAYLISTMAT arr, infotype X);
// Ini nyari X ada ga di Search, kalau ada, return idx, kalau ga ada, return -1

#endif