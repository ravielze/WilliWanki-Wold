#include "list.h"
#include <stdio.h>

/*
ADT
typedef int LLElType;
typedef struct tLLNode* LLaddress;
typedef struct tLLNode {
    LLElType info;
    LLaddress next;
} LLNode;
typedef struct {
    LLaddress First, Last;
} List;

SELEKTOR
#define AInfo(P) ((P)->info)
#define ANext(P) ((P)->next)
#define First(L) ((L).First)
#define Last(L) ((L).Last)
*/

void PrintList(List L) {
    // Print every element in list!
    if (!IsEmpty(L)) {
        address P = First(L);
        while (P != Nil) {
            printf("%d ", Info(P));
            P = Next(P);
        }
    }
}

int main() {
    //LLaddress AlokasiLL(LLElType X);
    LLaddress P = AlokasiLL(1);
    //Info(L)

    List L;
    MakeEmptyLL(&L);

    return 0;
}