#include <stdio.h>
#include "visitor.h"
#include "../game/game.h"
/* Ambil wahana yang ingin dinaiki (paling atas stack) */

WAHANA todonow(visitor v, GAME *g){
    if (!IsStackEmpty(todo(v)))){
        MapWahana CMap = SMappingW(Smanag(*g));
        int idwahana = IDAksi(InfoTop(todo(v)));
        return MWGetWahana(CMap,idwahana);
    }
    return Nil;
}


/* Create visitor */
visitor CreateVisitor(Stack todo,int patience);

/* Menggenerate to do list visitor */
Stack generateToDo(GAME *g){
    ARRAYLIST listwahanayangada = StorageW(Smanag(*g));
}

//Menggenerate pelanggan
void generateWeaboo() {
;
}

//BAN pelannggan kalo uda malem
void deleteWeaboo() {
;
}

// Update state pelanngan setelah dipanggil
// Tujuannya untuk menguji kesabaran biar makin marah
void updateWeaboo() {
;
}

// Pelanggan kembali ke antrian
void getbacktoWeaboo() {
;
}


// Pelanggan diusir ke SMappingW(Smanag(*g))ahana (setelah di serve)
void gotoAnimeConcert() {
    ;
}

//NOTE jgn lupa kasih fungsi kalau tiba2 wahana rusak, atau emang udah ada subtitusinya?