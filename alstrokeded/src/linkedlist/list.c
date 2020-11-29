#include "list.h"

/*** Alokasi dan dealokasi memori ***/
LLaddress AlokasiLL(LLElType X){
/* Mengalokasikan memori untuk node N */
    LLaddress a;
    a = (LLaddress) malloc (sizeof(LLNode));
    if (a != Nil){
        AInfo(a) = X;
        ANext(a) = Nil;
    }
    return a;
}

void DealokasiLL(LLaddress* a){
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
LLElType GetFirstElmtLL(List L){
/* Mengembalikan nilai elemen pertama pada list*/
    LLaddress a = First(L);
    return AInfo(a);
}

LLElType GetLastElmtLL(List L){
/* Mengembalikan nilai elemen terakhir pada list*/
    LLaddress a = Last(L);
    return AInfo(a);
}

/*** Testing ***/
boolean IsEmptyLL(List L){
/*Mencari tahu apakah list kosong atau tidak*/
    return ((First(L) == Nil) && (Last(L) == Nil));
}

/*** Searching ***/
boolean IsXElmtLL(List L, LLElType X){
/* Mencari tahu apakah nilai X ada di list */
    if (!IsEmptyLL(L)){
        LLaddress a = First(L);
        while (a != Nil){
            if (AInfo(a) == X) return (AInfo(a) == X);
            else a = ANext(a);
        }
    }
    return false;
}

int CountXElmtLL(List L, LLElType X){
/* Menghitung jumlah kemunculan X pada list */
    if (!IsEmptyLL(L)){
        LLaddress a = First(L);
        int count = 0;
        while (a != Nil){
            if (AInfo(a) == X) count++;
            a = ANext(a);
        }
        return count;
    }
    return 0;
}

LLaddress FindAdrFirstElmtXLL(List L, LLElType X){
/* Mengembalikan LLaddress dari node yang berelement X */
/* Jika tidak ditemukan Elemen X pada LLaddress, akan direturn nil */
    if (!IsEmptyLL(L)){
        LLaddress a = First(L);
        while (a != Nil){
            if (AInfo(a) == X) return a;
            a = ANext(a);
        }
    }
    return Nil;
}

boolean DoesAdressExistLL(List L, LLaddress N){
/* Mengecek apakah LLaddress ada pada list */
    if(!IsEmptyLL(L)){
        LLaddress a = First(L);
        while (a != Nil){
            if (a == N) return true;
            a = ANext(a);
        }
    }
    return false;
}

/*** AInfo ***/
int NbElmtLL(List L){
/* Menghitung total banyaknya Elemen pada list */
    LLaddress a = First(L);
    int count = 0;
    while (a != Nil){
        count++;
        a = ANext(a);
    }
    return count;
}

/*** Insert/Delete ***/
boolean InsertAfterLL(List* L, LLaddress N, LLElType X){
/* Menambahkan elemen Y setelah elemen X pada list */
    if (!IsEmptyLL(*L)){
        LLaddress P = AlokasiLL(X);
        if (P != Nil){
            LLaddress a = First(*L);
            while (a != Nil){
                if (a == N){
                    ANext(P) = ANext(a);
                    ANext(a) = P;
                    return true;
                }
                a = ANext(a);
            }
        }
    }
    return false;
}

boolean InsertFirstLL(List* L, LLElType X){
/* Menambahkan elemen X di awal list */
    LLaddress P = AlokasiLL(X);
    if (P != Nil){
        if (IsEmptyLL(*L)){
            First(*L) = P;
            Last(*L) = P;
        } else {
            ANext(P) = First(*L);
            First(*L) = P;
        }
        return true;
    }
    return false;
}

boolean InsertLastLL(List* L, LLElType X){
/* Menambahkan elemen X di akhir list */
    LLaddress P = AlokasiLL(X);
    if (P != Nil){
        if (IsEmptyLL(*L)){
            First(*L) = P;
            Last(*L) = P;
        } else {
            ANext(Last(*L)) = P;
            Last(*L) = P;
        }
        return true;
    }
    return false;
}

void DeleteAfterLL(List*L, LLaddress N){
/* Menghapus Elemen yang berada tepat setelah LLaddress N pada list */
    if (!IsEmptyLL(*L) && (Last(*L) != N) && DoesAdressExistLL(*L,N)){
        LLaddress a = First(*L),temp;
        boolean deleted = false;
        while ((a != Nil) && !deleted){
            if (a == N){
                temp = ANext(a);
                ANext(a) = ANext(ANext(a));
                DealokasiLL(&temp);
                deleted = true;
            }
            a = ANext(a);
        }
    }
}

void DeleteFirstLL(List* L){
/* Menghapus Elemen pertama pada list */
    if (NbElmtLL(*L) == 1){
        DealokasiLL(&First(*L));
        First(*L) = Nil;
        Last(*L) = Nil;
    } else if (!IsEmptyLL(*L)){
        LLaddress temp = First(*L);
        First(*L) = ANext(First(*L));
        DealokasiLL(&temp);
    }
}

void DeleteLastLL(List* L){
/* Menghapus Elemen terakhir pada list*/
    if (NbElmtLL(*L) == 1){
        DealokasiLL(&First(*L));
        First(*L) = Nil;
        Last(*L) = Nil;
    } else if (!IsEmptyLL(*L)){
        LLaddress a = First(*L);
        while (a != Nil){
            if (ANext(a) == Last(*L)){
                DealokasiLL(&Last(*L));
                ANext(a) = Nil;
            }
            a = ANext(a);
        }
    }
}