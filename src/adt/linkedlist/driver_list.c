#include "stdlib.h"
#include "stdio.h"
#include "list.h"
#include "list.c"


void main(){
    List L;
    MakeEmpty(&L);
    InsertFirst(&L,100);
    InsertFirst(&L,99);
    InsertLast(&L,101);
    DeleteFirst(&L);
    BacaList(L);
}