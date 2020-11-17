#include "../adt/plane/point.h"
#include "../adt/queue/queuelist.h"
#include "../adt/wahana/wahana.h"
#include "../adt/game/game.h"
#include "../adt/jam/jam.h"

/* BROOO 

typedef struct{
    char* NamaWahana;
    int KapasitasWahana;
    float Harga;
    char* Deskripsi;
    boolean rusak;
    JAM Durasi;
    Queue Antrian;
    // Stack, List, Queue, dan sebagainya
} GAME;
#define NamaWahana(W) W->NamaWahana
#define KapasitasWahana(W) W.KapasitasWahana
#define Harga(W) W.Harga
#define Deskripsi(W) W->Deskripsi
#define Durasi(W) W.Durasi
#define Antrian(W) W.Antrian
*/

GAME game;

/* MOVE */
void move(char dir){
    /* Basic Move, belum handle nabrak */
    if (dir == 'w'){
        Ordinat(PlayerLocation(game)) += 1;
    } else if (dir == 'a'){
        Absis(PlayerLocation(game)) += 1;
    } else if (dir == 's'){
        Ordinat(PlayerLocation(game)) -= 1;
    } else if (dir == 'd'){
        Absis(PlayerLocation(game)) -= 1;
    }
}

/* BUILD */
void build(WAHANA W){
    push(CmdStack(game),W);
    BuildTime(G)
}

/* UNDO */
void undo();

/* BUY */
void buy(){
    buy_print();
    
}

void buy_print(){
    printf("Ingin membeli apa?\n");
    printf("List :\n");
}

/* SERVE */
void serve(WAHANA *W){
    int X;
    Dequeue(&Antrian(*W), &X);
    game.Money += Harga(*W);
    game.CurrTime = NextNDetik(game.CurrTime, JamToDetik(Durasi(*W)));
}

/* REPAIR */
void repair(WAHANA *wahana){
    /* Basic repair wahana */
    if (wahana->rusak){
        wahana->rusak = false;
    }
}

/* OFFICE */
void office() {
    printf("// Memasuki office mode //\n");
    printf("Masukkan perintah (Details / Report / Exit):");
}

/* EXECUTE */
void execute() {
    Execution(game) = true;
}

