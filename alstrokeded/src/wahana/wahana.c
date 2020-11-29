#include "wahana.h"

WAHANA createWahana(char* namawhn, char* tipewhn, char* deskripsi, int kpstswhn, int sizewhn, float hargatiket, boolean rusakgasi, int durasi, boolean iswahanadasar,float hargabuild, int vertex, int durasibuild){
    WAHANA whn;
    
    strncpy(NamaWhn(whn), namawhn, 100);
    strncpy(TipeWhn(whn), tipewhn, 100);
    strncpy(DeskripsiWhn(whn), deskripsi, 255);
    KpstsWhn(whn) = kpstswhn;
    SizeWhn(whn) = sizewhn;
    HargaTiket(whn) = hargatiket;
    RusakGakSih(whn) = rusakgasi;
    Absis(LokWhn(whn)) = -1;
    Ordinat(LokWhn(whn)) = -1;
    DurasiWhn(whn) = durasi;
    WahanaDasar(whn) = iswahanadasar;
    HargaBuild(whn) = hargabuild;
    InVertex(whn) = vertex;
    DurasiBuild(whn) = durasibuild;
    PelangganCounter(whn) = 0;

    CreateEmptyQ(&(QueueWahana(whn)));
    MakeEmptyLL(&(History(whn)));
    return whn;
}

/**
 * Mengubah Wahana menjadi String. 
 */
void WahanatoString(WAHANA whn, char* result) {
    char rsl[1000];
    sprintf(rsl, "%s %s %s %d %d %f %d %d %d %d %d %f %d %d %d",
        NamaWhn(whn), TipeWhn(whn), DeskripsiWhn(whn), (KpstsWhn(whn)),
        (SizeWhn(whn)), (HargaTiket(whn)), (RusakGakSih(whn)), (Absis(LokWhn(whn))), (Ordinat(LokWhn(whn))),
        (DurasiWhn(whn)), (WahanaDasar(whn)), (HargaBuild(whn)), (InVertex(whn)), (DurasiBuild(whn)), PelangganCounter(whn));
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
    result = result && ((InVertex(whn) == (InVertex(whn2))));
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

    return (((x11 <= x21 && x21 <= x12 && y11 <= y21 && y21 <= y12)
            || (x11 <= x22 && x22 <= x12 && y11 <= y22 && y22 <= y12)) && (InVertex(whn) == InVertex(whn2)));
}

boolean isWahanaEqual(WAHANA whn1, WAHANA whn2){
    return (
        InVertex(whn1) == InVertex(whn2) &&
        NamaWhn(whn1) == NamaWhn(whn2) &&
        TipeWhn(whn1) == TipeWhn(whn2) &&
        DeskripsiWhn(whn1) == DeskripsiWhn(whn2) &&
        KpstsWhn(whn1) == KpstsWhn(whn2) &&
        SizeWhn(whn1) == SizeWhn(whn2) &&
        RusakGakSih(whn1) == RusakGakSih(whn2) &&
        PEQ(LokWhn(whn1), LokWhn(whn2)) &&
        DurasiWhn(whn1) == DurasiWhn(whn2) &&
        WahanaDasar(whn1) == WahanaDasar(whn2) &&
        isMaterialEqual(Bahan(whn1), Bahan(whn2)) &&
        isTreeEqual(UpgradeTree(whn1), UpgradeTree(whn2))
    );
}

boolean isNearWahana(POINT P, WAHANA whn){
    boolean IsNear = false;
    int startI = Ordinat(LokWhn(whn) ) - SizeWhn(whn)/2;
    int endI = Ordinat(LokWhn(whn) ) + SizeWhn(whn)/2;
    int startJ = Absis(LokWhn(whn) ) - SizeWhn(whn)/2;
    int endJ = Absis(LokWhn(whn) ) + SizeWhn(whn)/2;

    for (int i = startI; (i <= endI) && !IsNear; i++) {
        for (int j = startJ; (j <= endJ) && !IsNear; j++) {
           if ( (Absis(P) + 1 == j && Ordinat(P) == i )
            || ( Absis(P) - 1 == j && Ordinat(P) == i )
            || ( Absis(P) == j && Ordinat(P) + 1 == i )
            || ( Absis(P) == j && Ordinat(P) - 1 == i ) ) IsNear = true;
        }
    }

    return IsNear;
}


/* Enqueue visitor to rides with always 0 priority */
void enqueueWahana(WAHANA*w,Visitor v){
    Enqueue(&QueueWahana(*w),v,0); 
}

/* Dequeue visitor from rides */
int dequeueWahana(WAHANA*w){
    Visitor v;
    Dequeue(&QueueWahana(*w),&v);
    return visitorid(v);
}