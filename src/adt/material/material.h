/* *** Definisi ABSTRACT DATA TYPE MATERIAL *** */

#ifndef MATERIAL_H
#define MATERIAL_H

#include "../boolean.h"
#include "../jam/jam.h"

typedef struct{
    char* NamaMaterial;
    char* Deskripsi;
    char* Satuan;
    int   Jumlah;
    float Harga;
    JAM Waktu;
} MATERIAL;

/*** Selektor ***/
#define Nama(X) (X).NamaMaterial
#define Deskripsi(X) (X).Deskripsi
#define Satuan(X) (X).Satuan
#define Harga(X) (X).Harga
#define Waktu(X) (X).Waktu

void createMaterial(MATERIAL * mat);

#endif