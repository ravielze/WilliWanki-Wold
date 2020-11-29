#ifndef ARRAY_H
#define ARRAY_H
#include "../constant/adt.h"

void CreateEmptyAL(ARRAYLIST * arr, int maxel);
void DealokasiAL(ARRAYLIST * arr);
boolean IsALFull(ARRAYLIST arr);
boolean IsALEmpty(ARRAYLIST arr);
void InsertFirstAL(ARRAYLIST *arr, int X);
void InsertLastAL(ARRAYLIST * arr, int X);
ainfotype DeleteFirstAL(ARRAYLIST *arr);
ainfotype DeleteLastAL(ARRAYLIST *arr);
void InsertNAL(ARRAYLIST *arr, int idx, int X);
ainfotype DeleteNAL(ARRAYLIST *arr, int idx);

ainfotype SearchNAL(ARRAYLIST arr, int X);
// Ini nyari X ada ga di Search, kalau ada, return infotype, kalau ga ada, return -999
boolean SearchAL(ARRAYLIST arr, int X);
// Ini nyari apakah X ada di ArrayList
int SearchIdxAL(ARRAYLIST arr, int X);
// Ini nyari X ada ga di Search, kalau ada, return idx, kalau ga ada, return -1

#endif