#include "tree.h"

int main(){
    BinTree anakstrokedead = Tree(0, AlokasiT(-1), AlokasiT(-2));
    BinTree anakstrokedead2 = Tree(9, Nil, AlokasiT(5));
    BinTree keluargastrokedead = Tree(999, anakstrokedead2, anakstrokedead);

    PrintTree(keluargastrokedead, 2);
    printf("Daun: %d\n", NbDaun(keluargastrokedead));
    printf("Tinggi: %d\n", TinggiT(keluargastrokedead));
}