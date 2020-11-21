#include "map.h"

/*** Operasi ***/

/* CreateMap */
MapEntryWahana CreateMapEWahana(int id, WAHANA W) {
    MapEntryWahana MW;
    id(MW) = id;
    value(MW) = W;
    return MW;    
}

MapEntryMaterial CreateMapEMaterial(int id, MATERIAL M) {
    MapEntryMaterial MM;
    id(MM) = id;
    value(MM) = M;
    return MM;
}

MapEntryArea CreateMapEArea(int id, AREA A) {
    MapEntryArea MA;
    id(MA) = id;
    value(MA) = A;
    return MA;
}

/* Make Empty */
void MakeEmptyMapWahana(MapWahana *MW,int max){
    MapEntry(*MW) = (MapWahana*)malloc(max*sizeof(MapWahana));
    MaxEl(*MW) = max;
    NEff(*MW) = 0;
}

void MakeEmptyMapMaterial(MapMaterial *MM, int max){
    MapEntry(*MM) = (MapMaterial*)malloc(max*sizeof(MapMaterial));
    MaxEl(*MM) = max;
    NEff(*MM) = 0;
}

void MakeEmptyMapArea(MapArea *MA,int max) {
    MapEntry(*MA) = (MapArea*)malloc(max*sizeof(MapArea));
    MaxEl(*MA) = max;
    NEff(*MA) = 0;
}

/* Is Empty ???? */
boolean IsMapWEmpty (MapWahana MW) {
    return NEff(MW) == 0;
}

boolean IsMapMEmpty (MapMaterial MM) {
    return NEff(MM) == 0;
}

boolean IsMapAEmpty (MapArea MA) {
    return NEff(MA) == 0;
}

/* Is Full */
boolean IsMapWFull(MapWahana MW){
    return (NEff(MW) == MaxEl(MW));
}

boolean IsMapMFull(MapMaterial MM){
    return (NEff(MM) == MaxEl(MM));
}

boolean IsMapAFull(MapArea MA) {
    return (NEff(MA) == MaxEl(MA));
}

/* Search */
/* Return indeks entry dengan id tertentu, jika tidak ada, return -1 */
int IsEntryWahana(MapWahana MW, int sid) {
// Mengurangi MaxEl jika yang terisi kurang dari 25%
    for (int i = 0; i < NEff(MW); i++) {
        if (id(MapEntry(MW)[i]) == sid) return i;
    }
    return -1;
}
int IsEntryMaterial(MapMaterial MM, int sid) {
    for (int i = 0; i < NEff(MM); i++) {
        if (id(MapEntry(MM)[i]) == sid) return i;
    }
    return -1;
}

int IsEntryArea(MapArea MA, int sid) {
    for (int i = 0; i < NEff(MA); i++) {
        if (id(MapEntry(MA)[i]) == sid) return i;
    }
    return -1;
}

/* Delete Key */
/* IS PASTI ADA ID NYA GAMUNGKIN ENGGA GAMAU TAU
   FS IDNYA DAH ILANG BODO AMAT*/
void DeleteEntryWahana(MapWahana *MW,int id) {
// Mengurangi MaxEl jika yang terisi kurang dari 25%
    if (NEff(*MW) <= (MaxEl(*MW) / 4)) {
        MaxEl(*MW) /= 2;
        MapEntryWahana *temp = (MapEntryWahana *) realloc(MapEntry(*MW), (MaxEl(*MW) * sizeof(MapWahana)));
        if (temp == Nil) {
            printf("Error reallocating memory.");
            MapEntry(*MW) = Nil;
            return;
        }
        else {
            MapEntry(*MW) = temp;
        }
    }
    int i = 0;
    boolean found = false;
    while (i < NEff(*MW) && !found) {
        if (id(MapEntry(*MW)[i]) == id) {
            found = true;
            /* Geser semuanya ke kiri */
            for (int j = i; j < NEff(*MW); j++) {
                MapEntry(*MW)[j] = MapEntry(*MW)[j+1];
            }
            /* Kosongin yang terakhir */
            NEff(*MW)--;          
        }
        else i++;
    }
}

