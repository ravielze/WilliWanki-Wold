#include "../adt/word/mesinkata.h"
#include <stdio.h>

int main() {
    STARTKATA();
    while (!EndKata){
        if (IsKataSama(CKata, CreateKata("W"))){
            printf("MAJU");
        } else if (IsKataSama(CKata, CreateKata("S"))){
            printf("MUNDUR");
        } else if (IsKataSama(CKata, CreateKata("TOPHER"))){
            printf("APA");
        } else{
            printf("HAH");
        }
        ADVKATA();
    }



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

    /* SERVE - bije is working on this*/

    /* REPAIR */
    /* OFFICE */
    /* PREPARE */

    /** Dalem Office **/
    /* Lihat detail laporan (DETAIL) */
    /* Lihat laporan wahana */


    return 0;
}