/* *** Definisi ABSTRACT DATA TYPE GAME *** */

#ifndef GAME_H
#define GAME_H

#include "../boolean.h"
#include "../plane/point.h"

typedef struct{
    char* Pemain;
    float Money;
    POINT PosisiPlayer;
    // Stack, List, Queue, dan sebagainya
} GAME;

void createGame(GAME * game);

#endif