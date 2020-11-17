#include "../adt/queue/queuelist.h"

/* *** Definisi ABSTRACT DATA TYPE WAHANA *** */

#ifndef WAHANA_H
#define WAHANA_H

#include "../boolean.h"
#include "../jam/jam.h"
typedef struct{
    /* Info Wahana */
    char* NamaWahana;
    int KapasitasWahana;
    float Harga;
    int MaterialDibutuhkan;
    char* Deskripsi;
    boolean rusak;
    
    /* Waktu */
    JAM DurasiMain;
    JAM DurasiBangun;
    /* Queue */
    Queue Antrian;
} WAHANA;

/*** Selektor ***/
#define NamaWahana(W) (W).NamaWahana
#define KapasitasWahana(W) (W).KapasitasWahana
#define Harga(W) (W).Harga
#define Deskripsi(W) (W).Deskripsi
#define DurasiMain(W) (W).DurasiMain
#define DurasiMain(W) (W).DurasiMain
#define Antrian(W) (W).Antrian

void CreateWahana(WAHANA *W);

#endif