#include "material.h"

/*
 * Membuat Material dari String. Format: %s %s %s %d %f %d
 */
MATERIAL createMaterial(char* in){
    MATERIAL mat;
    char copied[1000];
    strcpy(copied, in);
    sscanf(copied, "%s %s %s %d %f %d",
        Nama(mat), Deskripsi(mat), Satuan(mat), &(Punya(mat)),
        &(Harga(mat)), &(Waktu(mat)));
    /* Bingung kenapa nggak pake ampersand ;-; */
    return mat;
}

/**
 * Mengubah Materialmenjadi String.
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