#include "../game/game.h"
#include "../queue/queuelist.h"
#include "../stack/stack.h"
#include "../wahana/wahana.h"
#include "../array/array.h"
#include "../jam/jam.h"

#ifndef VISITOR_H
#define VISITOR_H

typedef struct{
    int visitorid;
    Stack todo;
    int patience;
    JAM enterqueue;
    boolean inrides;
} visitor;

/*** Selektor ***/
#define todo(V) (V).todo
#define inrides(V) (V).inrides
#define patience(V) (V).patience
#define visitorid(V) (V).visitorid
#define entertime(V) (V).enterqueue

/* Ambil wahana yang ingin dinaiki (paling atas stack) */
WAHANA todonow(visitor v, GAME *g);

/* Spawn Visitor */
visitor SpawnVisitor(int patience, GAME * g);

/* Menggenerate to do list visitor */
Stack generateToDo(GAME *game);

//Menggenerate pelanggan
void generateWeaboo(GAME* g);

//BAN pelannggan kalo uda malem
void deleteWeaboo();

// Update state pelanngan setelah dipanggil
// Tujuannya untuk menguji kesabaran biar makin marah
void updateWeaboo();

// Pelanggan kembali ke antrian
void getbacktoWeaboo();

// Pelanggan diusir ke antrian wahana (setelah di serve)
void gotoAnimeConcert();

// Mengantrikan visitor pada antrian
void waittobuyConcert(visitor v, int prio);


#endif