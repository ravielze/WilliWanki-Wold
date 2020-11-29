#include "array.h"

void CreateEmptyAL(ARRAYLIST * arr, int maxel) {
    ainfotype * TI = (ainfotype*)malloc(maxel*sizeof(ainfotype));
    TI(*arr) = TI;
    NEff(*arr) = 0;
    MaxEl(*arr) = maxel;
}

void DealokasiAL(ARRAYLIST * arr) {
    free(TI(*arr));
    NEff(*arr) = -1;
    MaxEl(*arr) = -1;
}

boolean IsALFull(ARRAYLIST arr) {
    return NEff(arr) == MaxEl(arr);
}

boolean IsALEmpty(ARRAYLIST arr) {
    return NEff(arr) == 0;
}

void InsertFirstAL(ARRAYLIST *arr, int X) {
    if (IsAlFull(*arr)){
        MaxEl(*arr) += 10;
        ainfotype * temp = (ainfotype*)realloc(TI(*arr), (MaxEl(*arr)*sizeof(ainfotype)));
        if (temp == Nil) {
            printf("Error reallocating memory.");
            TI(*arr) = Nil;
            return;
        }
        else {
            TI(*arr) = temp;
        }
    }
    
    for (int i=NEff(*arr); i>0; i--){
        ItemOf(*arr,i) = ItemOf(*arr,i-1);
    }

    ItemOf(*arr, 0) = X;
    NEff(*arr)++;

}

void InsertLastAL(ARRAYLIST * arr, int X) {
    if (IsAlFull(*arr)) {
        MaxEl(*arr) += 10;
        ainfotype* temp = (ainfotype *) realloc (TI(*arr), (MaxEl(*arr) * sizeof(ainfotype)));
        if (temp == Nil) {
            printf("Error reallocating memory.");
            TI(*arr) = Nil;
            return;
        }
        else {
            TI(*arr) = temp;
        }
    }
    ItemOf(*arr, NEff(*arr)) = X;
    NEff(*arr)++;
}

ainfotype DeleteFirstAL(ARRAYLIST *arr) {
    // Mengambil elemen pertama array
    int temp = ItemOf(*arr, 0);
    // Geser semuanya ke kiri
    for (int i = 0; i < NEff(*arr); i++) {
        ItemOf(*arr, i) = ItemOf(*arr, i+1);
    }
    // Mengurangi NEff
    NEff(*arr) -= 1;
    return temp;
}

ainfotype DeleteLastAL(ARRAYLIST *arr) {
    int temp = ItemOf(*arr, NEff(*arr)-1);
    NEff(*arr) -= 1;
    return temp;
}

void InsertNAL(ARRAYLIST *arr, int idx, int X) {
    if (IsAlFull(*arr)){
        MaxEl(*arr) += 10;
        ainfotype * temp = (ainfotype*)realloc(TI(*arr), (MaxEl(*arr)*sizeof(ainfotype)));
        if (temp == Nil) {
            printf("Error reallocating memory.");
            TI(*arr) = Nil;
            return;
        }
        else {
            TI(*arr) = temp;
        }
    }
    
    for (int i=NEff(*arr); i>idx; i--){
        ItemOf(*arr,i) = ItemOf(*arr,i-1);
    }

    ItemOf(*arr, idx) = X;
    NEff(*arr)++;
}

ainfotype DeleteNAL(ARRAYLIST *arr, int idx) {
    if (NEff(*arr) <= (MaxEl(*arr) / 4)) {
        MaxEl(*arr) /= 2;
        ainfotype* temp = (ainfotype *) realloc (TI(*arr), (MaxEl(*arr) * sizeof(ainfotype)));
        if (temp == Nil) {
            printf("Error reallocating memory");
            TI(*arr) = Nil;
            return;
        }
        else {
            TI(*arr) = temp;
        }        
    }
    NEff(*arr)--;
    for (int i = idx; i < NEff(*arr); i++) {
        ItemOf(*arr, i) = ItemOf(*arr, i+1);
    }
}

ainfotype SearchNAL(ARRAYLIST arr, int X) {
// Ini nyari X ada ga di Search, kalau ada, return ainfotype, kalau ga ada, return apa kek wait, ini kan return ainfotype X yang jadi parameter fungsi(?)
// Pake yg return indeks aja(?)
    for (int i = 0; i < NEff(arr); i++) {
        if (ItemOf(arr, i) == X) {
            return X;
        }
    }
    return -999;
}

int SearchIdxAL(ARRAYLIST arr, int X) {
// Ini nyari X ada ga di Search, kalau ada, return idx, kalau ga ada, return apa kek
    for (int i = 0; i < NEff(arr); i++) {
        if (ItemOf(arr, i) == X) {
            return i;
        }
    }
    return -1; // IdxUndef
}

boolean SearchAL(ARRAYLIST arr, int X){
    for (int i = 0; i < NEff(arr); i++) {
        if (ItemOf(arr, i) == X) {
            return true;
        }
    return false; 
}