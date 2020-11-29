#ifndef __MATRIX_H_
#define __MATRIX_H_

#include "../constant/adt.h"
/* Gate dari tiap Peta sudah di tentukan pada .txt file ya*/
/* NBrsEff >= 1 dan NKolEff >= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeEmptyMATRIKS (int NB, int NK, MATRIKS* M);
    /* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
    /* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
    /* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

MATRIKS MakeMapMATRIKS(int NB, int NK, char* MapDisplay);
    /* Membuat MATRIKS Map berukuran 11 x 11 dengan */
    /* sisi terluarnya adalah # yaitu pagar, sisi dalamnya adalah . yaitu lahan */

void InitPeta (char* filename, MATRIKS* M);
    /* Membuat MATRIKS M sesuai pada filename */

/* *** Selektor "DUNIA MATRIKS" *** */
/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
Mindeks GetFirstIdxBrs (MATRIKS M);
    /* Mengirimkan Mindeks baris terkecil M */

Mindeks GetFirstIdxKol (MATRIKS M);
    /* Mengirimkan Mindeks kolom terkecil M */

Mindeks GetLastIdxBrs (MATRIKS M);
    /* Mengirimkan Mindeks baris terbesar M */

Mindeks GetLastIdxKol (MATRIKS M);
    /* Mengirimkan Mindeks kolom terbesar M */

MElType GetElmtDiagonal (MATRIKS M, Mindeks i);
    /* Mengirimkan elemen M(i,i) */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS* MHsl);
    /* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */ 

void TulisMATRIKS (MATRIKS M);
    /* I.S. M terdefinisi */
    /* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
    dipisahkan sebuah spasi di akhir matriks diberi sebuah newline*/
    /* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10
    */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2);
    /* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
    /* untuk setiap i,j yang merupakan Mindeks baris dan kolom M1(i,j) = M2(i,j) */
    /* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
    dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */

boolean EQSize (MATRIKS M1, MATRIKS M2);
    /* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
    /* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

#endif