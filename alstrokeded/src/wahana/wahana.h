/* *** Definisi ABSTRACT DATA TYPE WAHANA *** */

#ifndef WAHANA_H
#define WAHANA_H

#include "../constant/adt.h"

/*
 * Membuat Wahana dari String. Format: %s %s %s %d %d %f %d %d %d %d %d %f %d
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

boolean isWahanaEqual(WAHANA whn1, WAHANA whn2);

boolean isNearWahana(POINT P, WAHANA whn);

void enqueueWahana(WAHANA*w,Visitor v);

/* Return visitor id */
int dequeueWahana(WAHANA*w);

#endif