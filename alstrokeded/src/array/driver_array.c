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
    printf("CREATE EMPTY\n");
    ARRAYLIST LOL;
    CreateEmptyAL(&LOL,20);
    if(NEff(LOL) == 0) printf("THERE IS NO NEFF\n");
    if(MaxEl(LOL) == 20) printf("MAXEL IS 20\n");
    printf("\n");


    /* IS FULL OR IS EMPTY */
    printf("IS FULL OR IS EMPTY\n");
    if (IsALFull(LOL)) printf("Array penuh\n");
    if (IsALEmpty(LOL)) printf("Array kosong\n");

    /* INSERT ARRAY */
    InsertFirstAL(&LOL, 29);
    InsertLastAL(&LOL, 55);

    /* DELETE ARRAY */
    printf("DELETE ARRAY\n");
    ainfotype first = DeleteFirstAL(&LOL);
    printf("Delete first element: %d\n", first); 
    ainfotype last = DeleteLastAL(&LOL);
    printf("Delete last element: %d\n", last);

    /* SEARCHING */
    ARRAYLIST LUL;
    CreateEmptyAL(&LUL, 20);

    InsertFirstAL(&LUL, 2);
    InsertFirstAL(&LUL, 4);
    InsertFirstAL(&LUL, 6);
    InsertFirstAL(&LUL, 10);
    InsertFirstAL(&LUL, 16); //idx 1
    InsertFirstAL(&LUL, 26); //idx 0
    if (SearchNAL(LUL, 2) == 2) printf("%d berada di dalam list.\n", 2);
    if (SearchAL(LUL, 4)) printf("%d berada di dalam list.\n", 4);
    int wehr = SearchIdxAL(LUL, 16);
    printf("%d berada di index ke-%d.\n", 1, wehr);
    return 0;
}

/* DONEEEEEEEE */