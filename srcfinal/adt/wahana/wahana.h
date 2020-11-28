#include "../queue/queuelist.h"

/* *** Definisi ABSTRACT DATA TYPE WAHANA *** */

#ifndef WAHANA_H
#define WAHANA_H

#include "../boolean.h"
#include "../jam/jam.h"

typedef struct Whn* addressWahana;
typedef struct Whn{
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
#define DurasiBangun(W) (W).DurasiBangun
#define DurasiMain(W) (W).DurasiMain
#define Antrian(W) (W).Antrian

/* Return jumlah material yang dibutuhin yeet */
int GetWahanaMaterial (WAHANA w, char* Nama);
/* Return waktunya bangunnya yey */
JAM GetWahanaTime (WAHANA w, char* Nama); 
/* Build wahanana YEYEYEYEYEYEYEYEYEYEYEEY */
void buildWahanana(WAHANA *w,);
#endif