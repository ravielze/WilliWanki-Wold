#include <stdio.h>
#include "actionmanager.h"

void createManagerAction(GAME * game) {
    manact ma;
    MapWahana dw;
    MakeEmptyMapWahana(&dw, 10);
    MapMaterial dm;
    MakeEmptyMapMaterial(&dm, 10);
    Stack sa;
    MakeStack(&sa);
    float mu = 0.0;
    int tr = 720;

    AMappingW(ma) = dw;
    AMappingM(ma) = dm;
    StackAksi(ma) = sa;
    MoneyUsed(ma) = mu;
    TimeRemaining(ma) = tr;

    Amanag(*game) = ma;
}

void getWahanaa(manact * ma, int id, WAHANA * whn) {
    // dapetin wahana dengan idnya V output
    MapWahana list = AMappingW(*ma);
    *whn = MWGetWahana(list, id);    
}