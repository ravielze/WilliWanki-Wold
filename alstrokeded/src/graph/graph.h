/* ADT Graf dengan 4 edge dan vertex sebagai MATRIKS*/
#ifndef graph_H
#define graph_H

#include "../constant/adt.h"
#include "../matrix/matrix.h"
#include "../point/point.h"
#include "../game/game.h"

AdrVertex AlokasiVertex (MATRIKS M);
/* Mengalokasi MATRIKS M dengan edge semuanya menunjuk Nil */

Graph InitGraphPeta (MATRIKS M1, MATRIKS M2, MATRIKS M3, MATRIKS M4);
/* Membuat Graf khusus untuk Peta menerima 4 matriks */

void MovePlayer (AdrVertex* V, int difX, int difY, GAME* g);
    /* Mengupdate MATRIKS Map berukuran 11 x 11 dengan posisi Xplayer dan Yplayer diubah */
    /* sisi terluarnya adalah # yaitu pagar, sisi dalamnya adalah . yaitu lahan */

void UpdateMatriksWahana(AdrVertex* V, WAHANA W);
    /* Mengupdate MATRIKS Map dengan posisi wahana terbaru */

void DeleteMatriksWahana(AdrVertex* V, WAHANA W);

boolean isCollideWahanaBuilding(AdrVertex V, WAHANA W);
    /* Mengecek apakah suatu wahana menabrak tembok atau tidak */

boolean isNear(AdrVertex V, char X);
    /* Mengecek apakah player berdeketan dengan suatu building seperti W, A, O */

POINT getPlayer(AdrVertex V);
#endif 