/* *** Definisi ABSTRACT DATA TYPE GAME *** */

#ifndef GAME_H
#define GAME_H

#include "../boolean.h"

typedef struct{
    char* Pemain;
    float Money;
} GAME;

void createGame(GAME * game);

#endif