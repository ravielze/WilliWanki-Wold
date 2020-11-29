#include <stdio.h>
#include "visitor.h"
#include "../game/game.h"
#include "../queue/queuelist.h"
#include "../stack/stack.h"
#include "../wahana/wahana.h"
#include "../array/array.h"
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
visitor SpawnVisitor(int id, GAME * g){
    visitor v;
    int startpatience = 10; /* EDIT THIS TO CHANGE START PATIENCE, 0 PATIENCE MEANS VISITOR LEAVE */
    visitorid(v) = id;
    todo(v) = generateToDo(g);
    patience(v) = startpatience;
    entertime(v) = Time(*g);
    inrides(v) = false;
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
void generateWeaboo(GAME *g) {
    visitor genV;
    int maxvisitor = 5; /* CHANGE THIS TO CHANGE NUMBER OF VISITOR */
    int thevisitor = rand() & maxvisitor;

    int id;
    for (int i = 0; i < thevisitor; i++){
        id = thevisitor-i; /* Create visitor id */
        genV = SpawnVisitor(id,g);
        Enqueue(&GameQueue(*g),genV,0); /* Put visitor in queue with 0 priority at start */
    }
}

/* Force all visitor to quit if its night time */
void deleteWeaboo() {
    ;
}


/* Visitor dequeued and then queued with increased prio but inrides become true*/
/* */
void weabooGoToConcert(GAME*g) {
    qaddress A = Head(GameQueue(*g));
    while (A != Nil && inrides(Info(A))) A = Next(A);//Traversal untill found somone not in rides or till end of queue
    if (A != Nil) { /* Found visitor foremost visitor that is not in rides */
        /* Get used data */
        ElTypeQ fmv; visitor V = fmv;
        int cprio = Prio(A);

        WAHANA wantodothiswahana = todonow(Info(A),g); /* TO DO : GATAU QUEUE WAHANA DIMANA, JADI GATAU MAU DIAPAIN WAKAWKWAKKAW */
        /* Delete from todo list */
        Aksi dump;
        PopAksi(&todo(V),&dump); 
        /* Re enter queue with prio + 1 */
        if (IsStackEmpty(todo(V))) { /* Visitor has completed his/her to do list */
            Dequeue(A,&fmv);
        }
        else { /* Visitor has not yet completed his/her to do list */
            Dequeue(A,&fmv); 
            Enqueue(&GameQueue(*g),fmv,cprio+1);
        }
    }
}

/* Update the visitor patience and priority depending on the time they enter/re-enter the queue */
void updateWeaboo(GAME*g) {
    JAM time_now = Time(*g);
    Queue antrian = GameQueue(*g);
    int jlh_weaboo = NBElmtQ(antrian);

    qaddress P = Head(antrian);
    for (int i = 0; i < jlh_weaboo ; i++){
        visitor currV = Info(P);
        JAM time_visitor = entertime(currV);
        long durasi = Durasi(time_visitor , time_now);

        // Waktu update kesabaran : 10 menit
        long waktu_update_kesabaran = 10;
        
        if (durasi > waktu_update_kesabaran){
            int kesabaran_turun = durasi % waktu_update_kesabaran;
            patience(currV) -= kesabaran_turun;

            // TODO : JAM tiap visitor di update tiap kesabaran naik (?)
            int menit_hilang = kesabaran_turun * waktu_update_kesabaran;
            entertime(currV) = NextNMenit(time_visitor,menit_hilang);
        }
    }
}

// anjir dikeri toper
/******************************** >><< AFK REHAT DLO *******************************************/
/* Visitor coming back to queue after the rides */
void getbacktoWeaboo(GAME*g) {
    /* TO DO : GET VISITOR FROM WAHANA, CURRENTLY UNKNOW SINCE WAHANA DOESNT HAVE QUEUE */
    int vid; /* somehow get visitor id */

    qaddress A = Head(GameQueue(*g));
    while (A != Nil && visitorid(Info(A)) != vid) A = Next(A); /* Travesal until visitorid(A) is vid */
    if (visitorid(Info(A)) == vid) inrides(Info(A)) = false; /* visitor has yet finished rides he/she want */
    /* else : visitor is not found in main queue (has finished all rides he/she wanted) */
}

//NOTE jgn lupa kasih fungsi kalau tiba2 wahana rusak, atau emang udah ada subtitusinya?