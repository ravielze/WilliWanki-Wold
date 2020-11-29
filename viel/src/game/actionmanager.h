#ifndef AM_H
#define AM_H
#include "../constant/adt.h"
#include "../map/map.h"
#include "game.h"

void createManagerAction(GAME * game);

// dapetin wahana dengan idnya V output
void getWahanaa(manact * ma, int id, WAHANA * whn);

void resetTimeRemaining(manact * ma);
#endif