#include <stdio.h>
#include "stack.h"

void MakeStack (Stack *S) {
    Top(*S) = Nil;
}

boolean IsEmpty (Stack S) {
    return Top(S) == Nil;
}

boolean IsFull (Stack S) {
    return Top(S) == MaxEl-1;
}

void Push (Stack * S, infotype X) {
    Top(*S)++;
    InfoTop(*S) = X;
}

void Pop (Stack * S, infotype* X) {
    *X = InfoTop(*S);
    Top(*S)--;
}

boolean PastTime (Stack S) {
    long time = 0;
    while (!IsEmpty(S)) {
    }
}

void MoveToTarget (Stack * S1, Stack * S2) {
    infotype X;
    while (!IsEmpty(*S1)) {
        Pop(S1, &X);
        Push(S2, X);
    }
}