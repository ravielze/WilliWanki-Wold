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
#define manact MANAGER_ACTION
#define AMappingA(X) (X).DataArea
#define AMappingW(X) (X).DataWahana
#define AMappingM(X) (X).DataMaterial
#define StackAksi(X) (X).StackAksi

void execute(manact * ma);

#endif