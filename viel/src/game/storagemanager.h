#ifndef SM_H
#define SM_H
#include "../map/map.h"
#include "../array/array.h"
#include "../array/arraymat.h"
#include "game.h"
/*
0 | Wahana A
1 | Wahana B
2 | Wahana C
*/
typedef struct{
    MapWahana ListWahana; //Map untuk listing Wahana yang tersedia
    int LastIDWahana;
    MapMaterial ListMaterial; //Map Untuk listing Material yang
    int LastIDMaterial;
    ARRAYLIST StorageWahana; // Array List ID Wahana yang dipunyai
    ARRAYLISTMAT StorageMaterial; // Array List semua material yang tersedia
    GAME * game;
} MANAGER_STORAGE;

/* SELEKTOR */
#define manstor MANAGER_STORAGE
#define SMappingW(X) (X).ListWahana
#define SMappingM(X) (X).ListMaterial
#define LIDWahana(X) (X).LastIDWahana
#define LIDMaterial(X) (X).LastIDMaterial
#define StorageW(X) (X).StorageWahana
#define StorageM(X) (X).StorageMaterial
#define Game(X) (X).game

manstor createManagerStorage(GAME * game);

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

//TODO dapetin wahana dengan idnya      V output
void getWahana(manstor * ms, int id, WAHANA * whn);

#endif