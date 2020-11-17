#include "../adt/queue/queuelist.h"

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
    boolean rusak;
    JAM Durasi;
    Queue Antrian;
} WAHANA;

/*** Selektor ***/
#define NamaWahana(W) (W)->NamaWahana
#define KapasitasWahana(W) (W).KapasitasWahana
#define Harga(W) (W).Harga
#define Deskripsi(W) (W)->Deskripsi
#define Durasi(W) (W).Durasi
#define Antrian(W) (W).Antrian

void CreateWahana(WAHANA *W);

#endif