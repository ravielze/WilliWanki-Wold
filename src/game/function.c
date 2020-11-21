#include "../adt/plane/point.h"
#include "../adt/queue/queuelist.h"
#include "../adt/stack/stack.h"
#include "../adt/wahana/wahana.h"
#include "../adt/game/game.h"
#include "../adt/jam/jam.h"
#include "../adt/linkedlist/list.h"
#include "../adt/map/map.h"
#include "../adt/word/mesinkata.c"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
GAME game;

/* MOVE */
void move(char dir){
    /* Basic Move, belum handle nabrak */
    if (dir == 'w'){
        Ordinat(PlayerLocation(game)) += 1;
    } else if (dir == 'a'){
        Absis(PlayerLocation(game)) += 1;
    } else if (dir == 's'){
        Ordinat(PlayerLocation(game)) -= 1;
    } else if (dir == 'd'){
        Absis(PlayerLocation(game)) -= 1;
    }
}

/* BUILD */
void build(WAHANA W){
/* Prekondisi, ga bokek, tempatnya ada */
    if (Money(game) < Harga(W)){
        printf("Modal dikit lah bos\n"); //material harusnya juga(?)
    }
}

/* UPGRADE */
void upgrade (WAHANA W) {
/* Prekondisi, money money yes, material yes */
    if (Money(game) < price(W)){
        printf("money plz\n");
    // Kurang kalo material ga cukup '^'
    } else {
        // int id = rand() %10000;
        // while(IsEntryWahana(ListIDWahana(game),id)) id = rand() %10000;
        Push(&CmdStack(game), 'u');
    }
}

/* UNDO */
void undo(){
    /* Basic Undo */
    WAHANA dump;
    Pop(&CmdStack(game),&dump);
}

/* BUY */
void buy(int N, int IDMtr, MapMaterial MM){
    buy_print(MM);
    /* update var global uang, kepemilikan material, time remaining */
}

void buy_print(MapMaterial MM){
    printf("Ingin membeli apa?\n");
    printf("List :\n");
    /* Print list material */
    for (int i=0; i < NEff(MM); i++){
        printf("   - %s", Nama(value(MapEntry(MM)[i])));
    }

}

/* SERVE */
void serve(WAHANA *W){
    int X, Ndeq;
    DequeueN(&Antrian(*W), &X, Kapasitas(*W), &Ndeq);
    game.Money += Harga(*W) * Ndeq;
    game.CurrTime = NextNDetik(game.CurrTime, JamToDetik(DurasiMain(*W)));
}

/* REPAIR */
void repair(WAHANA *wahana){
    /* Basic repair wahana */
    if (wahana->rusak){
        wahana->rusak = false;
    }
}

/* OFFICE */
void office() {
    printf("// Memasuki office mode //\n");
    printf("Masukkan perintah (Details / Report / Exit):");
    /* bingung inputnya gmn */
    /* string = ??? */
    while (IsKataSama(CreateKata('string'), CreateKata("Exit"))) {
        if (IsKataSama(CreateKata('string'), CreateKata("Details"))) {
            details();
        } else if (IsKataSama(CreateKata('string'), CreateKata("Report"))) {
            report();
        } else {
            /* Invalid command(?) */
        }
        /* Move to next command */
    }
    /* Current command = Exit */
}

void details () {
    /* Print list wahana */
    /* Pilih wahana yang mau ditampilkan detailnya */
}

void report () {
    /* Print list wahana */
    /* Pilih wahana yang mau ditampilkan reportnya */
}

/* EXECUTE */
void execute() {
    /* Basic game execution*/
    Execution(game) = true;
}

/* ToDo to Inprogress*/
