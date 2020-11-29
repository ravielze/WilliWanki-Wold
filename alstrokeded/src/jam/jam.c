#include "jam.h"

boolean IsJamValid (int H, int M){
    return ((H >= 0) && (H <= 23) && (M >= 0) && (M <= 59));
}

void MakeJam (JAM* J, int HH, int MM){
    JAM jam;
    Hour(jam) = HH;
    Minute(jam) = MM;
    *J = jam;
}

void MakeJamFromMenit (JAM* J, int menit){
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
    if (Hour(J) == 0 && Minute(J) == 0) printf("0");
    else {
        if (Hour(J) != 0) printf("%d hour(s) ", Hour(J));
        if (Minute(J) != 0) printf("%d minute(s)", Minute(J));
    }
}

int JamToMenit (JAM J){
    return (60*Hour(J) + Minute(J));
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
    MakeJamFromMenit(&result, JamToMenit(J) + N);
    return result;
}

JAM NextMenit (JAM J){
    return NextNMenit(J, 1);
}

JAM PrevNMenit (JAM J, int N){
    JAM result;
    if (JamToMenit(J)-N < 0){
        MakeJamFromMenit(&result, 1440+(JamToMenit(J)-N));
    } else {
        MakeJamFromMenit(&result, JamToMenit(J)-N);
    }
    return result;
}

JAM PrevMenit (JAM J){
    return PrevNMenit(J, 1);
}

int Durasi (JAM JAw, JAM JAkh){
    if (JamToMenit(JAkh) < JamToMenit(JAw)){
        printf("TESTNYA ACIN : %d %d\n", JamToMenit(JAw), JamToMenit(JAkh));
        return (JamToMenit(JAkh)- JamToMenit(JAw) +1440);
    } else {
        printf("TESTNYA TOPER : %d %d\n", JamToMenit(JAw), JamToMenit(JAkh));
        return (JamToMenit(JAkh)- JamToMenit(JAw));
    }
}