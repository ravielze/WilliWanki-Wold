#ifndef stack_H
#define stack_H

#include "../boolean.h"
#include "../wahana/wahana.h"

#define Nil -1
/* Nil adalah stack dengan elemen kosong . */

typedef char infotype;
typedef int indeks;

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  int MaxEl;
  WAHANA *S; /* tabel penyimpan elemen */
  indeks TOP;  /* alamat TOP: elemen puncak */
  int duration; /* total durasi upgrade, build, dan buy */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP].char[(S).TOP]
#define Duration(S) (S).duration
#define Time(S) (S).

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void MakeStack (Stack *S, int maxel);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty (Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull (Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, WAHANA w);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotype* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

boolean PastTime (Stack S);
/* Mengirim true jika waktu yang dibutuhkan semua aksi di dalam stack melebihi durasi tutup wahana */

void MoveToTarget (Stack * S1, Stack * S2);
/* Memindahkan isi dari S1 (stack awal) ke S2 (stack target)
 * I.S. S1 mungkin kosong dan S2 kosong
 * F.S. S1 kosong, isi S2 = S1 yang mula-mula */
#endif
