#ifndef LIST_H
#define LIST_H

#include "../constant/adt.h"

/* Definisi list: */
/* List kosong: First = Nil and Last = Nil */
/* Setiap elemen dengan LLaddress P dapat diacu Info(P), Prev(P), Next(P) */

/*** Alokasi dan dealokasi memori ***/
LLaddress AlokasiLL(LLElType X);
/* Mengalokasikan memori untuk node N */

void DealokasiLL(LLaddress* a);
/* Mendealokasi memori node N */

/*** Konstruktor ***/
void MakeEmptyLL(List* L);
/* Membuat list kosong */

/*** Selektor ***/
LLElType GetFirstElmtLL(List L);
/* Mengembalikan nilai elemen pertama pada list*/

LLElType GetLastElmtLL(List L);
/* Mengembalikan nilai elemen terakhir pada list*/

/*** Testing ***/
boolean IsEmptyLL(List L);
/*Mencari tahu apakah list kosong atau tidak*/

/*** Searching ***/
boolean IsXElmtLL(List L, LLElType X);
/* Mencari tahu apakah nilai X ada di list */

int CountXElmtLL(List L, LLElType X);
/* Menghitung jumlah kemunculan X pada list */

LLaddress FindAdrFirstElmtXLL(List L, LLElType X);
/* Mengembalikan adress dari node yang berelement X */

boolean DoesAdressExistLL(List L, LLaddress a);
/* Mengecek apakah LLaddress ada pada list */

/*** Info ***/
int NbElmtLL(List L);
/* Menghitung total banyaknya Elemen pada list */

/*** Insert/Delete ***/
void InsertAfterLL(List* L, LLaddress a, LLElType X);
/* Menambahkan elemen Y setelah elemen X pada list */

void InsertFirstLL(List* L, LLElType X);
/* Menambahkan elemen X di awal list */

void InsertLastLL(List* L, LLElType X);
/* Menambahkan elemen X di akhir list */

void DeleteAfterLL(List*L, LLaddress a);
/* Menghapus Elemen yang berada tepat setelah elemen X pada list */

void DeleteFirstLL(List* L);
/* Menghapus Elemen pertama pada list */

void DeleteLastLL(List* L);
/* Menghapus Elemen terakhir pada list*/

#endif