#ifndef VISITOR_H
#define VISITOR_H
#include "../constant/adt.h"

#include "../map/map.h"
#include "../wahana/wahana.h"

#include "../stack/stack.h"
#include "../jam/jam.h"

/* Ambil wahana yang ingin dinaiki (paling atas stack) */
int todonow(Visitor v);

/* Spawn Visitor */
Visitor SpawnVisitor(int patience, GAME * g);

/* Menggenerate to do list Visitor */
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

// Mengantrikan Visitor pada antrian
void waittobuyConcert(Visitor v, int prio);

#endif