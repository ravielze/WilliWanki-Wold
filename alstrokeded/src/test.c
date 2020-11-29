#include <stdio.h>
#include "./game/game.h"
#include "./word/mesinkata.h"
//make test
int main(){
    GAME game = createGame();

    manstor Manstor = Smanag(game);
    MapWahana MW = SMappingW(Manstor);
    int neffMW = NEff(MW);
    WAHANA* whnlist = MWListWahana(MW);

    // Print list wahana tersedia
    printf("Ingin membangun apa?\n");
    printf("List wahana tersedia : \n");

    WAHANA select[neffMW];
    for (int i=0 ; i < neffMW; i++){
        WAHANA currwhn = whnlist[i];
        if (WahanaDasar(currwhn)){
            select[i] = currwhn;
            printf("%d. ", (i+1));
            printf("%s \n", NamaWhn(currwhn));
        }
    }    
    
    // Terima input wahana apa yang dibangun
    int selectuser;
    scanf("%d", &selectuser);
    selectuser--;
    WAHANA whn_selected = select[selectuser];

    printf("%f" , HargaTiket(whn_selected));

    return 0;
}