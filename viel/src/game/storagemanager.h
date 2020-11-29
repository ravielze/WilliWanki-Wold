#ifndef SM_H
#define SM_H
#include "../map/map.h"
#include "../array/array.h"
#include "../array/arraymat.h"
#include "../constant/adt.h"
#include "../material/material.h"
#include "game.h"
/*
0 | Wahana A
1 | Wahana B
2 | Wahana C
*/

void createManagerStorage(GAME * game);

void initStorageManager(char* wahanafilename, char* materialfilename, char* treefilename, manstor* ms);

/* Menambahkan wahana ke wahana yang tersedia */
void ScreateWahana(manstor * ms, WAHANA whn);
/* Menambahkan wahana ke storage */
void addWahana(manstor * ms, int id);
void deleteWahana(manstor * ms, int id);


void ScreateMaterial(manstor * ms, MATERIAL mat);
/* Menambahkan material ke storage */
void addMaterial(manstor * ms, int id);
void deleteMaterial(manstor * ms, int id);

// dapetin wahana dengan idnya V output
void getWahana(manstor * ms, int id, WAHANA * whn);

#endif