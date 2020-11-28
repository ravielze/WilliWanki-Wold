#ifndef queuelist_H
#define queuelist_H

#include "../boolean.h"
#include "../visitor/visitor.h"
#include <stdlib.h>
#include <stdio.h>

#define Nil NULL


typedef visitor ElType;
typedef struct qNode *qaddress;
typedef struct qNode {  ElType Info;
                        qaddress Next;
                        int Prio;
                     } queueNode;
typedef struct { qaddress HEAD;
               } Queue;

/* ********* AKSES (Selektor) ********* */
#define Head(Q) (Q).HEAD
#define InfoHead(Q) (Q).HEAD->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info
#define Prio(P) (P)->Prio

/* ********* Prototype ********* */
void AlokasiQ(address *P, ElType X, int Prio);
void DealokasiQ(address P);
boolean IsEmptyQ (Queue Q);
boolean IsFullQ (Queue Q);
int NBElmtQ (Queue Q);

/* *** Kreator *** */
void CreateEmptyQ (Queue * Q);

/* *** Primitif Add/Delete *** */
void Enqueue (Queue * Q, ElType X, int Prio);
void Dequeue (Queue * Q, ElType * X);
void DequeueN (Queue * Q, ElType * X, int N, int *Ndequeued);

#endif