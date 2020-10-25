#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>

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
    while ((CC != MARK) && (CC != BLANK) && i != NMax) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = (i < NMax) ? i : NMax;
}