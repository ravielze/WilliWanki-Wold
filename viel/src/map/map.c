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

/* Is Empty ???? */
boolean IsMapWEmpty (MapWahana MW) {
    return NEff(MW) == 0;
}

boolean IsMapMEmpty (MapMaterial MM) {
    return NEff(MM) == 0;
}

/* Is Full */
boolean IsMapWFull(MapWahana MW){
    return (NEff(MW) == MaxEl(MW));
}

boolean IsMapMFull(MapMaterial MM){
    return (NEff(MM) == MaxEl(MM));
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

/* Add Key */
void AddEntryWahana(MapWahana *MW, MapEntryWahana entry){
    if (IsMapWFull(*MW)){
        MapEntry(*MW) = (MapEntryWahana*)realloc(MapEntry(*MW), ((MaxEl(*MW)+5)*sizeof(MapEntryWahana)));
        MaxEl(*MW) += 5;
    }
    MapEntry(*MW)[NEff(*MW)] = entry;
    NEff(*MW)++;
}

void AddEntryMaterial(MapMaterial *MM, MapEntryMaterial entry){
    if (IsMapMFull(*MM)){
        MapEntry(*MM) = (MapEntryMaterial*)realloc(MapEntry(*MM), ((MaxEl(*MM)+5)*sizeof(MapEntryMaterial)));
        MaxEl(*MM) += 5;
    }
    MapEntry(*MM)[NEff(*MM)] = entry;
    NEff(*MM)++;
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

WAHANA* MWListWahana(MapWahana MW){
    WAHANA* result = (WAHANA*) malloc(NEff(MW)*sizeof(WAHANA));
    int i;
    for(i=0;i <NEff(MW);i++){
        result[i] = value(MapEntry(MW)[i]);
    }
    return result;
}