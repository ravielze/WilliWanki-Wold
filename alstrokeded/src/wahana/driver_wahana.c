#include "wahana.h"

// unused driver, too many 

int main() {
    // WAHANA createWahana(char* namawhn, char* tipewhn, char* deskripsi, int kpstswhn, int sizewhn, float hargatiket, boolean rusakgasi, int durasi, boolean iswahanadasar,float hargabuild, int vertex, int durasibuild);
    WAHANA W = createWahana("A", "roller_coaster", "gk", 1, 1, 3.5, 6, 1, 8, 9.5, 10, 11);

    // void WahanatoString(WAHANA whn, char* result);
    char string[100];
    WahanatoString(W, string);
    // A  roller_coaster gk 1  1  3.5 6  1  8  -1 -1 9.5 10 11 0
    // %s %s             %s %d %d %f  %d %d %d %d %d %f  %d %d %d
    
    // void setRusak(WAHANA* whn, boolean rusakgak);
    if (!RusakGakSih(W)) {
        printf("Wahana ini tidak rusak, ");
    }

    setRusak(&W, true);

    if (RusakGakSih(W)) {
        printf("tapi sekarang rusak.\n");
    }

    // boolean isCollide(WAHANA whn, WAHANA whn2);
    WAHANA W2 = createWahana("A", "roller_coaster", "gk", 1, 1, 3.5, 6, 1, 8, 9.5, 10, 11);
    if (isCollide(W, W2)) {
        printf("COLLIDE\n\n");
    }

    // boolean isWahanaEqual(WAHANA whn1, WAHANA whn2);
    if (isWahanaEqual(W, W2)) {
        printf("EQUAL\n\n");
    }

    // boolean isNearWahana(POINT P, WAHANA whn);
    POINT P;
    MakePoint(&P, 0, 0);
    if (isNearWahana(P, W)) {
        printf("NEAR\n\n");
    }

    // void enqueueWahana(WAHANA*w,Visitor v);
    // int dequeueWahana(WAHANA*w);
    // Gatau ah ini ;-;
    return 0;
}