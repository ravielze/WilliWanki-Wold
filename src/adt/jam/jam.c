#include "jam.h"
#include <stdio.h>

boolean IsJamValid (int H, int M, int S){
    return ((H >= 0) && (H <= 23) && (M >= 0) && (M <= 59) && (S >= 0) && (S <= 59));
}

void MakeJam (JAM* J, int HH, int MM, int SS){
    JAM jam;
    Hour(jam) = HH;
    Minute(jam) = MM;
    Second(jam) = SS;
    *J = jam;
}

void MakeJamFromDetik (JAM* J, long N){
    MakeJam(J, ((N % 86400) / 3600), (((N % 86400) % 3600) / 60), (((N % 86400) % 3600) % 60));
}

void TulisJam (JAM J){
    printf("%d:%d:%d", Hour(J), Minute(J), Second(J));
}

long JamToDetik (JAM J){
    return (3600L*Hour(J) + 60L*Minute(J) + 1L*Second(J));
}

boolean JEQ (JAM J1, JAM J2){
    return(JamToDetik(J1) == JamToDetik(J2));
}

boolean JNEQ (JAM J1, JAM J2){
    return(JamToDetik(J1) != JamToDetik(J2));
}

boolean JLT (JAM J1, JAM J2){
    return(JamToDetik(J1) < JamToDetik(J2));
}

boolean JGT (JAM J1, JAM J2){
    return(JamToDetik(J1) > JamToDetik(J2));
}

JAM NextNDetik (JAM J, int N){
    JAM result;
    MakeJamFromDetik(&result, JamToDetik(J) + (1L*N));
    return result;
}

JAM NextDetik (JAM J){
    return NextNDetik(J, 1);
}

JAM PrevNDetik (JAM J, int N){
    JAM result;
    MakeJamFromDetik(&result, JamToDetik(J) - (1L*N));
    return result;
}

JAM PrevDetik (JAM J){
    return PrevNDetik(J, 1);
}

long Durasi (JAM JAw, JAM JAkh){
    return((JamToDetik(JAkh)-JamToDetik(JAw)+86400)%86400);
}