#ifndef ARRAY_MAT_H
#define ARRAY_MAT_H
#include "../constant/adt.h"
#include "../material/material.h"

void CreateEmptyMAT(ARRAYLISTMAT * arr, int maxel);
void DealokasiMAT(ARRAYLISTMAT * arr);
boolean IsMATFull(ARRAYLISTMAT arr);
boolean IsMATEmpty(ARRAYLISTMAT arr);
void InsertFirstMAT(ARRAYLISTMAT *arr, minfotype X);
void InsertLastMAT(ARRAYLISTMAT * arr, minfotype X);
minfotype DeleteFirstMAT(ARRAYLISTMAT *arr);
minfotype DeleteLastMAT(ARRAYLISTMAT *arr);
void InsertNMAT(ARRAYLISTMAT *arr, int idx, minfotype X);
void DeleteNMAT(ARRAYLISTMAT *arr, int idx);

// Ini nyari X ada ga di Search, kalau ada, return minfotype, kalau ga ada, return -999
boolean SearchMAT(ARRAYLISTMAT arr, minfotype X);
// Ini nyari apakah X ada di ArrayList
int SearchIdxMAT(ARRAYLISTMAT arr, minfotype X);
// Ini nyari X ada ga di Search, kalau ada, return idx, kalau ga ada, return -1

#endif