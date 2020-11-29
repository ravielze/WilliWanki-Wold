// 13519114
#include "graph.h"

int main(){
    MATRIKS Peta1, Peta2, Peta3, Peta4;

    InitPeta("./database/peta/peta1.txt", &Peta1);
    InitPeta("./database/peta/peta2.txt", &Peta2);
    InitPeta("./database/peta/peta3.txt", &Peta3);
    InitPeta("./database/peta/peta4.txt", &Peta4);

    Graph G = InitGraphPeta(Peta1, Peta2, Peta3, Peta4);
    printf("Intial Map\n");
    TulisMATRIKS(InfoMATRIKS(G) );

    printf("If w is pressed\n");
    MovePlayer(&G, 0, -1);

    prinf("Is a Wall near player?\n");
    printf( (IsNear(G, '#') ) ? "Yes\n" : "No\n");

    printf("Where is the player now?\n");
    TulisPoint(getPlayer(G) );

    return 0;
}