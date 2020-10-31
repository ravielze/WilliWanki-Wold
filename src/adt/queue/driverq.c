#include "queuelist.c"

int main(){
    Queue Q;
    ElType x;

    CreateEmpty(&Q);
    Enqueue(&Q,1,4);printf("%d", InfoHead(Q));printf("%d\n", NBElmt(Q));
    Enqueue(&Q,2,3);printf("%d", InfoHead(Q));printf("%d\n", NBElmt(Q));
    Enqueue(&Q,3,6);printf("%d", InfoHead(Q));printf("%d\n", NBElmt(Q));
    Enqueue(&Q,3,1);printf("%d", InfoHead(Q));printf("%d\n", NBElmt(Q));
    Enqueue(&Q,3,1);printf("%d", InfoHead(Q));printf("%d\n", NBElmt(Q));
    Enqueue(&Q,4,0);printf("%d", InfoHead(Q));printf("%d\n\n", NBElmt(Q));

    Dequeue(&Q,&x);printf("%d", InfoHead(Q));printf("%d\n", NBElmt(Q));
    Dequeue(&Q,&x);printf("%d", InfoHead(Q));printf("%d\n", NBElmt(Q));
    Dequeue(&Q,&x);printf("%d", InfoHead(Q));printf("%d\n", NBElmt(Q));
    Dequeue(&Q,&x);printf("%d", InfoHead(Q));printf("%d\n", NBElmt(Q));
    Dequeue(&Q,&x);printf("%d", InfoHead(Q));printf("%d\n", NBElmt(Q));
    Dequeue(&Q,&x);printf("%d", x);printf("%d\n", NBElmt(Q));


}
