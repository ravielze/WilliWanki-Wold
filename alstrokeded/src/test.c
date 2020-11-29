//make test

#include <stdio.h>
#include "./game/game.h"
#include "./word/mesinkata.h"
#include "./word/mesinkar.h"
#include "./game/storagemanager.h"
#include "boolean.h"

void printpilih(){
    printf("Apa yang ingin dilakukan?\n");
    printf("  1. Bangun wahana      : build\n");
    printf("  2. Beli material      : buy\n");
    printf("  3. Upgrade wahana     : upgrade\n");
    printf("  4. Execute stack      : execute\n");
    printf("  5. Undo last action   : undo\n");
    printf("  6. Skip to main phase : main\n");
    printf("  7. Untuk pergerakan   : w, a, s, d\n\n");
    printf("Masukkan perintah:\n");
}

void printStats(GAME g){
    printf("\n+=====+=====+=====+\n");
    printf("|      STATUS     |\n");
    printf("|      Day #%d     |\n", CurrDay(g) );
    printf("+=====+=====+=====+\n\n");
    printf("Player: %s\n", Pemain(g) );
    printf("Time Remaining: %d\n", TimeRemaining(Amanag(g) ) );
    printf("Money: %.2f\n", Money(g) );
}

int main(){
    // printf("AAA");
    GAME g = createGame();
    boolean p = true;
    


    MATERIAL mat = createMaterial("Air", "Elemen_dasar", "galon", 100, 15, 1);
    ScreateMaterial(&(Smanag(g)), mat);

    TulisMATRIKS(InfoMATRIKS(Graf(g)));
    printpilih();
    while (true) {
        STARTKATA();
        while (!EndKata){
            /* Player Movements */
            if (IsKataSama(CKata, CreateKata("W") ) || IsKataSama(CKata, CreateKata("w") ) ) {
                MovePlayer(&Graf(g), 0, -1);
                // if (IsMP(g) ) 
            } else if (IsKataSama(CKata, CreateKata("A") ) || IsKataSama(CKata, CreateKata("a") ) ) {
                MovePlayer(&Graf(g), -1, 0);
            } else if (IsKataSama(CKata, CreateKata("S") ) || IsKataSama(CKata, CreateKata("s") ) ) {
                MovePlayer(&Graf(g), 0, 1);
            } else if (IsKataSama(CKata, CreateKata("D") ) || IsKataSama(CKata, CreateKata("d") ) ) {
                MovePlayer(&Graf(g), 1, 0);
            } 
            /* Player Actions */ 
            else if (IsKataSama(CKata, CreateKata("BUILD"))) {
                p = false;
                buildPush(&g);
            } else if (IsKataSama(CKata, CreateKata("BUY"))) {
                p = false;
                buyMaterialPush(&g);
            } else if (IsKataSama(CKata, CreateKata("SERVE"))) {
                p = false;
                Serve(&g);
            } else if (IsKataSama(CKata, CreateKata("UPGRADE"))) {
                p = false;
                upgradePush(&g);
            } else if (IsKataSama(CKata, CreateKata("EXECUTE"))) {
                p = false;
                ExecutePhase(&g);
            } else if (IsKataSama(CKata, CreateKata("UNDO"))) {
                p = false;
                undo(&g);
            } else if (IsKataSama(CKata, CreateKata("QUIT"))) {
                printf("DEFEAT THE TUBES DRAGON FIRST!\n");
                return 0;
            } else if (IsKataSama(CKata, CreateKata("REPAIR"))){
                p = false;
                //REPAIR
            } else if (IsKataSama(CKata, CreateKata("DETAIL"))) {
                p = false;
                //REPAIR
            } else if (IsKataSama(CKata, CreateKata("OFFICE"))) {
                p = false;
                //REPAIR
            } else if (IsKataSama(CKata, CreateKata("REPORT"))) {
                p = false;
                //REPAIR
            } else if (IsKataSama(CKata, CreateKata("PREPARE"))) {
                p = false;
                //REPAIR
            } else if (IsKataSama(CKata, CreateKata("MAIN"))) {
                p = false;
                //REPAIR
            }
            ADVKATA();
        }
        if (p){
            printStats(g);
            TulisMATRIKS(InfoMATRIKS(Graf(g)));
            printpilih();
        } else {
            p = !p;
        }
    }

    return 0;
}