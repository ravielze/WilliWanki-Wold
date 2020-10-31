#include "queuelist.h"

void Alokasi(address *P, ElType X, int Prio){
    *P = (address)malloc(1*sizeof(Node));
    if (P!=Nil){
        Info(*P) = X;
        Next(*P) = Nil;
        Prio(*P) = Prio;
    }
}

void Dealokasi(address P){
    free(P);
}

boolean IsEmpty (Queue Q){
    return (Head(Q) == Nil);
}

int NBElmt (Queue Q){
    if (IsEmpty(Q)){
        return 0;
    }
    else{
        address P = Head(Q);
        int i;
        for (i=0; Next(P)!=Nil; i++){
            P = Next(P);
        }
        return i+1;
    }
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q){
    Head(*Q) = Nil;
}

/* *** Primitif Add/Delete *** */
void Enqueue (Queue * Q, ElType X, int Prio){
    address P;
    Alokasi(&P,X,Prio);
    int PrioHead;

    if (!IsEmpty(*Q)){
        PrioHead = Prio(Head(*Q));
    }

    if ((PrioHead > Prio)||(IsEmpty(*Q))){
        Next(P) = Head(*Q);
        Head(*Q) = P;
    }
    else{
        address Prev = Nil;
        address After = Head(*Q);
        int PrioAfter = Prio(After);
        while ((Prio >= PrioAfter) && (Next(After) != Nil)){
            After = Next(After);

            PrioAfter = Prio(After);

            if (Prev == Nil){
                Prev = Head(*Q);
            }
            else{
                Prev = Next(Prev);
            }
        }

        if (Next(After) == Nil){
            if (Prio >= Prio(After)){
                Next(After) = P;
            }
            else{
                Next(P) = After;
                if (Prev != Nil){
                    Next(Prev) = P;
                }
            }
        }
        else{
            Next(P) = After;
            if (Prev != Nil){
                Next(Prev) = P;
            }
        }
    }
}

void Dequeue (Queue * Q, ElType * X){

    address P;
    *X = InfoHead(*Q);
    P = Head(*Q);
    if (Next(Head(*Q)) != Nil){
        Head(*Q) = Next(Head(*Q));
        Next(P) = Nil;
    }
    else{
        Head(*Q) = Nil;
    }
    Dealokasi(P);
}
