#include "material.h"

/*
 * Membuat Material dari String. Format: %s %s %s %d %f %d %d
 */
MATERIAL createMaterial(char* in);

/**
 * Mengubah Materialmenjadi String.
 */
void MaterialtoString(MATERIAL mat, char* result);

boolean isMaterialEqual(MATERIAL mat, MATERIAL mat2){
    return(
        Nama(mat) == Nama(mat2) &&
        Deskripsi(mat) == Deskripsi(mat2) &&
        Satuan(mat) == Satuan(mat2) &&
        Waktu(mat) == Waktu(mat2)
    );
}