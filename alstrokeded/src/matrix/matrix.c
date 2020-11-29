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

/* *** Selektor "DUNIA MATRIKS" *** */
/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
Mindeks GetFirstIdxBrs (MATRIKS M){
    /* Mengirimkan Mindeks baris terkecil M */
    return BrsMin;
}

Mindeks GetFirstIdxKol (MATRIKS M){
    /* Mengirimkan Mindeks kolom terkecil M */
    return KolMin;
}

Mindeks GetLastIdxBrs (MATRIKS M){
    /* Mengirimkan Mindeks baris terbesar M */
    return NBrsEff(M)-1;
}

Mindeks GetLastIdxKol (MATRIKS M){
    /* Mengirimkan Mindeks kolom terbesar M */
    return NKolEff(M)-1;
}

MElType GetElmtDiagonal (MATRIKS M, Mindeks i){
    /* Mengirimkan elemen M(i,i) */
    return Elmt(M, i, i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS* MHsl){
    /* Melakukan assignment MHsl  MIn */
    *MHsl = MIn;
}

/* ********** KELOMPOK TULIS ********** */ 
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
   printf("+=====+=====+=====+\n\n");
   for (int i = BrsMin; i <= GetLastIdxBrs(M); i++){
        for (int j = KolMin; j <= GetLastIdxKol(M); j++){
            printf("%c", Elmt(M, i, j) );
            if (j != GetLastIdxKol(M) ) printf(" ");
        }

        printf("\n");
    }

    printf("\n+=====+=====+=====+\n");
    printf("Legend:\n");
    printf("A = Antrian\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, >, V = Gerbang\n");
    printf("+=====+=====+=====+\n");
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
    /* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
    /* untuk setiap i,j yang merupakan Mindeks baris dan kolom M1(i,j) = M2(i,j) */
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