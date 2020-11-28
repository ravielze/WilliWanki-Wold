#include "../game/game.h"
#include "../queue/queuelist.h"
#include "../stack/stack.h"
#include "../wahana/wahana.h"

#ifndef VISITOR_H
#define VISITOR_H

typedef struct{
    Stack todo;
    int patience;
} visitor;

/*** Selektor ***/
#define todo(P) (P).todo
#define patience(P) (P).patience

/* Ambil wahana yang ingin dinaiki (paling atas stack) */
WAHANA todonow(visitor v, GAME *g);

/* Create visitor */
visitor CreateVisitor(Stack todo,int patience);

/* Menggenerate to do list visitor */
Stack generateToDo(GAME *game);

//Menggenerate pelanggan
void generateWeaboo(GAME*g);

//BAN pelannggan kalo uda malem
void deleteWeaboo();

// Update state pelanngan setelah dipanggil
// Tujuannya untuk menguji kesabaran biar makin marah
void updateWeaboo();

// Pelanggan kembali ke antrian
void getbacktoWeaboo();

// Pelanggan diusir ke antrian wahana (setelah di serve)
void gotoAnimeConcert();

#endif