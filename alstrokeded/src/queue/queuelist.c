#include "queuelist.h"

void AlokasiQ(qaddress *P, ElTypeQ X, int Prio){
    *P = (qaddress) malloc (1*sizeof(queueNode));
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
    if (IsEmptyQ(Q)){
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
void Enqueue (Queue * Q, ElTypeQ X, int NewPrio){
    qaddress P; // untuk alokasi
    AlokasiQ(&P,X,NewPrio);

    if (IsEmptyQ(*Q)){
        Head(*Q) = P;
    } 
    else {
        if (Prio(Head(*Q)) <= NewPrio){// Prio Head sama dengan NewPrio maka NewPrio taruh paling depan
            Next(P) = Head(*Q);
            Head(*Q) = P;
        } else { 
            qaddress A = Head(*Q); 
            // Travesal hingga Prio(Next(A)) > NewPrio
            while (Next(A) != Nil && (Prio(Next(A)) > NewPrio)) A = Next(A);
            // Berdasarkan hasil travesal akan dimasukan
            // Jika next == nil maka dimasukkan paling akhir queue
            if (Next(A) == Nil) Next(A) = P;
            else { // Jika dimasukkan ditengah (tapi di paling depan prio)
                Next(P) = Next(A);
                Next(A) = P;
            }
        }
    }
}

void Dequeue (Queue * Q, ElTypeQ * X){
    qaddress P;
    if (!IsEmptyQ(*Q)){
        *X = InfoHead(*Q);
        P = Head(*Q);
        if (Next(Head(*Q)) != Nil){
            Head(*Q) = Next(Head(*Q));
            Next(P) = Nil;
        }
        else{
            Head(*Q) = Nil;
        }
        DealokasiQ(P);
    }
}

/* Prekondisi : N pasti index dari Q */
void DequeueN (Queue * Q, ElTypeQ * X, int N){
    if (N == 0){
        *X = Info(Head(*Q));
        Head(*Q) = Next(Head(*Q));
    } else {
        int temp = 0;
        qaddress A = Head(*Q);
        while (A != Nil && temp < N-1) {
            A = Next(A);
            temp++;
        }

        *X = Info(Next(A));
        if (Next(A) != Nil){
            /* Didapat address sebelum index N */
             /* Visitor di index ke-N */
            Next(A) = Next(Next(A)); /* mengubah Next(A) menjadi Next(Next(A)) */
        } else {
            Next(A) = Nil;
        }
    }
}