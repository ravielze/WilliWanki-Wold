// #include "../word/mesinkata.h"
// #include "../matrix/matrix.h"
// #include "../graph/graph.h"


// int main(){
//     GAME G = createGame();

//     move(&G);
//     return 0;
// }
// int main() {
//     MATRIKS Peta1, Peta2, Peta3, Peta4;

//     InitPeta("../../database/peta/peta1.txt", &Peta1);
//     InitPeta("../../database/peta/peta2.txt", &Peta2);
//     InitPeta("../../database/peta/peta3.txt", &Peta3);
//     InitPeta("../../database/peta/peta4.txt", &Peta4);

//     Graph G = InitGraphPeta(Peta1, Peta2, Peta3, Peta4);

//     printf("Intial Map\n");
//     TulisMATRIKS(InfoMATRIKS(G));
//     while (true) {
//         STARTKATA();
//         while (!EndKata){
//             if (IsKataSama(CKata, CreateKata("W") ) || IsKataSama(CKata, CreateKata("w") ) ) {
//                 MovePlayer(&G, 0, -1);
//             } else if (IsKataSama(CKata, CreateKata("A") ) || IsKataSama(CKata, CreateKata("a") ) ) {
//                 MovePlayer(&G, -1, 0);
//             } else if (IsKataSama(CKata, CreateKata("S") ) || IsKataSama(CKata, CreateKata("s") ) ) {
//                 MovePlayer(&G, 0, 1);
//             } else if (IsKataSama(CKata, CreateKata("D") ) || IsKataSama(CKata, CreateKata("d") ) ) {
//                 MovePlayer(&G, 1, 0);
//             }
            
//             ADVKATA();
//         }

//         TulisMATRIKS(InfoMATRIKS(G));
//     }
//     return 0;
// }