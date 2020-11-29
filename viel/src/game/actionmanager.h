#ifndef AM_H
#define AM_H
#include "../map/map.h"
#include "../stack/stack.h"
#include "game.h"

typedef struct{
    MapWahana DataWahana;
    MapMaterial DataMaterial;
    Stack StackAksi;
    float MoneyUsed;
    int timeRemaining; //dalam menit
} MANAGER_ACTION;

/* SELEKTOR */
#define manact MANAGER_ACTION
#define AMappingW(X) (X).DataWahana
#define AMappingM(X) (X).DataMaterial
#define StackAksi(X) (X).StackAksi
#define MoneyUsed(X) (X).MoneyUsed
#define TimeRemaining(X) (X).timeRemaining

void createManagerAction(GAME * game);

// dapetin wahana dengan idnya V output
void getWahanaa(manact * ma, int id, WAHANA * whn);

void resetTimeRemaining(manact * ma);
#endif