#include "point.h"
#include <stdio.h>

void MakePoint (POINT *P, float X, float Y){
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPoint (POINT *P){
    float x,y;
    scanf("%f %f", &x, &y);
    MakePOINT(P, x,y);
}

void TulisPoint (POINT P){
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean PEQ (POINT P1, POINT P2){
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));

}
boolean PNEQ (POINT P1, POINT P2){
    return (!PEQ(P1,P2));
}

POINT PNextX (POINT P){
    POINT result;
    Absis(result) = Absis(P) + 1;
    Ordinat(result) = Ordinat(P);
    return result;
}

POINT PNextY (POINT P){
    POINT result;
    Absis(result) = Absis(P);
    Ordinat(result) = Ordinat(P) + 1;
    return result;

}

POINT PPlusDelta (POINT P, float deltaX, float deltaY){
    POINT R;
    Absis(R) =  Absis(P) + deltaX;
    Ordinat(R) = Ordinat(P) + deltaY;
    return R;
}

float PJarak0 (POINT P){
    return (sqrt(pow(Ordinat(P),2) + pow(Absis(P),2)));
}

float PPanjang (POINT P1, POINT P2){
    return Jarak0(PlusDelta(P2, -Absis(P1), -Ordinat(P1)));
}

void PGeser (POINT *P, float deltaX, float deltaY){
    P->X += deltaX;
    P->Y += deltaY;
}

void PGeserKeSbX (POINT *P){
    P->Y = 0;
}

void PGeserKeSbY (POINT *P){
    P->X = 0;
}

void PMirror (POINT *P, boolean SbX){
    P->X = (SbX) ? P->X : -1*(P->X);
    P->Y = (SbX) ? -1*(P->Y) : P->Y;
}

void PPutar (POINT *P, float s){
    float Sudut = -(s/180)*acos(-1);
    float x = P->X, y = P->Y;
    P->X = (cos(Sudut)*x)-(sin(Sudut)*y);
    P->Y = (sin(Sudut)*x)+(cos(Sudut)*y);
}