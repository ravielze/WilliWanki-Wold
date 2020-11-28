#include "list.h"

/*** Alokasi dan dealokasi memori ***/
address AlokasiLL(ElType X){
/* Mengalokasikan memori untuk node N */
    address a;
    a = (address) malloc (sizeof(Node));
    if (a != Nil){
        a->info = X;
        a->next = Nil;
    }
    return a;
}

void DealokasiLL(address* a){
/* Mendealokasi memori node N */
    free(*a);
}

/*** Konstruktor ***/
void MakeEmptyLL(List* L){
/* Membuat list kosong */
    First(*L) = Nil;
    Last(*L) = Nil;
}

/*** Selektor ***/
ElType GetFirstElmtLL(List L){
/* Mengembalikan nilai elemen pertama pada list*/
    address a = First(L);
    return Info(a);
}

ElType GetLastElmtLL(List L){
/* Mengembalikan nilai elemen terakhir pada list*/
    address a = Last(L);
    return Info(a);
}

/*** Testing ***/
boolean IsEmptyLL(List L){
/*Mencari tahu apakah list kosong atau tidak*/
    return ((First(L) == Nil) && (Last(L) == Nil));
}

/*** Searching ***/
boolean IsXElmtLL(List L, ElType X){
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

int CountXElmtLL(List L, ElType X){
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

address FindAdrFirstElmtXLL(List L, ElType X){
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

boolean DoesAdressExistLL(List L, address N){
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
int NbElmtLL(List L){
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
boolean InsertAfterLL(List* L, address N, ElType X){
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

boolean InsertFirstLL(List* L, ElType X){
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

boolean InsertLastLL(List* L, ElType X){
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

void DeleteAfterLL(List*L, address N){
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

void DeleteFirstLL(List* L){
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

void DeleteLastLL(List* L){
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