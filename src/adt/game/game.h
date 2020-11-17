/* *** Definisi ABSTRACT DATA TYPE GAME *** */

#ifndef GAME_H
#define GAME_H

#include "../boolean.h"
#include "../plane/point.h"
#include "../jam/jam.h"
#include "../stack/stack.h"

typedef struct{
    char* Pemain;
    float Money;
    POINT PosisiPlayer;
    JAM CurrTime;
    JAM BuildTime;
    boolean ExecDay;
    Stack CmdStack;
    // Stack, List, Queue, dan sebagainya
} GAME;

#define PlayerLocation(G) G.PosisiPlayer
#define CurrentTime(G) G.CurrTime
#define BuildTime(G) G.BuildTime
#define Money(G) G.Money
#define Execution(G) G.ExecDay
#define CmdStack(G) G.CmdStack

void createGame(GAME * game);

#endif