/* *** Definisi ABSTRACT DATA TYPE MATERIAL *** */

#ifndef MATERIAL_H
#define MATERIAL_H

#include "../constant/adt.h"

/*** Selektor ***/
/*
 * Membuat Material dari String. Format: %s %s %s %d %f %d
 */
MATERIAL createMaterial(char* in);

/**
 * Mengubah Materialmenjadi String.
 */
void MaterialtoString(MATERIAL mat, char* result);

// mat = mat2 ga ya? hmmmm
boolean isMaterialEqual(MATERIAL mat, MATERIAL mat2);
#endif