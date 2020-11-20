#include "../adt/word/mesinkata.h"
#include "../adt/matrix/matrix.h"
#include <stdio.h>

int main() {
    MATRIKS Peta1 = MakeMapMATRIKS();

    printf("Intial Map\n");
    TulisMATRIKS(Peta1);
    while (true) {
        STARTKATA();
        while (!EndKata){
            if (IsKataSama(CKata, CreateKata("W") ) || IsKataSama(CKata, CreateKata("w") ) ) {
                MovePlayer(&Peta1, 0, -1);
            } else if (IsKataSama(CKata, CreateKata("A") ) || IsKataSama(CKata, CreateKata("a") ) ) {
                MovePlayer(&Peta1, -1, 0);
            } else if (IsKataSama(CKata, CreateKata("S") ) || IsKataSama(CKata, CreateKata("s") ) ) {
                MovePlayer(&Peta1, 0, 1);
            } else if (IsKataSama(CKata, CreateKata("D") ) || IsKataSama(CKata, CreateKata("d") ) ) {
                MovePlayer(&Peta1, 1, 0);
            }
            
            ADVKATA();
        }

        TulisMATRIKS(Peta1);
    }
    
    return 0;
}