#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>

boolean EndKata;
Kata CKata;

void IgnoreBlank(){
    while (CC == BLANK){
        ADV();
    }
}

void STARTKATA(){
    START();
    IgnoreBlank();
    if (CC == MARK){
        EndKata = true;
    } else {
        EndKata = false;
        ADVKATA();
    }
}

void ADVKATA(){
    IgnoreBlank();
    if (CC == MARK && !EndKata){
        EndKata = true;
    } else{
        SalinKata();
        IgnoreBlank();
    }
}

void SalinKata(){
    int i = 0;
    CKata.NMax = 10;
    CKata.TabKata = (char*) malloc(CKata.NMax * sizeof(char));
    while ((CC != MARK) && (CC != BLANK)) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
        if (i > CKata.NMax ){
            CKata.NMax += 10;
            char *temp = (char*) realloc(CKata.TabKata, (CKata.NMax * sizeof(char)));
            if (temp == NULL){
                CKata.NMax -= 10;
                printf("Error reallocating memory.");
                break;
            } else {
                CKata.TabKata = temp;
            }
        }
    }
    CKata.Length = i;
    CKata.TabKata[i] = '\0';
}

Kata CreateKata(char* kata){
    Kata result;
    result.TabKata = kata;
    int i;
    for (i = 0; kata[i] != '\0'; ++i);
    result.NMax = i;
    result.Length = i;
    return result;
}

boolean IsKataSama(Kata K1, Kata K2){
    boolean result = (K1.Length == K2.Length);
    if (result){
        int i;
        for (i=0; i < K1.Length; i++){
            result = (result && (K1.TabKata[i] == K2.TabKata[i]));
        }
    }
    return result;
}