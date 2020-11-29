#include <stdio.h>
#include "array.h"


// typedef struct {
//     ainfotype *TI;
//     int NEff;
//     int MaxEl;
// } ARRAYLIST;


// #define TI(T) (T).TI
// #define ItemOf(T, i) (T).TI[(i)]
// #define NEff(T) (T).NEff
// #define MaxEl(T) (T).MaxEl

int main() {
    /* CREATE EMPTY */
    prinft("CREATE EMPTY\n");
    ARRAYLIST LOL;
    CreateEmptyAL(&LOL,20);
    if(MaxEl(T) == 20)
    prinft("\n");


    /* IS FULL OR IS EMPTY */
    printf("IS FULL OR IS EMPTY\n");
    if (IsALFull(LOL)) printf("Array penuh\n");
    if (IsALEmpty(L)) printf("Array kosong\n");

    /* INSERT ARRAY */
    printf("INSERT ARRAY\n");
    InsertFirstAL(&L)

    return 0;
}

void CreateEmptyAL(ARRAYLIST * arr, int maxel);
void DealokasiAL(ARRAYLIST * arr);
boolean IsALFull(ARRAYLIST arr);
boolean IsALEmpty(ARRAYLIST arr);
void InsertFirstAL(ARRAYLIST *arr, int X);
void InsertLastAL(ARRAYLIST * arr, int X);
ainfotype DeleteFirstAL(ARRAYLIST *arr);
ainfotype DeleteLastAL(ARRAYLIST *arr);
void InsertNAL(ARRAYLIST *arr, int idx, int X);
void DeleteNAL(ARRAYLIST *arr, int idx);

ainfotype SearchNAL(ARRAYLIST arr, int X);
// Ini nyari X ada ga di Search, kalau ada, return infotype, kalau ga ada, return -999
boolean SearchAL(ARRAYLIST arr, int X);
// Ini nyari apakah X ada di ArrayList
int SearchIdxAL(ARRAYLIST arr, int X);