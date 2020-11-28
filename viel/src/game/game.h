/* *** Definisi ABSTRACT DATA TYPE GAME *** */

#ifndef GAME_H
#define GAME_H

#define Nil NULL

#include "../boolean.h"
#include "../plane/point.h"
#include "../jam/jam.h"
#include "../queue/queuelist.h"
#include "storagemanager.h"
#include "actionmanager.h"

typedef struct{
    char* Pemain;
    float Money;

    JAM Time;
    int currentDay;
    int executionTimes;
    int actionTimes;
    boolean isMainPhase;

    manstor StorageManager;
    manact ActionManager;

    antrian SEMOGABANYAKPELANGGAN;
} GAME;

#define Pemain(G) (G).Pemain
#define Money(G) (G).Money
#define PosisiPlayer(G) (G).PosisiPlayer
#define Time(G) (G).Time
#define CurrDay(G) (G).currentDay
#define ExecTimes(G) (G).executionTimes
#define IsMP(G) (G).isMainPhase
#define Amanag(G) (G).ActionManager
#define Smanag(G) (G).StorageManager
#define actionTimes(G) (G).actionTimes


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
void buyMaterial(GAME * game, int jumlah, MATERIAL* mat);

/* Pop sekali */
void undo(GAME * game);

/* langsung ke main phase dan kosongkan stack */
void mainphase(GAME * game);

/* InverseStack, terus pop 1 per 1 terus jalanin */
void execute(GAME * game);

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

#endif