#include "../adt/word/mesinkata.h"
#include "../adt/word/mesinkar.h"
#include <stdio.h>
#include <time.h>

long long randInt(long X){
    // Random dari [0,X)
    time_t t = time(NULL);
    time_t t2 = time(NULL);
    t %= X;
    long long A = (41+(t*37))%X;
    long long B = (23+(t*101))%X;
    return (A^B);
}

int main() {
    while (true){
        STARTKATA();
        while (!EndKata){
            if (IsKataSama(CKata, CreateKata("W"))){
                printf("MAJU");
            } else if (IsKataSama(CKata, CreateKata("S"))){
                printf("MUNDUR");
            } else if (IsKataSama(CKata, CreateKata("TOPHER"))){
                printf("APA");
            } else if (IsKataSama(CKata, CreateKata("exit"))){
                fclose(pita);
                return 0;
            } else{
                printf("%lld", randInt(100));
            }
            ADVKATA();
            printf("\n");
        }
    }
    return 0;



    /* NEW GAME */
    /* EXIT */

    /* PREPARATION PHASE */
    /* BUILD */
    /* UPGRADE */
    /* BUY */
    /* UNDO */
    /* EXECUTE */


    /*** MAIN PHASE ***/
    /* Keterangan main phase day ke-n */

    /** Prints **/
    /* Print map */
    /* Print Legend */
    /* Print data name, money, current time, closing time, time remaining */
    /* Print currency */
    
    /** Luar Office **/
    /* MOVE */

    /* SERVE*/

    /* REPAIR */
    /* OFFICE */
    /* PREPARE */

    /** Dalem Office **/
    /* Lihat detail laporan (DETAIL) */
    /* Lihat laporan wahana */


    return 0;
}