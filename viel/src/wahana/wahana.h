/* *** Definisi ABSTRACT DATA TYPE WAHANA *** */

#ifndef WAHANA_H
#define WAHANA_H

#include "../boolean.h"
#include "../jam/jam.h"
#include "../point/point.h"
#include "../tree/tree.h"
#include "../material/material.h"

typedef struct Whn{
    char nama[100];
    char tipewahana[100];
    char deskripsi[255];

    int kapasitas;
    int ukuran; //Harus ganjil dan >= 1
    float hargatiket;
    boolean rusak;

    POINT lokasi;
    int durasi;
    boolean isDasar;
    float hargaBuild; //TODO masukin ke wahana.c

    BinTree uptree;
    MATERIAL bahan;
} WAHANA;

/*** Selektor ***/
#define NamaWhn(W) (W).nama
#define TipeWhn(W) (W).tipewahana
#define DeskripsiWhn(W) (W).deskripsi
#define KpstsWhn(W) (W).kapasitas
#define SizeWhn(W) (W).ukuran
#define HargaTiket(W) (W).hargatiket
#define RusakGakSih(W) (W).rusak
#define LokWhn(W) (W).lokasi
#define DurasiWhn(W) (W).durasi
#define WahanaDasar(W) (W).isDasar
#define Bahan(W) (W).bahan
#define UpgradeTree(W) (W).uptree
#define HargaBuild(W) (W).hargaBuild

/*
 * Membuat Wahana dari String. Format: %s %s %s %d %d %f %d %d %d %d %d
 */
WAHANA createWahana(char* in);

/**
 * Mengubah Wahana menjadi String.
 */
void WahanatoString(WAHANA whn, char* result);

// Wahananya mau rusak/enggak?
void setRusak(WAHANA* whn, boolean rusakgak);

// Apakah nabrak sama wahana laen?
boolean isCollide(WAHANA whn, WAHANA whn2);

#endif