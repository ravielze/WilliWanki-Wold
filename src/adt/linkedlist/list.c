#include "list.h"

/*** Alokasi dan dealokasi memori ***/
address Alokasi(ElType X){
/* Mengalokasikan memori untuk node N */
    address a;
    a = (address) malloc (sizeof(Node));
    if (a != Nil){
        a->info = X;
        a->next = Nil;
    }
    return a;
}

void Dealokasi(address* a){
/* Mendealokasi memori node N */
    free(*a);
}

/*** Konstruktor ***/
void MakeEmpty(List* L){
/* Membuat list kosong */
    First(*L) = Nil;
    Last(*L) = Nil;
}

/*** Selektor ***/
ElType GetFirstElmt(List L){
/* Mengembalikan nilai elemen pertama pada list*/
    address a = First(L);
    return Info(a);
}

ElType GetLastElmt(List L){
/* Mengembalikan nilai elemen terakhir pada list*/
    address a = Last(L);
    return Info(a);
}

/*** Testing ***/
boolean IsEmpty(List L){
/*Mencari tahu apakah list kosong atau tidak*/
    return ((First(L) == Nil) && (Last(L) == Nil));
}

/*** Searching ***/
boolean IsXElmt(List L, ElType X){
/* Mencari tahu apakah nilai X ada di list */
    if (!IsEmpty(L)){
        address a = First(L);
        while (a != Nil){
            if (Info(a) == X) return (Info(a) == X);
            else a = Next(a);
        }
    }
    return false;
}

int CountXElmt(List L, ElType X){
/* Menghitung jumlah kemunculan X pada list */
    if (!IsEmpty(L)){
        address a = First(L);
        int count = 0;
        while (a != Nil){
            if (Info(a) == X) count++;
            a = Next(a);
        }
        return count;
    }
    return 0;
}

address FindAdrFirstElmtX(List L, ElType X){
/* Mengembalikan address dari node yang berelement X */
/* Jika tidak ditemukan Elemen X pada address, akan direturn nil */
    if (!IsEmpty(L)){
        address a = First(L);
        while (a != Nil){
            if (Info(a) == X) return a;
            a = Next(a);
        }
    }
    return Nil;
}

boolean DoesAdressExist(List L, address N){
/* Mengecek apakah address ada pada list */
    if(!IsEmpty(L)){
        address a = First(L);
        while (a != Nil){
            if (a == N) return true;
            a = Next(a);
        }
    }
    return false;
}

/*** Info ***/
int NbElmt(List L){
/* Menghitung total banyaknya Elemen pada list */
    address a = First(L);
    int count = 0;
    while (a != Nil){
        count++;
        a = Next(a);
    }
    return count;
}

/*** Insert/Delete ***/
boolean InsertAfter(List* L, address N, ElType X){
/* Menambahkan elemen Y setelah elemen X pada list */
    if (!IsEmpty(*L)){
        address P = Alokasi(X);
        if (P != Nil){
            address a = First(*L);
            while (a != Nil){
                if (a == N){
                    Next(P) = Next(a);
                    Next(a) = P;
                    return true;
                }
                a = Next(a);
            }
        }
    } else return false;
}

boolean InsertFirst(List* L, ElType X){
/* Menambahkan elemen X di awal list */
    address P = Alokasi(X);
    if (P != Nil){
        if (IsEmpty(*L)){
            First(*L) = P;
            Last(*L) = P;
        } else {
            Next(P) = First(*L);
            First(*L) = P;
        }
        return true;
    }
    return false;
}

boolean InsertLast(List* L, ElType X){
/* Menambahkan elemen X di akhir list */
    address P = Alokasi(X);
    if (P != Nil){
        if (IsEmpty(*L)){
            First(*L) = P;
            Last(*L) = P;
        } else {
            Next(Last(*L)) = P;
            Last(*L) = P;
        }
        return true;
    }
    return false;
}

void DeleteAfter(List*L, address N){
/* Menghapus Elemen yang berada tepat setelah address N pada list */
    if (!IsEmpty(*L) && (Last(*L) != N) && DoesAdressExist(*L,N)){
        address a = First(*L),temp;
        boolean deleted = false;
        while ((a != Nil) && !deleted){
            if (a == N){
                temp = Next(a);
                Next(a) = Next(Next(a));
                Dealokasi(&temp);
                deleted = true;
            }
            a = Next(a);
        }
    }
}

void DeleteFirst(List* L){
/* Menghapus Elemen pertama pada list */
    if (NbElmt(*L) == 1){
        Dealokasi(&First(*L));
        First(*L) = Nil;
        Last(*L) = Nil;
    } else if (!IsEmpty(*L)){
        address temp = First(*L);
        First(*L) = Next(First(*L));
        Dealokasi(&temp);
    }
}

void DeleteLast(List* L){
/* Menghapus Elemen terakhir pada list*/
    if (NbElmt(*L) == 1){
        Dealokasi(&First(*L));
        First(*L) = Nil;
        Last(*L) = Nil;
    } else if (!IsEmpty(*L)){
        address a = First(*L);
        while (a != Nil){
            if (Next(a) = Last(*L)){
                Dealokasi(&Last(*L));
                Next(a) = Nil;
            }
            a = Next(a);
        }
    }
}

void BacaList(List L){
    if (IsEmpty(L)){
        printf("List Kosong!\n");
    } else {
        address a = First(L);
        printf("[");
        while (a != Nil){
            if (a == Last(L)) printf("%d",Info(a));
            else printf("%d, ",Info(a));
            a = Next(a);
        }
        printf("]\n");
    }
}