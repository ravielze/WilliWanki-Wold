/* ADT Graf dengan 4 edge dan vertex sebagai MATRIKS*/
#ifndef graph_H
#define graph_H

#include "../boolean.h"
#include "../matrix/matrix.h"
#include <stdio.h>
#include <stdlib.h>

#define Nil NULL

typedef struct vertex* AdrVertex;
typedef struct vertex {
    MATRIKS InfoMATRIKS;
    AdrVertex Up;
    AdrVertex Left;
    AdrVertex Right;
    AdrVertex Bottom;
} Vertex;
typedef AdrVertex Graph;

#define InfoMATRIKS(P) (P)->InfoMATRIKS
#define Up(P) (P)->Up
#define Left(P) (P)->Left
#define Right(P) (P)->Right
#define Bottom(P) (P)->Bottom

AdrVertex AlokasiVertex (MATRIKS M);
/* Mengalokasi MATRIKS M dengan edge semuanya menunjuk Nil */

Graph InitGraphPeta (MATRIKS M1, MATRIKS M2, MATRIKS M3, MATRIKS M4);
/* Membuat Graf khusus untuk Peta menerima 4 matriks */

void MovePlayer (AdrVertex* V, int difX, int difY);
    /* Mengupdate MATRIKS Map berukuran 11 x 11 dengan posisi Xplayer dan Yplayer diubah */
    /* sisi terluarnya adalah # yaitu pagar, sisi dalamnya adalah . yaitu lahan */

void UpdateMatriksWahana(AdrVertex* V);
    /* Mengupdate MATRIKS Map dengan posisi wahana terbaru */

#endif 