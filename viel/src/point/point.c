#include <stdio.h>
#include "point.h"

void MakePoint (POINT * P, int X, int Y) {
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void TulisPoint (POINT P) {
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean PEQ (POINT P1, POINT P2) {
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean PNEQ (POINT P1, POINT P2) {
    return (!PEQ(P1,P2));
}

POINT PNextX (POINT P) {
    POINT result;
    Absis(result) = Absis(P) + 1;
    Ordinat(result) = Ordinat(P);
    return result;
}

POINT PNextY (POINT P) {
    POINT result;
    Absis(result) = Absis(P);
    Ordinat(result) = Ordinat(P) + 1;
    return result;
}