#include <stdio.h>
#include "visitor.h"
#include "../game/game.h"
#include "../stack/stack.h"
/* Ambil wahana yang ingin dinaiki (paling atas stack) */
WAHANA todonow(visitor v, GAME *g){
    MapWahana CMap = SMappingW(Smanag(*g));
    if (!IsStackEmpty(todo(v))){
        int idwahana = IDAksi(InfoTop(todo(v)));
        return MWGetWahana(CMap,idwahana);
    }
    return MWGetWahana(CMap,-1);
}


/* Spawn visitor */
visitor SpawnVisitor(int p, GAME * g){
    visitor v;
    todo(v) = generateToDo(g);
    patience(v) = p;
    entertime(v) = Time(*g);
    return v;
}

/* Menggenerate to do list visitor */
Stack generateToDo(GAME *g){
    Stack S;

    int todocap = 10; /* jumlah wahana yang akan dinaiki */

    ARRAYLIST ownedrides = StorageW(Smanag(*g));

    int totaltodo = rand() % todocap;
    int i = 1;
    int selectedid; Aksi selectedAksi;
    while (i < Neff(ownedrides) && i < todocap){
        selectedid = rand() % (Neff(ownedrides));
        if (!isIDInStack(S,selectedid)) {
            selectedAksi = createAksi(ItemOf(ownedrides, selectedid),'r');
            PushAksi(&S,selectedAksi);
        }
    }
    return S;
}

/* Generate visitors queue (untuk initialization) */
void generateWeaboo(Queue *Q, GAME *g) {
    visitor genV;
    for (int i = 0; i < 5; i++){
        genV = SpawnVisitor(0,g);
        Enqueue(Q,genV,0); /* Put visitor in queue */
    }
}

/* Force all visitor to quit if its night time */
void deleteWeaboo() {
    ;
}


/* Update the visitor patience and priority depending on the time they enter/re-enter the queue */
void updateWeaboo(GAME*g) {
    JAM time_now = Time(*g);
    Queue antrian = Queue(*g);
    int jlh_weaboo = NBElmtQ(antrian);

    for (int i = 0; i < jlh_weaboo ; i++){
        
    }
    
}

/* Visitor coming back to queue after the rides */
void getbacktoWeaboo(GAME*g) {
    ;
}


// Pelanggan diusir ke SMappingW(Smanag(*g)) (setelah di serve)
void gotoAnimeConcert() {
    ;
}

//NOTE jgn lupa kasih fungsi kalau tiba2 wahana rusak, atau emang udah ada subtitusinya?