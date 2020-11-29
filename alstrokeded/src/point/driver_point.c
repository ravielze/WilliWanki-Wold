#include <stdio.h>
#include "point.h"


int main(){
    /* MAKE POINT */
    printf("MAKE POINT\n");
    POINT peg1, peg2, peg3, peg4;
    MakePoint(&peg1, 1, 1); TulisPoint(peg1); printf("\n");
    MakePoint(&peg2, 1, 1); TulisPoint(peg2); printf("\n");
    if (PEQ(peg1,peg2)) printf("peg1 and peg2 LOCATED ON THE SAME POINT\n");
    MakePoint(&peg3, 99, -49); TulisPoint(peg3); printf("\n");
    MakePoint(&peg4, -789, 21); TulisPoint(peg4); printf("\n");
    if (PNEQ(peg3,peg4)) printf("peg3 and peg4 LOCATED ON DIFFRENT POINT\n");
    
    /* GESER POINT */
    printf("GESER POINT\n");
    POINT new_p_1 = PNextX(peg1);
    POINT new_p_2 = PNextY(peg2);
    printf("Bergeser secara sumbu x\n");
    TulisPoint(peg1); printf(" -> "); TulisPoint(new_p_1); printf("\n");

    printf("Bergeser secara sumbu y\n");
    TulisPoint(peg2); printf(" -> "); TulisPoint(new_p_2); printf("\n");
}