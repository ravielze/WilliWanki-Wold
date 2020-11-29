#include "mesinkata.h"

int main(){

    STARTKATA();
    while (!EndKata){
        ADVKATA();
    }

    printf("Kata: %s", CKata.TabKata);
    printf("\nKata tersebut %s dengan 'Alstrokedead'.\n", (IsKataSama(CKata, CreateKata("Alstrokedead")) ? "sama" : "tidak sama"));

}