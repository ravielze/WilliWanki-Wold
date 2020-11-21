#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeEmptyMATRIKS (int NB, int NK, MATRIKS* M){
    /* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
    /* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
    /* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

MATRIKS MakeMapMATRIKS(int NB, int NK, char* MapDisplay){
    /* Membuat MATRIKS Map berukuran 11 x 11 dengan */
    /* sisi terluarnya adalah # yaitu pagar, sisi dalamnya adalah . yaitu lahan */
    MATRIKS Peta;
    MakeEmptyMATRIKS(NB, NK, &Peta);

    for (int i = 0; i < NB; i ++) {
        for (int j = 0; j < NK; j++) {
            Elmt(Peta, i, j) = *( (MapDisplay + i * NK) + j);
            if (Elmt(Peta, i, j) == 'P') {
                Xplayer(Peta) = j;
                Yplayer(Peta) = i;
            }
        }
    }

    return Peta;
}

void InitPeta (char* filename, MATRIKS* M) {
    static int retval;
    int NB, NK;
    FILE* MapFile = fopen(filename, "r");

    retval = fscanf(MapFile, "%d %d\n", &NB, &NK);

    char MapDisplay[NB][NK];      
    int i = 0, j = 0;

    while(retval != EOF) {
        char c;

        retval = fscanf(MapFile, "%c", &c);
        if (c != '\n' && c != ' ') {
            MapDisplay[i][j] = c;
            j++;
        } else if (c == '\n') {
            i++;
            j = 0;
        }
    }

    *M = MakeMapMATRIKS(NB, NK, (char*) MapDisplay);

    fclose(MapFile);
}

/* *** Update POSISI atau Wahana pada MATRIKS *** */
void MovePlayer (MATRIKS* M, int difX, int difY) {
    int Xbefore = Xplayer(*M);
    int Ybefore = Yplayer(*M);
    Xplayer(*M) += difX;
    Yplayer(*M) += difY;

    if (Elmt(*M, Yplayer(*M), Xplayer(*M) ) == '#') {
        Xplayer(*M) -= difX;
        Yplayer(*M) -= difY;
        printf("You've hit a wall!\n");
    } else {
        Elmt(*M, Ybefore, Xbefore) = '.';
        Elmt(*M, Yplayer(*M), Xplayer(*M) ) = 'P';
    }
}

void UpdateMatriksWahana(MATRIKS* M) {

}

/* *** Selektor "DUNIA MATRIKS" *** */
/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
    /* Mengirimkan indeks baris terkecil M */
    return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M){
    /* Mengirimkan indeks kolom terkecil M */
    return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M){
    /* Mengirimkan indeks baris terbesar M */
    return NBrsEff(M)-1;
}

indeks GetLastIdxKol (MATRIKS M){
    /* Mengirimkan indeks kolom terbesar M */
    return NKolEff(M)-1;
}

ElType GetElmtDiagonal (MATRIKS M, indeks i){
    /* Mengirimkan elemen M(i,i) */
    return Elmt(M, i, i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS* MHsl){
    /* Melakukan assignment MHsl  MIn */
    *MHsl = MIn;
}

/* ********** KELOMPOK TULIS ********** */ 
void BacaMATRIKS (MATRIKS* M, int NB, int NK){
    /* I.S. IsIdxValid(NB,NK) */ 
    /* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
    /* Proses: Melakukan MakeEmptyMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
    /* Selanjutnya membaca nilai elemen per baris dan kolom */
    /* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
    1 2 3
    4 5 6
    8 9 10 
    */
    MakeEmptyMATRIKS(NB, NK, M);

    for (int i = BrsMin; i <= GetLastIdxBrs(*M); i++){
        for (int j = KolMin; j <= GetLastIdxKol(*M); j++){
            ElType x;
            scanf("%c", &x);

            Elmt(*M, i, j) = x;
        }
    }
}

void TulisMATRIKS (MATRIKS M){
    /* I.S. M terdefinisi */
    /* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
    dipisahkan sebuah spasi, di akhir matriks diberi sebuah newline*/
    /* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10
    */
   for (int i = BrsMin; i <= GetLastIdxBrs(M); i++){
        for (int j = KolMin; j <= GetLastIdxKol(M); j++){
            printf("%c", Elmt(M, i, j) );
            if (j != GetLastIdxKol(M) ) printf(" ");
        }

        printf("\n");
    }

}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
    /* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
    /* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
    /* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
    dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
    boolean same = true;

    if (!EQSize(M1, M2) ) same = false;
    else {
        for (int i = BrsMin; i <= GetLastIdxBrs(M1); i++){
            for (int j = KolMin; j <= GetLastIdxKol(M1); j++){
                if (Elmt(M1, i, j) != Elmt(M2, i, j) ) same = false;
            }
        }
    }    

    return same;
}

boolean EQSize (MATRIKS M1, MATRIKS M2){
    /* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
    /* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
    return (NBrsEff(M1) == NBrsEff(M2) && NKolEff(M1) == NKolEff(M2) );
}