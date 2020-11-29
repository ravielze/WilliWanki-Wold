#include "queuelist.h"

int main() {
    Queue ki;
    CreateEmptyQ(&ki);

    /* IS EMPTY */
    printf("IS EMPTY\n");
    if (IsEmptyQ(ki)) printf("Queue kosong\n");
    int enbe = NBElmtQ(ki);
    printf("\nJUMLAH ELEMEN\n");
    printf("Jumlah elemen dalam Queue adalah %d\n", enbe);
    
    return 0;
}

/* ********* Prototype ********* */
void AlokasiQ(qaddress *P, ElTypeQ X, int Prio);
void DealokasiQ(qaddress P);
boolean IsEmptyQ (Queue Q);
int NBElmtQ (Queue Q);

/* *** Kreator *** */
void CreateEmptyQ (Queue * Q);

/* *** Primitif Add/Delete *** */
void Enqueue (Queue * Q, ElTypeQ X, int Prio);
void Dequeue (Queue * Q, ElTypeQ * X);
void DequeueN (Queue * Q, ElTypeQ * X, int N);