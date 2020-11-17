/* ADT ARRAY ACTION DAN BAHAN */
/* Rata kiri, NEff eksplisit, alokasi dinamik */

#include "../boolean.h"
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/* *** KONSTRUKTOR *** */

void MakeItem(Item *I, char* lbl, int val)
/* Membuat Item dengan Label lbl dan Value val */
{
    strcpy(ILabel(*I), lbl);
    IValue(*I) = val;
}

void MakeEmpty(TabItem *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
{
    TI(*T) = malloc(maxel * sizeof(Item));
    MaxEl(*T) = maxel;
    Neff(*T) = 0;
}

void Deallocate(TabItem *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
    free(TI(*T));
    MaxEl(*T) = 0;
    Neff(*T) = 0;
}

/* *** SELEKTOR LAIN *** */

int NbElmt(TabItem T)
/* Mengirimkan banyaknya elemen efektif tabel */
{
    return Neff(T);
}

int MaxElement(TabItem T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return MaxEl(T);
}

IdxType GetFirstIdx(TabItem T)
/* First indeks efektif */
{
    return IdxMin;
}

IdxType GetLastIdx(TabItem T)
/* Last indeks efektif */
{
    return Neff(T) - 1;
}

/* Test Indeks */

boolean IsIdxValid(TabItem T, IdxType i)
/* Indeks antara 0..MaxEl-1 */
{
    return (i >= IdxMin && i < MaxEl(T));
}

boolean IsIdxEff(TabItem T, IdxType i)
/* Indeks antara 0..NEff-1 */
{
    return (i >= GetFirstIdx(T) && i < GetLastIdx(T));
}

/* *** TEST KOSONG/PENUH *** */

boolean IsEmpty(TabItem T)
{
    return (Neff(T) == 0);
}

boolean IsFull(TabItem T)
{
    return (Neff(T) == MaxEl(T));
}

/* *** SEARCH *** */

/* !!!Ada kasus IsEmpty!!! */

IdxType SearchIdx(TabItem T, char *X)
/* Search elemen X -- indeks terkecil */
/* Jika tidak ada, mengirimkan IdxUndef */
{
    int i = GetFirstIdx(T);
    while (i <= GetLastIdx(T)) {
        if (strcmp(Label(T, i), X) == 0) {
            return i;
        }
        i += 1;
    }
    return IdxUndef;
}

boolean SearchBool(TabItem T, char *X)
/* Search elemen X -- boolean */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
{
    int i = GetFirstIdx(T);
    while (i <= GetLastIdx(T)) {
        if (strcmp(Label(T, i), X) == 0) {
            return true;
        }
        i += 1;
    }
    return false;
}

/* *** NILAI EKSTREM *** */

Item MaxTab(TabItem T)
{
    int Max = Value(T, GetFirstIdx(T));
    int MaxIdx = GetFirstIdx(T);
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (Value(T, i) > Max) {
            Max = Value(T, i);
            MaxIdx = i;
        }
    }
    return ItemOf(T, MaxIdx);
}

Item MinTab(TabItem T)
{
    int Min = Value(T, GetFirstIdx(T));
    int MinIdx = GetFirstIdx(T);
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (Value(T, i) < Min) {
            Min = Value(T, i);
            MinIdx = i;
        }
    }
    return ItemOf(T, MinIdx);
}

/* *** SORTING *** */

/* !!!Ada kasus IsEmpty!!! */

void SortbyLabel(TabItem *T)
/* Mengurutkan berdasarkan alfabet */
{
    Item temp;
    for (int i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++) {
        for (int j = i + 1; j <= GetLastIdx(*T); j++) {
            if (strcmp(Label(*T, i), Label(*T, j)) > 0) {
                //strcpy(temp, Label(*T, i));
                //strcpy(Label(*T, i), Label(*T, j));
                //strcpy(Label(*T, i), temp);
                temp = ItemOf(*T, i);
                ItemOf(*T, i) = ItemOf(*T, j);
                ItemOf(*T, j) = temp;
            }
        }
    }
}

void SortbyValue(TabItem *T, boolean asc)
/*  Jika asc = true, T terurut membesar */
/*  Jika asc = false, T terurut mengecil */
{
    Item temp;
    if (asc) {
        for (int i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++) {
            for (int j = i + 1; j <= GetLastIdx(*T); j++) {
                if (Value(*T, j) < Value(*T, i)) {
                    //strcpy(temp, Label(*T, i));
                    //strcpy(Label(*T, i), Label(*T, j));
                    //strcpy(Label(*T, i), temp);
                    temp = ItemOf(*T, i);
                    ItemOf(*T, i) = ItemOf(*T, j);
                    ItemOf(*T, j) = temp;
                }
            }
        }
    } else {
        for (int i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++) {
            for (int j = i + 1; j <= GetLastIdx(*T); j++) {
                if (Value(*T, j) > Value(*T, i)) {
                    //strcpy(temp, Label(*T, i));
                    //strcpy(Label(*T, i), Label(*T, j));
                    //strcpy(Label(*T, i), temp);
                    temp = ItemOf(*T, i);
                    ItemOf(*T, i) = ItemOf(*T, j);
                    ItemOf(*T, j) = temp;
                }
            }
        }
    }
}

/* *** ADD/DEL *** */

void AddLast(TabItem *T, Item X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
{
    if (!IsFull(*T)) {
        Label(*T, GetLastIdx(*T) + 1) = malloc(StdLabelSize * sizeof(char)); 
        strcpy(Label(*T, GetLastIdx(*T) + 1), ILabel(X));
        Value(*T, GetLastIdx(*T) + 1) = IValue(X); 
    } else {
        GrowTab(T, 1);
        Label(*T, GetLastIdx(*T) + 1) = malloc(StdLabelSize * sizeof(char)); 
        strcpy(Label(*T, GetLastIdx(*T) + 1), ILabel(X));
        Value(*T, GetLastIdx(*T) + 1) = IValue(X); 
    }
    Neff(*T) += 1;
}

void DelLabel(TabItem *T, char *lbl, Item *X)
/* Proses: Menghapus elemen dengan label X */
{
    IdxType a = SearchIdx(*T, lbl);
    if (a != IdxUndef) {
        *X = ItemOf(*T, a);
        for (int i = a; i < GetLastIdx(*T); i++) {
            ItemOf(*T, i) = ItemOf(*T, i+1);
        }
        Label(*T, GetLastIdx(*T)) = NULL;
        Value(*T, GetLastIdx(*T)) = 0;
        Neff(*T) -= 1;
    }
}

/* *** RESIZE *** */

void GrowTab(TabItem *T, int num)
/* Proses : Menambahkan max element sebanyak num */
{
    TabItem TBig;
    MakeEmpty(&TBig, MaxElement(*T) + num);
    Neff(TBig) = Neff(*T);
    for (int i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++) {
        ItemOf(TBig, i) = ItemOf(*T, i);
    }
    Deallocate(T);
    *T = TBig;
}

void ShrinkTab(TabItem *T, int num)
/* Proses : Mengurangi max element sebanyak num */
{
    TabItem TSmall;
    MakeEmpty(&TSmall, MaxElement(*T) - num);
    Neff(TSmall) = Neff(*T);
    for (int i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++) {
        ItemOf(TSmall, i) = ItemOf(*T, i);
    }
    Deallocate(T);
    *T = TSmall;
}