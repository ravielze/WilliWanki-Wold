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

/* TESTING BENTAR
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
    printf("-- TES ALOK/DEALOK --\n");

    LLaddress P = AlokasiLL(1);
    if (P != Nil) {
        if (AInfo(P) == 1) {
            printf("Alokasi P berhasil.\n");
        }
    }

    DealokasiLL(P);
    if (P == Nil) {
        printf("2. Dealokasi P berhasil.\n\n");
    }

    printf("-- TES INSERT --\n");

    List L;
    MakeEmptyLL(&L);
    if (IsEmptyLL(L)) {
        printf("List kosong berhasil dibuat.\n");
    }

    InsertFirstLL(&L, 2);
    InsertFirstLL(&L, 1);
    InsertLastLL(&L, 4);
    InsertLastLL(L&, 4);

    P = FindAdrElmtXLL(L, 2);
    InsertAfterLL(&L, P, 3);
    printf("Isi List: "); PrintList(L); printf("\n\n");

    printf("-- TES DELETE --\n");

    DeleteFirstLL(&L);
    DeleteLastLL(&L);
    DeleteAfterLL(&L, P);
    printf("Isi List: "); PrintList(L); printf("\n\n");

    printf("-- TES GET --\n");
    printf("Elemen pertama: %d\n", GetFirstElmtLL(L));
    printf("Elemen terakhir: %d\n\n", GetLastElmtLL(L));

    printf("-- TES SEARCH/COUNT --\n");
    if (IsXElmtLL(L, 2)) {
        printf("2 adalah elemen List.\n")
    }
    if (!IsXElmtLL(L, 3)) {
        printf("3 bukan elemen List.\n")
    }
    printf("Ada %d angka 2 dari %d elemen List.", CountXElmtLL(L, 2), NbElmtLL(L));

    return 0;
}
*/