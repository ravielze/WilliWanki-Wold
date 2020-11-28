#include <stdio.h>
#include <stdlib.h>
#include "storagemanager.h"

manstor createManagerWahana(GAME * game){
    manstor ms;
    Game(ms) = game;

    LIDMaterial(ms) = -1;
    LIDWahana(ms) = -1;

    ARRAYLIST AL, AL2;
    CreateEmptyAL(&AL, 20);
    CreateEmptyAL(&AL2, 20);
    StorageW(ms) = AL;
    StorageM(ms) = AL2;

    MapWahana MapWhn;
    MakeEmptyMapWahana(&MapWhn, 20);
    SMappingW(ms) = MapWhn;
    
    MapMaterial MapMat;
    MakeEmptyMapMaterial(&MapMat, 20);
    SMappingM(ms) = MapMat;

    return ms;
}


void createWahana(manstor * ms, WAHANA whn){
/* Menambahkan wahana ke mapwahana global game */
    MapEntryWahana MEW = CreateMapEWahana(LIDWahana(*ms),whn);
    AddEntryWahana(&(SMappingW(*ms)), MEW);
    LIDWahana(*ms)++;
}


void addWahana(manstor * ms, int id){
/* Menambahkan wahana ke storage JIKA belum ada */
    if(!Search(StorageW(*ms),id)){
        InsertLastAL(&StorageW(*ms),id);
    }
}

void deleteWahana(manstor * ms, int id){
/* Delete wahana dengan id tertentu pada storage JIKA ada */
    int i = SearchIdx(StorageW(*ms),id);
    if(Search(StorageW(*ms), id)){
        DeleteNAL(&StorageW(*ms),i);
    }
}


void createMaterial(manstor * ms, MATERIAL mat){
/* Menambahkan wahana ke mapmaterial global game */
    MapEntryMaterial MEM = CreateMapEMaterial(LIDMaterial(*ms),mat);
    AddEntryMaterial(&(SMappingM(*ms)), MEM);
    LIDMaterial(*ms)++;
}

void addMaterial(manstor * ms, int id){
/* Menambahkan material ke storage JIKA belum ada */
    if(!Search(StorageM(*ms),id)){
        InsertLastAL(&StorageM(*ms),id);
    }
}

void deleteMaterial(manstor * ms, int id){
/* Delete material dengan id tertentu pada storage JIKA ada */
    int i = SearchIdx(StorageM(*ms),id);
    if(Search(StorageM(*ms), id)){
        DeleteNAL(&StorageM(*ms),i);
    if(Search(StorageM(*ms), id)){
        DeleteNAL(&StorageM(*ms),i);
    if(Search(StorageM(*ms), id)){
        DeleteNAL(&StorageM(*ms),i);
    }
}