#ifndef stack_H
#define stack_H

#include "../constant/adt.h"
/* Nil adalah stack dengan elemen kosong . */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/

/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

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

/* ID ada dalem stack teeduckz ashsiapzz */
boolean isIDInStack(Stack S, int id);

/* Pindah ke stack, tapi posisinya sama */
void MoveStack (Stack * S1, Stack * S2);

#endif