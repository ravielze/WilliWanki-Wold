/* *** Definisi ABSTRACT DATA TYPE MATERIAL *** */

#ifndef MATERIAL_H
#define MATERIAL_H

#include "../boolean.h"
#include "../jam/jam.h"

typedef struct{
    char* NamaMaterial;
    char* Deskripsi;
    char* Satuan;
    float Harga;
    JAM waktu;
} MATERIAL;

void createMaterial(MATERIAL * mat);

#endif