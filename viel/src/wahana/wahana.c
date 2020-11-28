#include "wahana.h"
#include <stdio.h>
#include <string.h>

WAHANA createWahana(char* in){
    WAHANA whn;
    char copied[1000];
    strcpy(copied, in);
    sscanf(copied, "%s %s %s %d %d %f %d %d %d %d %d",
        NamaWhn(whn), TipeWhn(whn), DeskripsiWhn(whn), &(KpstsWhn(whn)),
        &(SizeWhn(whn)), &(HargaTiket(whn)), &(RusakGakSih(whn)), &(Absis(LokWhn(whn))), &(Ordinat(LokWhn(whn))),
        &(DurasiWhn(whn)), &(WahanaDasar(whn)));

    return whn;
}

/**
 * Mengubah Wahana menjadi String.
 */
void WahanatoString(WAHANA whn, char* result){
    char rsl[1000];
    sprintf(rsl, "%s %s %s %d %d %f %d %d %d %d %d",
        NamaWhn(whn), TipeWhn(whn), DeskripsiWhn(whn), (KpstsWhn(whn)),
        (SizeWhn(whn)), (HargaTiket(whn)), (RusakGakSih(whn)), (Absis(LokWhn(whn))), (Ordinat(LokWhn(whn))),
        (DurasiWhn(whn)), (WahanaDasar(whn)));
    result = rsl;
}

// Wahananya mau rusak/enggak?
void setRusak(WAHANA* whn, boolean rusakgak){
    RusakGakSih(*whn) = rusakgak;
}

// Apakah nabrak sama wahana laen?
boolean isCollide(WAHANA whn, WAHANA whn2){
    boolean result = (SizeWhn(whn) == SizeWhn(whn2));
    result = result && ((Absis(LokWhn(whn))) == (Absis(LokWhn(whn2))));
    result = result && ((Ordinat(LokWhn(whn))) == (Ordinat(LokWhn(whn2))));
    if (result) return result;

    int sz1 = (SizeWhn(whn)-1)/2;
    int x11 = Absis(LokWhn(whn)) - sz1;
    int y11 = Ordinat(LokWhn(whn)) - sz1;
    int x12 = Absis(LokWhn(whn)) + sz1;
    int y12 = Ordinat(LokWhn(whn)) + sz1;

    int sz2 = (SizeWhn(whn2)-1)/2;
    int x21 = Absis(LokWhn(whn2)) - sz2;
    int y21 = Ordinat(LokWhn(whn2)) - sz2;
    int x22 = Absis(LokWhn(whn2)) + sz2;
    int y22 = Ordinat(LokWhn(whn2)) + sz2;

    return (x11 <= x21 && x21 <= x12 && y11 <= y21 && y21 <= y22)
            || (x11 <= x22 && x22 <= x12 && y11 <= y22 && y22 <= y22);
}

WAHANA copyWahana(WAHANA whn){
    //TODO
}