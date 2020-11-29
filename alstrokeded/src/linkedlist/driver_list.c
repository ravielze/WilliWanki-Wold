#include "list.h"
#include "../constant/adt.h"
#include "../constant/selector.h"
#include <stdio.h>
#include <stdlib.h>

void PrintList(List L) {
    // Print every element in list!
    if (!IsEmptyLL(L)) {
        LLaddress P = First(L);
        while (P != Nil) {
            printf("%d ", AInfo(P));
            P = ANext(P);
        }
    }
}

int main() {
    printf("-- TES ALOKASI --\n");

    LLaddress P = AlokasiLL(1);
    if (P != Nil) {
        if (AInfo(P) == 1) {
            printf("Alokasi P berhasil.\n");
        }
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
    InsertLastLL(&L, 5);

    LLaddress P1 = FindAdrFirstElmtXLL(L, 2);
    InsertAfterLL(&L, P1, 3);
    printf("Isi List: "); PrintList(L); printf("\n\n");

    printf("-- TES DELETE --\n");

    DeleteFirstLL(&L);
    DeleteLastLL(&L);
    DeleteAfterLL(&L, P1);
    printf("Isi List: "); PrintList(L); printf("\n\n");

    printf("-- TES GET --\n");
    printf("Elemen pertama: %d\n", GetFirstElmtLL(L));
    printf("Elemen terakhir: %d\n\n", GetLastElmtLL(L));

    printf("-- TES SEARCH/COUNT --\n");
    if (IsXElmtLL(L, 2)) {
        printf("2 adalah elemen List.\n");
    }
    if (!IsXElmtLL(L, 3)) {
        printf("3 bukan elemen List.\n");
    }
    printf("Ada %d angka 2 dari %d elemen List.\n", CountXElmtLL(L, 2), NbElmtLL(L));

    return 0;
}