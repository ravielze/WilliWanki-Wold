/* *** Definisi ABSTRACT DATA TYPE WAHANA *** */

#ifndef WAHANA_H
#define WAHANA_H

#include "../boolean.h"
#include "../jam/jam.h"

typedef struct{
    char* NamaWahana;
    int KapasitasWahana;
    float Harga;
    char* Deskripsi;
    JAM Durasi;
} WAHANA;

void createWahana(WAHANA * whn);

#endif