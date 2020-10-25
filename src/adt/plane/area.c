#include "area.h"
#include "math.h"
#include "point.h"

boolean isAreaValid(POINT P1, POINT P2){
    return (fabs(Absis(P1)-Absis(P2)) > 0.00000001) && (fabs(Ordinat(P1)-Ordinat(P2)) > 0.00000001);
}

void fixArea(AREA *A){
    POINT newLeft, newRight;
    Absis(newLeft) = (Absis(POSL(*A)) > Absis(POSR(*A)) ? Absis(POSR(*A)) : Absis(POSL(*A)));
    Absis(newRight) = (Absis(POSL(*A)) < Absis(POSR(*A)) ? Absis(POSR(*A)) : Absis(POSL(*A)));
    Ordinat(newLeft) = (Ordinat(POSL(*A)) > Ordinat(POSR(*A)) ? Ordinat(POSR(*A)) : Ordinat(POSL(*A)));
    Ordinat(newRight) = (Ordinat(POSL(*A)) < Ordinat(POSR(*A)) ? Ordinat(POSR(*A)) : Ordinat(POSL(*A)));

    POSL(*A) = newLeft;
    POSR(*A) = newRight;

}

void MakeArea(AREA *A, POINT P1, POINT P2){
    POSL(*A) = P1;
    POSR(*A) = P2;
    fixArea(A);
}

boolean AEQ (AREA A1, AREA A2){
    return (PEQ(POSL(A1), POSL(A2))) && (PEQ(POSR(A1), POSR(A2)));
}
boolean ANEQ (AREA A1, AREA A2){
    return (!AEQ(A1, A2));
}

float AWidth(AREA A){
    return fabs(Absis(POSL(A))-Absis(POSR(A)));
}

float AHeight(AREA A){
    return fabs(Ordinat(POSL(A))-Ordinat(POSR(A)));
}

float ASize(AREA A){
    return AHeight(A)*AWidth(A);
}

void AGeser(AREA *A, float deltaX, float deltaY){
    PGeser(&(POSL(*A)), deltaX, deltaY);
    PGeser(&(POSR(*A)), deltaX, deltaY);
}

void AMirror(AREA *A, boolean SbX){
    PMirror(&(POSL(*A)), SbX);
    PMirror(&(POSR(*A)), SbX);
}
void APutar(AREA *A, float Sudut){
    PPutar(&(POSL(*A)), Sudut);
    PPutar(&(POSR(*A)), Sudut);
}