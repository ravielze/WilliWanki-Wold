#include "jam.h"
#include <stdio.h>

boolean IsJamValid (int H, int M){
    return ((H >= 0) && (H <= 23) && (M >= 0) && (M <= 59));
}

void MakeJam (JAM* J, int HH, int MM){
    JAM jam;
    Hour(jam) = HH;
    Minute(jam) = MM;
    *J = jam;
}

void MakeJamFromMenit (JAM* J, long menit){
    MakeJam(J, ((menit % 1440) / 60), (menit % 1440) % 60);
}

void TulisJam (JAM J){
    if (Hour(J) < 10) printf("0");
    printf("%d.", Hour(J));

    if (Minute(J) < 10) printf("0");
    printf("%d", Minute(J));
}

void TimeRemain (JAM J) {
    printf("Time Remaining: ");
    if (Hour(J) == 0 && Minute(J) == 0) printf("-");
    else {
        if (Hour(J) != 0) printf("%d hour(s) ", Hour(J));
        if (Minute(J) != 0) printf("%d minute(s)", Minute(J));
    }
}

long JamToMenit (JAM J){
    return (60L*Hour(J) + 1L*Minute(J));
}

boolean JEQ (JAM J1, JAM J2){
    return(JamToMenit(J1) == JamToMenit(J2));
}

boolean JNEQ (JAM J1, JAM J2){
    return(JamToMenit(J1) != JamToMenit(J2));
}

boolean JLT (JAM J1, JAM J2){
    return(JamToMenit(J1) < JamToMenit(J2));
}

boolean JGT (JAM J1, JAM J2){
    return(JamToMenit(J1) > JamToMenit(J2));
}

JAM NextNMenit (JAM J, int N){
    JAM result;
    MakeJamFromMenit(&result, JamToMenit(J) + (1L*N));
    return result;
}

JAM NextMenit (JAM J){
    return NextNMenit(J, 1);
}

JAM PrevNMenit (JAM J, int N){
    JAM result;
    MakeJamFromMenit(&result, JamToMenit(J) - (1L*N));
    return result;
}

JAM PrevMenit (JAM J){
    return PrevNMenit(J, 1);
}

long Durasi (JAM JAw, JAM JAkh){
    return((JamToMenit(JAkh)-JamToMenit(JAw)+1440)%1440);
}