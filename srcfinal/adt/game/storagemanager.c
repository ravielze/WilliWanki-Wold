#include <stdio.h>
#include <stdlib.h>
#include "storagemanager.h"

manstor createManagerWahana(GAME * game){
    manstor ms;
    Game(ms) = game;

    ARRAYLIST AL, AL2;
    CreateEmptyAL(&AL, 20);
    CreateEmptyAL(&AL2, 20);
    StorageW(ms) = AL;
    StorageM(ms) = AL2;

    MapWahana MapWhn;
    MakeEmptyMapWahana(&MapWhn, 20);
    MappingW(ms) = MapWhn;
    
    MapMaterial MapMat;
    MakeEmptyMapMaterial(&MapMat, 20);
    MappingM(ms) = MapMat;
}