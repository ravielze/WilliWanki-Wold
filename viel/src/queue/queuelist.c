#include "queuelist.h"

void AlokasiQ(qaddress *P, ElType X, int Prio){
    *P = (qaddress)malloc(1*sizeof(Node));
    if (P!=Nil){
        Info(*P) = X;
        Next(*P) = Nil;
        Prio(*P) = Prio;
    }
}

void DealokasiQ(qaddress P){
    free(P);
}

boolean IsEmptyQ (Queue Q){
    return (Head(Q) == Nil);
}

int NBElmtQ (Queue Q){
    if (IsEmpty(Q)){
        return 0;
    }
    else{
        qaddress P = Head(Q);
        int i;
        for (i=0; Next(P)!=Nil; i++){
            P = Next(P);
        }
        return i+1;
    }
}

/* *** Kreator *** */
void CreateEmptyQ (Queue * Q){
    Head(*Q) = Nil;
}

/* *** Primitif Add/Delete *** */
void Enqueue (Queue * Q, ElType X, int Prio){
    qaddress P;
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
        qaddress Prev = Nil;
        qaddress After = Head(*Q);
        while ((Prio >= Prio(After)) && (Next(After) != Nil)){
            After = Next(After);

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

    qaddress P;
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

void DequeueN (Queue * Q, ElType * X, int N, int *Ndequeued){
    int temp = N;
    while ((!IsEmpty(*Q)) && (temp != 0)){
        qaddress P;
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

        Ndequeued++;
        temp--;
    }
    
}
