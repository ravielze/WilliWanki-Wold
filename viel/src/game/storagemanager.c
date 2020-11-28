#include <stdio.h>
#include <stdlib.h>
#include "storagemanager.h"

manstor createManagerWahana(GAME * game){
    manstor ms;
    Game(ms) = game;

    LIDMaterial(ms) = -1;
    LIDWahana(ms) = -1;

    ARRAYLIST AL;
    CreateEmptyAL(&AL, 20);
    StorageW(ms) = AL;

    MapWahana MapWhn;
    MakeEmptyMapWahana(&MapWhn, 20);
    SMappingW(ms) = MapWhn;
    
    MapMaterial MapMat;
    MakeEmptyMapMaterial(&MapMat, 20);
    SMappingM(ms) = MapMat;

    return ms;
}

void initStorageManager(char* wahanafilename, char* materialfilename, char* treefilename, manstor* ms){

// ngebaca dari file
// WAHANA w = create....
// screatewahana
    static int retval;
    int N;
    boolean nowWahana = true;
    FILE* WahanaFile = fopen(wahanafilename, "r");
    FILE* MaterialFile = fopen(materialfilename, "r");
    FILE* TreeFile = fopen(treefilename, "r");

    retval = fscanf(MaterialFile, "%d\n", &N);
    while(N--){
        char strInput[1000];
        retval = fscanf(MaterialFile, "%s\n", &strInput);

        MATERIAL mat = createMaterial(strInput);
        ScreateMaterial(ms, mat);
    }


    retval = fscanf(WahanaFile, "%d\n", &N);
    WAHANA whn;
    while(N--){
        char strInput[1000];
        retval = fscanf(WahanaFile, "%s\n", &strInput);

        if (nowWahana){
            whn = createWahana(strInput);
            ScreateWahana(ms, whn);
        } else {
            MATERIAL mat = createMaterial(strInput);
            Bahan(whn) = mat;
        }

        nowWahana = !nowWahana;
    }

   retval = fscanf(TreeFile, "%d\n", &N);
   while(N--){
        int from, to;
        char LorR;

        retval = fscanf("%d %c %d\n", &from, &LorR, &to);
        if (LorR == 'L') {
            WAHANA whn;
            getWahana(ms, from, &whn);

            if (UpgradeTree(whn) != Nil){
                Left(UpgradeTree(whn)) = AlokasiT(to); 
            } else {
                BinTree T = Tree(from, AlokasiT(to), Nil);
                UpgradeTree(whn) = T;
            }
        } else {
            WAHANA whn;
            getWahana(ms, from, &whn);

            if (UpgradeTree(whn) != Nil){
                Right(UpgradeTree(whn)) = AlokasiT(to); 
            } else {
                BinTree T = Tree(from, Nil, AlokasiT(to) );
                UpgradeTree(whn) = T;
            }
        }
   }
}


void ScreateWahana(manstor * ms, WAHANA whn){
/* Menambahkan wahana ke mapwahana global game */
    LIDWahana(*ms)++;
    MapEntryWahana MEW = CreateMapEWahana(LIDWahana(*ms),whn);
    AddEntryWahana(&(SMappingW(*ms)), MEW);
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


void ScreateMaterial(manstor * ms, MATERIAL mat){
/* Menambahkan wahana ke mapmaterial global game */
    LIDMaterial(*ms)++;
    MapEntryMaterial MEM = CreateMapEMaterial(LIDMaterial(*ms),mat);
    AddEntryMaterial(&(SMappingM(*ms)), MEM);
}

void getWahana(manstor* ms, int id, WAHANA* whn){
    
}