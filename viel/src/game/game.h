/* *** Definisi ABSTRACT DATA TYPE GAME *** */

#ifndef GAME_H
#define GAME_H

#define Nil NULL

#include "../boolean.h"
#include "../plane/point.h"
#include "../jam/jam.h"
#include "../queue/queuelist.h"
#include "../wahana/wahana.h"
#include "../map/map.h"
#include "../stack/stack.h"
#include "../graph/graph.h"
#include "../matrix/matrix.h"
#include "storagemanager.h"
#include "actionmanager.h"
//TODO apa yang belum dipikirkan? linked list taruh mana, queue per wahana ditaruh dimana
typedef struct{
    char* Pemain;
    float Money;
    JAM Time;

    int currentDay;
    int executionTimes;
    int actionTimes;
    boolean isMainPhase; // penanda phase

    manstor StorageManager; // ini untuk semua hal yang dimiliki player
    manact ActionManager; // ini untuk semua aksi yang akan dilakukan

    Queue GameQueue; // ini untuk antrian
    Graph graphGame;
} GAME;

#define GameQueue(G) (G).GameQueue
#define Pemain(G) (G).Pemain
#define Money(G) (G).Money
#define Time(G) (G).Time
#define CurrDay(G) (G).currentDay
#define ExecTimes(G) (G).executionTimes
#define IsMP(G) (G).isMainPhase
#define Amanag(G) (G).ActionManager
#define Smanag(G) (G).StorageManager
#define actionTimes(G) (G).actionTimes
#define Graph(G) (G).graphGame
#define QueueG(G) (G).Queue 


GAME createGame();
/* Preparation Phase */

void action(GAME * game);

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
void generatePengunjung(GAME * game); //TODO dipikir, ADT Pengunjung???
/*  Upgrade Wahana
    1. Print Tree Upgrade
    2. Pilih kanan atau kiri
    3. Cek resource dan uang dan waktu
    4. Push ke stack aksi */
void upgrade(GAME * game);

/*  Upgrade Wahana
    1. Print List Material
    2. Pilih material
    3. Cek resource dan uang dan waktu
    4. Push ke stack aksi */
void buyMaterial(GAME * game);

/* Pop sekali */
void undo(GAME * game);

/* langsung ke main phase dan kosongkan stack */
void mainphase(GAME * game);

/* InverseStack, terus pop 1 per 1 terus jalanin */
void ExecutePhase(GAME * game);

/* Seperti namanya, melayani pelayanan */
void Serve(GAME * game);

#endif