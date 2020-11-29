// 13519114
#include "matrix.h"

int main(){
    char mapDisplay[5][5] = {
        {'#', '#', '#', '#', '#'},
        {'#', '.', '.', 'P', '#'},
        {'#', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#'} };

    MATRIKS M = MakeMapMATRIKS(5, 5, mapDisplay);

    return 0;
}