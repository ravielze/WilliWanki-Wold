#ifndef queuelist_H
#define queuelist_H

#include "../constant/adt.h"

/* ********* Prototype ********* */
void AlokasiQ(qaddress *P, ElTypeQ X, int Prio);
void DealokasiQ(qaddress P);
boolean IsEmptyQ (Queue Q);
boolean IsFullQ (Queue Q);
int NBElmtQ (Queue Q);

/* *** Kreator *** */
void CreateEmptyQ (Queue * Q);

/* *** Primitif Add/Delete *** */
void Enqueue (Queue * Q, ElTypeQ X, int Prio);
void Dequeue (Queue * Q, ElTypeQ * X);
void DequeueN (Queue * Q, ElTypeQ * X, int N, int *Ndequeued);

#endif
