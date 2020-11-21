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
    address First, Last;
} List;

/* Selektor */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)
#define Last(L) ((L).Last)

/*** Alokasi dan dealokasi memori ***/
address AlokasiLL(ElType X);
/* Mengalokasikan memori untuk node N */

void DealokasiLL(address* a);
/* Mendealokasi memori node N */

/*** Konstruktor ***/
void MakeEmptyLL(List* L);
/* Membuat list kosong */

/*** Selektor ***/
ElType GetFirstElmtLL(List L);
/* Mengembalikan nilai elemen pertama pada list*/

ElType GetLastElmtLL(List L);
/* Mengembalikan nilai elemen terakhir pada list*/

/*** Testing ***/
boolean IsEmptyLL(List L);
/*Mencari tahu apakah list kosong atau tidak*/

/*** Searching ***/
boolean IsXElmtLL(List L, ElType X);
/* Mencari tahu apakah nilai X ada di list */

int CountXElmtLL(List L, ElType X);
/* Menghitung jumlah kemunculan X pada list */

address FindAdrElmtXLL(List L, ElType X);
/* Mengembalikan adress dari node yang berelement X */

boolean DoesAdressExistLL(List L, address a);
/* Mengecek apakah address ada pada list */

/*** Info ***/
int NbElmtLL(List L);
/* Menghitung total banyaknya Elemen pada list */

/*** Insert/Delete ***/
boolean InsertAfterLL(List* L, address a, ElType X);
/* Menambahkan elemen Y setelah elemen X pada list */

boolean InsertFirstLL(List* L, ElType X);
/* Menambahkan elemen X di awal list */

boolean InsertLastLL(List* L, ElType X);
/* Menambahkan elemen X di akhir list */

void DeleteAfterLL(List*L, address a);
/* Menghapus Elemen yang berada tepat setelah elemen X pada list */

void DeleteFirstLL(List* L);
/* Menghapus Elemen pertama pada list */

void DeleteLastLL(List* L);
/* Menghapus Elemen terakhir pada list*/

#endif