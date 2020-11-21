#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"

void MakeStack (Stack *S) {
    Top(*S) = Nil;
    MaxEl(*S) = 10;
    IsiStack(*S) = (Aksi *) malloc (10* sizeof(infotype));
}

boolean IsStackEmpty (Stack S) {
    return Top(S) == Nil;
}

boolean IsStackFull (Stack S) {
    return Top(S) == MaxEl(S)-1;
}

void PushChar (Stack * S, char C) {
    if (IsStackEmpty(*S)) {
        Top(*S) = -1;
    }
    if (IsStackFull(*S)) {
        MaxEl(*S) += 10;
        Aksi* temp = (Aksi *) realloc(IsiStack(*S), (MaxEl(*S) * sizeof(Aksi)));
        if (temp == Nil) {
            printf("Error reallocating memory.");
            IsiStack(*S) = Nil;
            return;
        } else {
            IsiStack(*S) = temp;
        }
    }
    Top(*S)++;
    Aksi a;
    IDAksi(a) = Top(*S);
    InfoAksi(a) = C;
    InfoTop(*S) = a;
}

void PushAksi (Stack * S, Aksi X) {
    if (IsStackEmpty(*S)) {
        Top(*S) = -1;
    }
    if (IsStackFull(*S)) {
        MaxEl(*S) += 10;
        Aksi* temp = (Aksi *) realloc(IsiStack(*S), (MaxEl(*S) * sizeof(Aksi)));
        if (temp == Nil) {
            printf("Error reallocating memory.");
            IsiStack(*S) = Nil;
            return;
        } else {
            IsiStack(*S) = temp;
        }
    }
    Top(*S)++;
    InfoTop(*S) = X;
}

void PopStack (Stack * S, Aksi* X) {
    if (Top(*S) <= (MaxEl(*S)/4)) {
        MaxEl(*S) /= 2;
        Aksi* temp = (Aksi *) realloc(IsiStack(*S), (MaxEl(*S) * sizeof(Aksi)));
        if (temp == Nil) {
            printf("Error reallocating memory.");
            IsiStack(*S) = Nil;
            return;
        }
        else {
            IsiStack(*S) = temp;
        }
    }
    *X = InfoTop(*S);
    Top(*S)--;
}

void InverseStack (Stack * S1, Stack * S2) {
    while (!IsStackEmpty(*S1)) {
        Aksi temp;
        PopStack(S1, &temp);
        PushAksi(S2, temp);
    }
}