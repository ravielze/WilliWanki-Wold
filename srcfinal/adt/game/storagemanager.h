#ifndef SM_H
#define SM_H
#include "../map/map.h"
#include "../array/array.h"
#include "game.h"

typedef struct{
    MapWahana ListWahana; //Map untuk listing Wahana yang tersedia
    int LastIDWahana;
    MapMaterial ListMaterial; //Map Untuk listing Material yang
    int LastIDMaterial;
    ARRAYLIST StorageWahana; // Array List ID Wahana yang dipunyai
    ARRAYLIST StorageMaterial; // Array List ID Material yang dipunyai
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

/* Menambahkan wahana ke wahana yang tersedia */
void createWahana(manstor * ms, WAHANA whn);
/* Menambahkan wahana ke storage */
void addWahana(manstor * ms, int id);
void deleteWahana(manstor * ms, int id);


void createMaterial(manstor * ms, MATERIAL mat);
/* Menambahkan material ke storage */
void addMaterial(manstor * ms, int id);
void deleteMaterial(manstor * ms, int id);

#endif