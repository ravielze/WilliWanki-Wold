#ifndef LIST_H
#define LIST_H

#include "../boolean.h"
#include "stdlib.h"

#define Nil NULL
typedef int ElType;
typedef struct tNode* address;
typedef struct tNode {
    ElType info;
    address next;
} Node;

/* Definisi list: */
/* List kosong: First = Nil and Last = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Prev(P), Next(P) */
typedef struct {
    address First; address Last;
} List;

/* Selektor */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)
#define Last(L) ((L).Last)

/*** Alokasi dan dealokasi memori ***/
address Alokasi(ElType X);
/* Mengalokasikan memori untuk node N */

void Dealokasi(address* a);
/* Mendealokasi memori node N */

/*** Konstruktor ***/
void MakeEmpty(List* L);
/* Membuat list kosong */

/*** Selektor ***/
ElType GetFirstElmt(List L);
/* Mengembalikan nilai elemen pertama pada list*/

ElType GetLastElmt(List L);
/* Mengembalikan nilai elemen terakhir pada list*/

/*** Testing ***/
boolean IsEmpty(List L);
/*Mencari tahu apakah list kosong atau tidak*/

/*** Searching ***/
boolean IsXElmt(List L, ElType X);
/* Mencari tahu apakah nilai X ada di list */

int CountXElmt(List L, ElType X);
/* Menghitung jumlah kemunculan X pada list */

address FindAdrElmtX(List L, ElType X);
/* Mengembalikan adress dari node yang berelement X */

boolean DoesAdressExist(List L, address a);
/* Mengecek apakah address ada pada list */

/*** Info ***/
int NbElmt(List L);
/* Menghitung total banyaknya Elemen pada list */

/*** Insert/Delete ***/
boolean InsertAfter(List* L, address a, ElType X);
/* Menambahkan elemen Y setelah elemen X pada list */

boolean InsertFirst(List* L, ElType X);
/* Menambahkan elemen X di awal list */

boolean InsertLast(List* L, ElType X);
/* Menambahkan elemen X di akhir list */

void DeleteAfter(List*L, address a);
/* Menghapus Elemen yang berada tepat setelah elemen X pada list */

void DeleteFirst(List* L);
/* Menghapus Elemen pertama pada list */

void DeleteLast(List* L);
/* Menghapus Elemen terakhir pada list*/

#endif