void DeleteEntryMaterial(MapMaterial *MM,int id) {
// Mengurangi MaxEl jika yang terisi kurang dari 25%
    if (Neff(*MM) <= (MaxEl(*MM) / 4)) {
        MaxEl(*MM) /= 2;
        MapEntryMaterial *temp = (MapEntryMaterial *) realloc(MapEntry(*MM), (MaxEl(*MM) * sizeof(MapMaterial)));
        if (temp == Nil) {
            printf("Error reallocating memory.");
            MapEntry(*MM) = Nil;
            return;
        }
        else {
            MapEntry(*MM) = temp;
        }
    }
    int i = 0;
    boolean found = false;
    while (i < NEff(*MM) && !found) {
        if (id(MapEntry(*MM)[i]) == id) {
            found = true;
            /* Geser semuanya ke kiri */
            for (int j = i; j < NEff(*MM); j++) {
                MapEntry(*MM)[j] = MapEntry(*MM)[j+1];
            }
            /* Kosongin yang terakhir */
            NEff(*MM)--;          
        }
        else i++;
    }
}

void DeleteEntryArea(MapArea *MA, int id) {
    if (NEff(*MA) <= (MaxEl(*MA) / 4)) {
        MaxEl(*MA) /= 2;
        MapEntryArea *temp = (MapEntryArea *) realloc(MapEntry(*MA), (MaxEl(*MA) * sizeof(MapArea)));
        if (temp == Nil) {
            printf("Error reallocating memory.");
            MapEntry(*MA) = Nil;
            return;
        }
        else {
            MapEntry(*MA) = temp;
        }
    }
    int i = 0;
    boolean found = false;
    while (i < NEff(*MA) && !found) {
        if (id(MapEntry(*MA)[i]) == id) {
            found = true;
            /* Geser semuanya ke kiri */
            for (int j = i; j < NEff(*MA); j++) {
                MapEntry(*MA)[j] = MapEntry(*MA)[j+1];
            }
            /* Kosongin yang terakhir */
            NEff(*MA)--;          
        }
        else i++;
    }
}

/* Add Key */
void AddEntryWahana(MapWahana *MW, MapEntryWahana entry){
    if (IsMapWFull(*MW)){
        MapEntry(*MW) = (MapWahana*)realloc(MapEntry(*MW), ((MaxEl(*MW)+5)*sizeof(MapWahana)));
        MaxEl(*MW) += 5;
    }
    MapEntry(*MW)[NEff(*MW)] = entry;
    NEff(*MW)++;
}

void AddEntryMaterial(MapMaterial *MM, MapEntryMaterial entry){
    if (IsMapMFull(*MM)){
        MapEntry(*MM) = (MapMaterial*)realloc(MapEntry(*MM), ((MaxEl(*MM)+5)*sizeof(MapMaterial)));
        MaxEl(*MM) += 5;
    }
    MapEntry(*MM)[NEff(*MM)] = entry;
    NEff(*MM)++;
}

void AddEntryArea(MapArea *MA, MapEntryArea entry){
    if (IsMapAFull(*MA)){
        MapEntry(*MA) = (MapArea*)realloc(MapEntry(*MA), ((MaxEl(*MA)+5)*sizeof(MapArea)));
        MaxEl(*MA) += 5;
    }
    MapEntry(*MA)[NEff(*MA)] = entry;
    NEff(*MA)++;
}

/* Get Key-Value */
WAHANA MWGetWahana(MapWahana MW, int id){
    /* Prekondisi : wahana ada*/
    int rid = IsEntryWahana(MW, id);
    if (rid == -1){ 
        WAHANA whnkosong;
        return whnkosong;
    }

    return value(MapEntry(MW)[rid]);
}

MATERIAL MMGetMaterial(MapMaterial MM, int id) {
    /* Prekondisi : material ada*/
    int rid = IsEntryMaterial(MM ,id);
    if (rid == -1){
        MATERIAL matkosong;
        return matkosong;
    }

    return value(MapEntry(MM)[rid]);
}

AREA MAGetMaterial(MapArea MA, int id) {
    /* Prekondisi : material ada*/
    int rid = IsEntryArea(MA ,id);
    if (rid == -1){
        AREA areakosong;
        return areakosong;
    }
    return value(MapEntry(MA)[rid]);
}
