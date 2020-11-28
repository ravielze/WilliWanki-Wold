#ifndef __MATRIX_H_
#define __MATRIX_H_

#include "../boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 0
#define BrsMax 99
#define KolMin 0
#define KolMax 99

typedef int indeks; /* indeks baris, kolom */
typedef char ElType; 
typedef struct { 
	ElType Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
    int Xplayer;
    int Yplayer;
} MATRIKS;
/* Gate dari tiap Peta sudah di tentukan:
    Peta 1: 
        Ke Gate 2 (NKolEff - 1, 5)
        Ke Gate 4 (NBrsEff - 1, 5)
    Peta 2:
        Ke Gate 2 (0, 5)
        Ke Gate 3 (NBrsEff - 1, 5)
    Peta 3:
        Ke Gate 4 (0, 5)
        Ke Gate 2 (0, 5)
    Peta 4:
        Ke Gate 1 (0, 5)
        Ke Gate 3 (NKolEff - 1, 5)
*/
/* NBrsEff >= 1 dan NKolEff >= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]
#define Xplayer(M) (M).Xplayer
#define Yplayer(M) (M).Yplayer

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
indeks GetFirstIdxBrs (MATRIKS M);
    /* Mengirimkan indeks baris terkecil M */

indeks GetFirstIdxKol (MATRIKS M);
    /* Mengirimkan indeks kolom terkecil M */

indeks GetLastIdxBrs (MATRIKS M);
    /* Mengirimkan indeks baris terbesar M */

indeks GetLastIdxKol (MATRIKS M);
    /* Mengirimkan indeks kolom terbesar M */

ElType GetElmtDiagonal (MATRIKS M, indeks i);
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
    /* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
    /* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
    dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */

boolean EQSize (MATRIKS M1, MATRIKS M2);
    /* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
    /* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

#endif