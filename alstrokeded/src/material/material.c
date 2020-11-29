#include "material.h"

/*
 * Membuat Material dari String. Format: %s %s %s %d %f %d
 */
MATERIAL createMaterial(char* nama, char* desc, char* satuan, int jmlh, float harga, int waktu){
    MATERIAL mat;
    strncpy(Nama(mat), nama, 100);
    strncpy(Deskripsi(mat), desc, 255);
    strncpy(Satuan(mat), satuan, 50);
    Punya(mat) = jmlh;
    Waktu(mat) = waktu;
    Harga(mat) = harga;
    return mat;
}

/**
 * Mengubah Material menjadi String.
 */

void MaterialtoString(MATERIAL mat, char* result) {
    char rsl[1000];
    sprintf(rsl, "%s %s %s %d %f %d",
        Nama(mat), Deskripsi(mat), Satuan(mat), Punya(mat),
        Harga(mat), Waktu(mat));
    result = rsl;
}

boolean isMaterialEqual(MATERIAL mat, MATERIAL mat2){
    return(
        Nama(mat) == Nama(mat2) &&
        Deskripsi(mat) == Deskripsi(mat2) &&
        Satuan(mat) == Satuan(mat2) &&
        Waktu(mat) == Waktu(mat2)
    );
}