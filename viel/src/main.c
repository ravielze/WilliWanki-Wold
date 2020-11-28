#include "boolean.h"
#include "./wahana/wahana.h"
#include <stdio.h>

int main(){
    WAHANA test = createWahana("aCIn_coaster rollercoaster ga_asik_bosen 1 3 10.2 0 1 1 3 5");
    //printf("%s %s %d %d", NamaWhn(test), TipeWhn(test), Ordinat(LokWhn(test)), Hour(DurasiWhn(test)));
    char* result;
    WahanatoString(test, result);
    return 0;
}