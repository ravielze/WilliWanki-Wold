 /* ADT ARRAY ACTION DAN BAHAN */
/* Rata kiri, NEff eksplisit, alokasi dinamik */

#ifndef ARRAY_H
#define ARRAY_H

#include "../boolean.h"

/*  Kamus Umum */

#define IdxMin 0        /* Indeks minimum array */
#define IdxUndef -1     /* Indeks tak terdefinisi*/
#define StdLabelSize 20 /* Panjang label standar */

/* Definisi elemen dan koleksi objek */

typedef int IdxType; /* type indeks */

typedef struct {
    char *Label;
    int Value;
} Item;

typedef struct
{
    Item *TI;
    int Neff;
    int MaxEl;
} TabItem;
/*  Tabel kosong: T.Neff = 0
    Definisi elemen pertama : T.TI[0]
    Definisi elemen terakhir terdefinisi: T.TI[T.Neff] */

/* *** SELEKTOR *** */

#define ILabel(I) (I).Label
#define IValue(I) (I).Value

#define TI(T) (T).TI
#define Label(T, i) (T).TI[(i)].Label
#define Value(T, i) (T).TI[(i)].Value
#define ItemOf(T, i) (T).TI[(i)]
#define Neff(T) (T).Neff
#define MaxEl(T) (T).MaxEl

/* *** KONSTRUKTOR *** */

void MakeItem(Item *I, char* lbl, int val);
/* Membuat Item dengan Label lbl dan Value val */

void MakeEmpty(TabItem *T, int maxel);
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */

void Dealokasi(TabItem *T);
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

/* *** SELEKTOR LAIN *** */

int NbElmt(TabItem T);
/* Mengirimkan banyaknya elemen efektif tabel */

int MaxElement(TabItem T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

IdxType GetFirstIdx(TabItem T);
IdxType GetLastIdx(TabItem T);
/* First dan Last indeks efektif */

/* Test Indeks */

boolean IsIdxValid(TabItem T, IdxType i);
/* Indeks antara 0..MaxEl-1 */
boolean IsIdxEff(TabItem T, IdxType i);
/* Indeks antara 0..NEff-1 */

/* *** TEST KOSONG/PENUH *** */

boolean IsEmpty(TabItem T);
boolean IsFull(TabItem T);

/* *** BACA/TULIS *** */

void ReadTab(TabItem *T);
/* Membaca banyaknya elemen yang akan dimasukkan (N) */
/*  N = 0 -> MakeEmpty
    N > 0 -> Insert N Element
    Other -> Pesan kesalahan
/* Membaca label dan value secara berurutan */

void WriteTab(TabItem T);
/* Menuliskan isi tab */
/* Jika tabel kosong : menulis [] */

/* *** SEARCH *** */

/* !!!Ada kasus IsEmpty!!! */

IdxType SearchIdx(TabItem T, char *X);
/* Search elemen X -- indeks terkecil */
/* Jika tidak ada, mengirimkan IdxUndef */

boolean SearchBool(TabItem T, char *X);
/* Search elemen X -- boolean */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */

/* *** NILAI EKSTREM *** */

Item MaxTab(TabItem T);
Item MinTab(TabItem T);

/* *** SORTING *** */

/* !!!Ada kasus IsEmpty!!! */

void SortbyLabel(TabItem *T);
/* Mengurutkan berdasarkan alfabet */

void SortbyValue(TabItem *T, boolean asc);
/*  Jika asc = true, T terurut membesar */
/*  Jika asc = false, T terurut mengecil */

/* *** ADD/DEL *** */

void AddLast(TabItem *T, Item X);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */

void DelLabel(TabItem *T, char *lbl, Item *X);
/* Proses: Menghapus elemen dengan label X */

/* *** RESIZE *** */

void GrowTab(TabItem *T, int num);
/* Proses : Menambahkan max element sebanyak num */

void ShrinkTab(TabItem *T, int num);
/* Proses : Mengurangi max element sebanyak num */

#endif