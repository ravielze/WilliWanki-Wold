#ifndef AM_H
#define AM_H
#include "../map/map.h"
#include "../stack/stack.h"
#include "game.h"

typedef struct{
    MapArea DataArea;
    MapWahana DataWahana;
    MapMaterial DataMaterial;
    Stack StackAksi;
} MANAGER_ACTION;

/* SELEKTOR */
#define manstor MANAGER_STORAGE
#define MappingW(X) X.ListWahana
#define MappingM(X) X.ListMaterial
#define StorageW(X) X.StorageWahana
#define StorageM(X) X.StorageMaterial
#define Game(X) X.game

#endif