#ifndef AM_H
#define AM_H
#include "../map/map.h"
#include "../stack/stack.h"
#include "game.h"

typedef struct{
    MapWahana DataWahana;
    MapMaterial DataMaterial; //TODO dipikir gmn cr masukin materialnya
    Stack StackAksi;
    float MoneyUsed;
} MANAGER_ACTION;

/* SELEKTOR */
#define manact MANAGER_ACTION
#define AMappingW(X) (X).DataWahana
#define AMappingM(X) (X).DataMaterial
#define StackAksi(X) (X).StackAksi
#define MoneyUsed(X) (X).MoneyUsed

#endif