#include <stdio.h>
#include "./game/game.h"
#include "./word/mesinkata.h"
#include "./word/mesinkar.h"
#include "boolean.h"

void printMenu(GAME g){
    printf("\n+=====++=====+=====++=====+\n");
    printf("|          STATUS         |\n");
    printf( (IsMP(g) ) 
        ?  "|        MAIN PHASE       |\n"
        :  "|    PREPARATION PHASE    |\n");
    printf("|          Day #%d         |\n", CurrDay(g) );
    printf("+=====++=====+=====++=====+\n\n");
    // printf("Player: %s\n", Pemain(g) );
    // printf("Current Time: "); TulisJam(Time(g)); printf("\n");
    // printf("Money: %.2f\n", Money(g) );

    TulisMATRIKS(InfoMATRIKS(Graf(g)));
    
    printf("Player: %s\n", Pemain(g) );
    printf("Money: %.2f\n", Money(g) );

    if (IsMP(g)) {
        printf("Current Time: "); TulisJam(Time(g));
        printf("\nClosing Time: 18.00\n");
        printf("Time Remaining: "); JAM j; MakeJamFromMenit(&j, TimeRemaining(Amanag(g))); TimeRemain(j);
        printf("\nApa yang ingin dilakukan?\n");
        printf("  - Perbaiki wahana     : REPAIR\n");
        printf("  - Lihat detail wahana : DETAIL\n");
        if (isNear(Graf(g) , 'O')) printf("  - Masuk ke office     : OFFICE\n");
        if (isNear(Graf(g) , 'A')) printf("  - Melayani pengunjung : SERVE\n");
        printf("  - Skip to prep phase  : PREPARE\n");
        printf("  - Keluar game         : QUIT\n");
        printf("  - Untuk pergerakan    : w, a, s, d\n");
        printf("Masukkan perintah: ");    
    } else {
        printf("Current Time: 18.00\n");
        printf("Opening Time: 06.00\n");
        printf("Time Remaining: ");
        JAM j; MakeJamFromMenit(&j, TimeRemaining(Amanag(g))); TimeRemain(j);
        printf("\nTotal aksi yang akan dilakukan: %d\n", actionTimes(g));
        printf("Total waktu yang dibutuhkan: "); 
        JAM j2; MakeJamFromMenit(&j2, (720 - TimeRemaining(Amanag(g)))); TimeRemain(j2);
        // Jam j1; MakeJamFromMenit(&j1, TimeRemaining(Amanag(g)))
        printf("\nTotal uang yang dibutuhkan: %.2f\n", MoneyUsed(Amanag(g)));

        printf("Apa yang ingin dilakukan?\n");
        printf("  - Bangun wahana       : BUILD\n");
        printf("  - Beli material       : BUY\n");
        printf("  - Upgrade wahana      : UPGRADE\n");
        printf("  - Execute stack       : EXECUTE\n");
        printf("  - Undo last action    : UNDO\n");
        printf("  - Skip to main phase  : MAIN\n");
        printf("  - Keluar game         : QUIT\n");
        printf("  - Untuk pergerakan    : w, a, s, d\n\n");
        printf("Masukkan perintah: ");
    }
}

int main(){
    // printf("AAA");
    GAME g = createGame();
    boolean p = true;
    printf("Who is your name: ");
    STARTKATA();
    Pemain(g) = CKata.TabKata;
    ADVKATA();
    printMenu(g);
    while (true) {
        STARTKATA();
        while (!EndKata){
            /* Player Movements */
            if (IsKataSama(CKata, CreateKata("W") ) || IsKataSama(CKata, CreateKata("w") ) ) {
                MovePlayer(&Graf(g), 0, -1, &g);
                // if (IsMP(g) ) TickTime(&g, 1);
            } else if (IsKataSama(CKata, CreateKata("A") ) || IsKataSama(CKata, CreateKata("a") ) ) {
                MovePlayer(&Graf(g), -1, 0, &g);
                // if (IsMP(g) ) TickTime(&g, 1, g);
            } else if (IsKataSama(CKata, CreateKata("S") ) || IsKataSama(CKata, CreateKata("s") ) ) {
                MovePlayer(&Graf(g), 0, 1, &g);
                // if (IsMP(g) ) TickTime(&g, 1, g);
            } else if (IsKataSama(CKata, CreateKata("D") ) || IsKataSama(CKata, CreateKata("d") ) ) {
                MovePlayer(&Graf(g), 1, 0, &g);
                // if (IsMP(g) ) TickTime(&g, 1);
            } 
            /* Player Actions */ 
            else if (IsKataSama(CKata, CreateKata("BUILD")) && (!IsMP(g))) {
                p = false;
                buildPush(&g);
            } else if (IsKataSama(CKata, CreateKata("BUY")) && (!IsMP(g))) {
                p = false;
                buyMaterialPush(&g);
            } else if (IsKataSama(CKata, CreateKata("SERVE")) && (IsMP(g))) {
                p = false;
                Serve(&g);
            } else if (IsKataSama(CKata, CreateKata("UPGRADE")) && (!IsMP(g))) {
                p = false;
                upgradePush(&g);
            } else if (IsKataSama(CKata, CreateKata("EXECUTE")) && (!IsMP(g))) {
                ExecutePhase(&g);
            } else if (IsKataSama(CKata, CreateKata("UNDO")) && (!IsMP(g))) {
                p = false;
                undo(&g);
            } else if (IsKataSama(CKata, CreateKata("QUIT"))) {
                printf("DEFEAT THE TUBES DRAGON FIRST!\n");
                return 0;
            } else if (IsKataSama(CKata, CreateKata("REPAIR")) && (IsMP(g))){
                p = false;
                Repair(&g);
            } else if (IsKataSama(CKata, CreateKata("DETAIL")) && (IsMP(g))) {
                p = false;
                detail(&g);
            } else if (IsKataSama(CKata, CreateKata("OFFICE")) && (IsMP(g))) {
                p = false;
                office_detail(&g);
            } else if (IsKataSama(CKata, CreateKata("PREPARE")) && (IsMP(g))) {
                GoToPrepare(&g);
            } else if (IsKataSama(CKata, CreateKata("MAIN")) && (!IsMP(g))) {
                mainphase(&g);
            } else {
                printf("Command tidak ditemukan atau tidak tepat saatnya.");
            }
            ADVKATA();
        }    
        if (p){
            printMenu(g);
        } else {
            p = !p;
        }
    }

    return 0;
}