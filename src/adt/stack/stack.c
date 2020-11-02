#include <stdio.h>
#include "stack.h"

void MakeStack (Stack *S, int maxel) {
    Top(*S) = Nil;
    MaxEl(*S) = maxel;
    T(*S) = (infotype *) malloc (maxel* sizeof(infotype));
    Duration(*S) = 0;
}

boolean IsEmpty (Stack S) {
    return Top(S) == Nil;
}

boolean IsFull (Stack S) {
    return Top(S) == MaxEl(S)-1;
}

void Push (Stack * S, WAHANA w) {
    if (PasTime(*S)) {
        Top(*S)++;
        InfoTop(*S) = w.char[Top(*S)];
        Duration(*S) += JamToDetik(w.Durasi);
    }
    else printf("Error");
}

void Pop (Stack * S, infotype* X) {
    *X = InfoTop(*S);
    Top(*S)--;
}

boolean PastTime (Stack S) {
    
}

void MoveToTarget (Stack * S1, Stack * S2) {
    infotype X;
    while (!IsEmpty(*S1)) {
        Pop(S1, &X);
        Push(S2, X);
    }
    Duration(*S) = 0;
}