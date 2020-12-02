/* *** Definisi ABSTRACT DATA TYPE GAME *** */

#ifndef GAME_H
#define GAME_H

#define Nil NULL

// #include "../word/mesinkata.h"
#include "../constant/adt.h"
#include "../point/point.h"
#include "../jam/jam.h"
#include "../queue/queuelist.h"
#include "../wahana/wahana.h"
#include "../map/map.h"
#include "../stack/stack.h"
#include "../graph/graph.h"
#include "../matrix/matrix.h"
#include "storagemanager.h"
#include "actionmanager.h"

GAME createGame();


/*  Build Wahana
    1. Print List Wahana Dasar
    2. Pilih wahana dasar
    3. Cek resource dan uang dan waktu
    4. Push ke stack aksi */
void buildPush(GAME * game);
void buildPop(GAME * game);

/*  Upgrade Wahana
    1. Print Tree Upgrade
    2. Pilih kanan atau kiri
    3. Cek resource dan uang dan waktu
    4. Push ke stack aksi */
void upgradePush(GAME * game);
void upgradePop(GAME * game);

/*  Upgrade Wahana
    1. Print List Material
    2. Pilih material
    3. Cek resource dan uang dan waktu
    4. Push ke stack aksi */
void buyMaterialPush(GAME * game);
void buyMaterialPop(GAME * game);
boolean IsBuildAbleSenpai(WAHANA thefkinwahana,GAME *game);

/* Pop sekali */
void undo(GAME * game);

/* langsung ke main phase dan kosongkan stack */
void mainphase(GAME * game);

/* Main Phase */

/* Generate Pengunjung diawal main phase */
void GeneratePengunjung(GAME * g);

/* InverseStack, terus pop 1 per 1 terus jalanin */
void ExecutePhase(GAME * game);

/* Seperti namanya, melayani pelayanan */
void Serve(GAME * game);

int todonow(Visitor v);

/* Spawn Visitor */
Visitor SpawnVisitor(int id, GAME * g);

/* Menggenerate to do list Visitor */
Stack generateToDo(GAME *g);

/* Force all Visitor to quit if its night time */
void deleteWeaboo(GAME* g);

/* Update the Visitor patience and priority depending on the time they enter/re-enter the queue */
void updateWeaboo(GAME*g);

/* Update the Visitor patience and priority depending on the time they enter/re-enter the queue on Wahana*/
void updateWeabooWahana(GAME*g , WAHANA* whn);

/* Print wahana */
void printAnime(Stack S, GAME* g);

/* Print Visitors with patience */
void printWeaboo(GAME* g);

/* Visitor coming back to queue after the rides */
void getbacktoWeaboo(GAME*g,WAHANA*w);

/* Get wahana dari point */
WAHANA getWahanaFromPoint(POINT P, manstor ms);

/* Repair wahana */
void Repair(GAME *game);

/* Tick Waktu N Menit */
void TickTime(GAME *game , int menit);

/* Go to Preparation Phase */
void GoToPrepare(GAME *game);

/* Office Detail */
void office_detail(GAME *game);

/* Detail di samping wahana */
void detail(GAME *game);

time_t t;

void initRNG();
void printWahanaOffice (WAHANA w,GAME*g);

#endif