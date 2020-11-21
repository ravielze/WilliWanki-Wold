#include <stdio.h>
#include <stdlib.h>
#include "../../src/adt/boolean.h"
#include "array.h"

void CreateEmptyAL(ARRAYLIST * arr, int maxel) {
    infotype * TI = (infotype*)malloc(maxel*sizeof(infotype));
    TI(*arr) = TI;
    Neff(*arr) = 0;
    MaxEl(*arr) = maxel;
}

void DealokasiAL(ARRAYLIST * arr) {
    free(TI(*arr));
    Neff(*arr) = -1;
    MaxEl(*arr) = -1;
}

boolean IsALFull(ARRAYLIST arr) {
    return Neff(arr) == MaxEl(arr);
}

boolean IsAlEmpty(ARRAYLIST arr) {
    return Neff(arr) == 0;
}

void InsertFirstAL(ARRAYLIST *arr, int X) {
    if (IsAlFull(*arr)){
        MaxEl(*arr) += 10;
        infotype * temp = (infotype*)realloc(TI(*arr), (MaxEl(*arr)*sizeof(infotype)));
        if (temp == Nil) {
            printf("Error reallocating memory.");
            TI(*arr) = Nil;
            return;
        }
        else {
            TI(*arr) = temp;
        }
    }
    
    for (int i=Neff(*arr); i>0; i--){
        ItemOf(*arr,i) = ItemOf(*arr,i-1);
    }

    ItemOf(*arr, 0) = X;
    Neff(*arr)++;

}

void InsertLastAL(ARRAYLIST * arr, int X) {
    if (IsAlFull(*arr)) {
        MaxEl(*arr) += 10;
        infotype* temp = (infotype *) realloc (TI(*arr), (MaxEl(*arr) * sizeof(infotype)));
        if (temp == Nil) {
            printf("Error reallocating memory.");
            TI(*arr) = Nil;
            return;
        }
        else {
            TI(*arr) = temp;
        }
    }
    ItemOf(*arr, Neff(*arr)) = X;
    Neff(*arr)++;
}

infotype DeleteFirstAL(ARRAYLIST *arr) {
    // Mengambil elemen pertama array
    int temp = ItemOf(*arr, 0);
    // Geser semuanya ke kiri
    for (int i = 0; i < Neff(*arr); i++) {
        ItemOf(*arr, i) = ItemOf(*arr, i+1);
    }
    // Mengurangi NEff
    Neff(*arr) -= 1;
    return temp;
}

infotype DeleteLastAL(ARRAYLIST *arr) {
    int temp = ItemOf(*arr, Neff(*arr)-1);
    Neff(*arr) -= 1;
    return temp;
}

void InsertNAL(ARRAYLIST *arr, int idx, int X) {
    if (IsAlFull(*arr)){
        MaxEl(*arr) += 10;
        infotype * temp = (infotype*)realloc(TI(*arr), (MaxEl(*arr)*sizeof(infotype)));
        if (temp == Nil) {
            printf("Error reallocating memory.");
            TI(*arr) = Nil;
            return;
        }
        else {
            TI(*arr) = temp;
        }
    }
    
    for (int i=Neff(*arr); i>idx; i--){
        ItemOf(*arr,i) = ItemOf(*arr,i-1);
    }

    ItemOf(*arr, idx) = X;
    Neff(*arr)++;
}

infotype DeleteNAL(ARRAYLIST *arr, int idx) {
    if (Neff(*arr) <= (MaxEl(*arr) / 4)) {
        MaxEl(*arr) /= 2;
        infotype* temp = (infotype *) realloc (TI(*arr), (MaxEl(*arr) * sizeof(infotype)));
        if (temp == Nil) {
            printf("Error reallocating memory");
            TI(*arr) = Nil;
            return;
        }
        else {
            TI(*arr) = temp;
        }        
    }
    Neff(*arr)--;
    for (int i = idx; i < Neff(*arr); i++) {
        ItemOf(*arr, i) = ItemOf(*arr, i+1);
    }
}

infotype SearchN(ARRAYLIST arr, int X) {
// Ini nyari X ada ga di Search, kalau ada, return infotype, kalau ga ada, return apa kek wait, ini kan return infotype X yang jadi parameter fungsi(?)
// Pake yg return indeks aja(?)
    for (int i = 0; i < Neff(arr); i++) {
        if (ItemOf(arr, i) == X) {
            return X;
        }
    }
    return -999;
}

int SearchIdx(ARRAYLIST arr, int X) {
// Ini nyari X ada ga di Search, kalau ada, return idx, kalau ga ada, return apa kek
    for (int i = 0; i < Neff(arr); i++) {
        if (ItemOf(arr, i) == X) {
            return i;
        }
    }
    return -1; // IdxUndef
}

boolean Search(ARRAYLIST arr, int X){
    for (int i = 0; i < Neff(arr); i++) {
        if (ItemOf(arr, i) == X) {
            return true;
        }
    return false; 
}