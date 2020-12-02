#include "stack.h"

void MakeStack (Stack *S) {
    Top(*S) = -1;
    MaxEl(*S) = 10;
    Aksi* y = (Aksi *) malloc (10* sizeof(Aksi));
    IsiStack(*S) = y;
}

Aksi createAksi(int id, char aksi){
    Aksi a;
    IDAksi(a) = id;
    InfoAksi(a) = aksi;
    return a;
}

boolean IsStackEmpty (Stack S) {
    return (Top(S) == -1);
}

boolean IsStackFull (Stack S) {
    return Top(S) == MaxEl(S)-1;
}

void PushAksi (Stack * S, Aksi X) {
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
    printf("AAAAAAAAAAAAAAAAAAAAAANJIR GILA\n");
    Top(*S) += 1;
    InfoTop(*S) = X;
}

// typedef struct {
//   int id;
//   char aksi;
// } Aksi;

// typedef struct {
//   int MaxEl;
//   Aksi *TA; 
//   int TOP; 
// } Stack;

void PopAksi (Stack * S, Aksi* X) {
    if (IsStackEmpty(*S)) return;
    if (Top(*S) == 0){
        *X = InfoTop(*S);
        printf("%d %c\n", IDAksi(*X), InfoAksi(*X));
        Top(*S) = -1;
        printf("tes\n");
        return;
    }
    printf("JIRRRRRRRRRRRRRRRRRRRRRRR\n");
    if (Top(*S) <= (MaxEl(*S)/4) && MaxEl(*S) > 10) {
        printf("aaa");
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
        printf("bbb");
    *X = InfoTop(*S);
    Top(*S)--;
}

void InverseStack (Stack * S1, Stack * S2) {
    MakeStack(S2);
    while (!IsStackEmpty(*S1)) {
        Aksi temp;
        PopAksi(S1, &temp);
        PushAksi(S2, temp);
    }
}

boolean isIDInStack(Stack S, int id) {
    while (!IsStackEmpty(S)) { 
        Aksi temp;
        PopAksi(&S, &temp);
        if (IDAksi(temp) == id) {
            return true;
        }
    }
    return false;
}

void MoveStack (Stack * S1, Stack * S2) {
    Stack temp;
    MakeStack(&temp);
    InverseStack(S1, &temp);
    while (!IsStackEmpty(temp)) {
        Aksi P;
        PopAksi(&temp, &P);
        PushAksi(S2, P);
    }
}