#ifndef stack_H
#define stack_H

#include "../boolean.h"

#define Nil NULL
/* Nil adalah stack dengan elemen kosong . */
#define infotype Aksi
#define idx int

typedef struct {
  int id;
  char aksi;
} Aksi;

// 'b' for build yeahh
// 'm' for buy material
// 'u' upgradeeeeeeeeeeeeeee

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
  int MaxEl;
  Aksi *TA; /* tabel penyimpan elemen */
  idx TOP; /* alamat TOP: elemen puncak */
} Stack;

/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).TA[(S).TOP]
#define MaxEl(S) (S).MaxEl
#define IsiStack(S) (S).TA
#define IDAksi(A) (A).id
#define InfoAksi(A) (A).aksi

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void MakeStack (Stack *S);

Aksi createAksi(int id, char aksi);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty (Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackFull (Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushChar (Stack * S, char C);
/* Menambahkan C sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

void PushAksi (Stack * S, Aksi X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopAksi (Stack * S, Aksi* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void InverseStack (Stack * S1, Stack * S2);
/* Memindahkan isi dari S1 (stack awal) ke S2 (stack target)
 * I.S. S1 mungkin kosong dan S2 kosong
 * F.S. S1 kosong, isi S2 = S1 yang mula-mula */
#endif
