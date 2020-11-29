/* *** Definisi ABSTRACT DATA TYPE WAHANA *** */

#ifndef WAHANA_H
#define WAHANA_H

#include "../constant/adt.h"
#include "../queue/queuelist.h"
#include "../point/point.h"
#include "../tree/tree.h"
#include "../material/material.h"
#include "../linkedlist/list.h"

WAHANA createWahana(char* namawhn, char* tipewhn, char* deskripsi, int kpstswhn, int sizewhn, float hargatiket, boolean rusakgasi, int durasi, boolean iswahanadasar,float hargabuild, int vertex, int durasibuild);

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