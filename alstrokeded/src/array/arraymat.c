#include "arraymat.h"

void CreateEmptyMAT(ARRAYLISTMAT * arr, int maxel) {
    minfotype * TI = (minfotype*)malloc(maxel*sizeof(minfotype));
    TI(*arr) = TI;
    NEff(*arr) = 0;
    MaxEl(*arr) = maxel;
}

void DealokasiMAT(ARRAYLISTMAT * arr) {
    free(TI(*arr));
    NEff(*arr) = -1;
    MaxEl(*arr) = -1;
}

boolean IsMATFull(ARRAYLISTMAT arr) {
    return NEff(arr) == MaxEl(arr);
}

boolean IsMATEmpty(ARRAYLISTMAT arr) {
    return NEff(arr) == 0;
}

void InsertFirstMAT(ARRAYLISTMAT *arr, minfotype X) {
    if (IsMATFull(*arr)){
        MaxEl(*arr) += 10;
        minfotype * temp = (minfotype*)realloc(TI(*arr), (MaxEl(*arr)*sizeof(minfotype)));
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

void InsertLastMAT(ARRAYLISTMAT * arr, minfotype X) {
    if (IsMATFull(*arr)) {
        MaxEl(*arr) += 10;
        minfotype* temp = (minfotype *) realloc (TI(*arr), (MaxEl(*arr) * sizeof(minfotype)));
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

minfotype DeleteFirstMAT(ARRAYLISTMAT *arr) {
    // Mengambil elemen pertama array
    minfotype temp = ItemOf(*arr, 0);
    // Geser semuanya ke kiri
    for (int i = 0; i < NEff(*arr); i++) {
        ItemOf(*arr, i) = ItemOf(*arr, i+1);
    }
    // Mengurangi NEff
    NEff(*arr) -= 1;
    return temp;
}

minfotype DeleteLastMAT(ARRAYLISTMAT *arr) {
    minfotype temp = ItemOf(*arr, NEff(*arr)-1);
    NEff(*arr) -= 1;
    return temp;
}

void InsertNMAT(ARRAYLISTMAT *arr, int idx, minfotype X) {
    if (IsMATFull(*arr)){
        MaxEl(*arr) += 10;
        minfotype * temp = (minfotype*)realloc(TI(*arr), (MaxEl(*arr)*sizeof(minfotype)));
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

void DeleteNMAT(ARRAYLISTMAT *arr, int idx) {
    if (NEff(*arr) <= (MaxEl(*arr) / 4)) {
        MaxEl(*arr) /= 2;
        minfotype* temp = (minfotype *) realloc (TI(*arr), (MaxEl(*arr) * sizeof(minfotype)));
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

int SearchIdxMAT(ARRAYLISTMAT arr, minfotype X) {
// Ini nyari X ada ga di Search, kalau ada, return idx, kalau ga ada, return apa kek
    for (int i = 0; i < NEff(arr); i++) {
        if (isMaterialEqual(ItemOf(arr,i) , X)) {
            return i;
        }
    }
    return -1; // IdxUndef
}

boolean SearchMAT(ARRAYLISTMAT arr, minfotype X){
    for (int i = 0; i < NEff(arr); i++) {
        if (isMaterialEqual(ItemOf(arr,i) , X)) {
            return true;
        }
    }
    return false; 
}