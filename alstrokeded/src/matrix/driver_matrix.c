// 13519114
#include "matrix.h"

int main(){
    MATRIKS em; 
    MakeEmptyMATRIKS(5, 5, &em);
    char mapDisplay[5][5] = {
        {'#', '#', '#', '#', '#'},
        {'#', '.', '.', 'P', '#'},
        {'#', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#'} };

    // MATRIKS M = MakeMapMATRIKS(5, 5, mapDisplay);


    /* INIT PETA */
    MATRIKS hiya;
    
    /* COPY MATRIKS */
    MATRIKS yey;
    CopyMATRIKS(em, &yey);

    /* IS EQUAL */
    if (EQ(em, yey)) printf("Kedua matriks elemennya sama.\n");
    if (EQSize(em, yey)) printf("Kedua ukuran matriks sama.\n");

    return 0;
}

// void InitPeta (char* filename, MATRIKS* M);
//     /* Membuat MATRIKS M sesuai pada filename */

// /* *** Selektor "DUNIA MATRIKS" *** */
// /* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
// Mindeks GetFirstIdxBrs (MATRIKS M);
//     /* Mengirimkan Mindeks baris terkecil M */

// Mindeks GetFirstIdxKol (MATRIKS M);
//     /* Mengirimkan Mindeks kolom terkecil M */

// Mindeks GetLastIdxBrs (MATRIKS M);
//     /* Mengirimkan Mindeks baris terbesar M */

// Mindeks GetLastIdxKol (MATRIKS M);
//     /* Mengirimkan Mindeks kolom terbesar M */

// MElType GetElmtDiagonal (MATRIKS M, Mindeks i);
//     /* Mengirimkan elemen M(i,i) */