#include <stdio.h>
#include "./game/game.h"
#include "./word/mesinkata.h"

int main(){
    // printf("AAA");
    GAME g = createGame();

    TulisMATRIKS(InfoMATRIKS(Graf(g) ) );
    while (true) {
        printf("Apa yang ingin dilakukan?\n");
        printf("  1. Bangun wahana      : build\n");
        printf("  2. Beli material      : buy\n");
        printf("  3. Upgrade wahana     : upgrade\n");
        printf("  4. Execute stack      : execute\n");
        printf("  5. Undo last action   : undo\n");
        printf("  6. Skip to main phase : main\n\n");
        printf("Masukkan perintah:\n");
        STARTKATA();
        while (!EndKata){
            /* Player Movements */
            if (IsKataSama(CKata, CreateKata("W") ) || IsKataSama(CKata, CreateKata("w") ) ) {
                MovePlayer(&Graf(g), 0, -1);
            } else if (IsKataSama(CKata, CreateKata("A") ) || IsKataSama(CKata, CreateKata("a") ) ) {
                MovePlayer(&Graf(g), -1, 0);
            } else if (IsKataSama(CKata, CreateKata("S") ) || IsKataSama(CKata, CreateKata("s") ) ) {
                MovePlayer(&Graf(g), 0, 1);
            } else if (IsKataSama(CKata, CreateKata("D") ) || IsKataSama(CKata, CreateKata("d") ) ) {
                MovePlayer(&Graf(g), 1, 0);
            } 
            /* Player Action */ 
            else if (IsKataSama(CKata, CreateKata("BUILD"))) {
                buildPush(&g);
            } else if (IsKataSama(CKata, CreateKata("BUY"))) {
                buyMaterialPush(&g);
            } else if (IsKataSama(CKata, CreateKata("SERVE"))) {
                Serve(&g);
            } else if (IsKataSama(CKata, CreateKata("UPGRADE"))) {
                upgradePush(&g);
            } else if (IsKataSama(CKata, CreateKata("EXECUTE"))) {
                ExecutePhase(&g);
            } else if (IsKataSama(CKata, CreateKata("UNDO"))) {
                undo(&g);
            } else if (IsKataSama(CKata, CreateKata("QUIT"))) {
                fclose(pita);
                printf("LOSER!");
                return 0;
            } else if (IsKataSama(CKata, CreateKata("REPAIR"))){
                
            } else if (IsKataSama(CKata, CreateKata("DETAIL"))) {

            } else if (IsKataSama(CKata, CreateKata("OFFICE"))) {

            } else if (IsKataSama(CKata, CreateKata("REPORT"))) {
                
            } else if (IsKataSama(CKata, CreateKata("PREPARE"))) {

            } else if (IsKataSama(CKata, CreateKata("MAIN"))) {
                
            }
            
            ADVKATA();
        }

        TulisMATRIKS(InfoMATRIKS(Graf(g)));
    }

    return 0;
}