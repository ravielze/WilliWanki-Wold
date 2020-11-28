/* *** Definisi ABSTRACT DATA TYPE MATERIAL *** */

#ifndef MATERIAL_H
#define MATERIAL_H

#include "../boolean.h"
#include "../jam/jam.h"

typedef struct Mtrl{
    //Untuk kepemilikan/pembelian
    char NamaMaterial[100];
    char Deskripsi[255];
    char Satuan[50];
    int   Jumlah;

    //Untuk penjualan
    float Harga;
    int WaktuBeli;
} MATERIAL;

/*** Selektor ***/
#define Nama(X) (X).NamaMaterial
#define Deskripsi(X) (X).Deskripsi
#define Satuan(X) (X).Satuan
#define Harga(X) (X).Harga
#define Waktu(X) (X).WaktuBeli
#define Punya(X) (X).Jumlah
/*
 * Membuat Material dari String. Format: %s %s %s %d %f %d %d
 */
MATERIAL createMaterial(char* in);

/**
 * Mengubah Materialmenjadi String.
 */
void MaterialtoString(MATERIAL mat, char* result);

// mat = mat2 ga ya? hmmmm
boolean isMaterialEqual(MATERIAL mat, MATERIAL mat2);
//TODO
#endif