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
    MapEntryWahana * newTab = (MapEntryWahana *) malloc(max*sizeof(MapEntryWahana));
    MapEntry(*MW) = newTab;
    MaxEl(*MW) = max;
    NEff(*MW) = 0;
}

void MakeEmptyMapMaterial(MapMaterial *MM, int max){
    MapEntryMaterial * newTab = (MapEntryMaterial *) malloc(max*sizeof(MapEntryMaterial));
    MapEntry(*MM) = newTab;
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
int IsEntryWahana(MapWahana MW, int id) {
// Mengurangi MaxEl jika yang terisi kurang dari 25%
    for (int i = 0; i < NEff(MW); i++) {
        if (id(MapEntry(MW)[i]) == id) return i;
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
    if (NEff(*MM) <= (MaxEl(*MM) / 4)) {
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
        MapEntryWahana *temp = (MapEntryWahana*)realloc(MapEntry(*MW), ((MaxEl(*MW)+10)*sizeof(MapEntryWahana)));
        if (temp != Nil){
            MaxEl(*MW) += 10;
            MapEntry(*MW) = temp;
        }
    }
    MapEntry(*MW)[NEff(*MW)] = entry;
    NEff(*MW)++;
}

void AddEntryMaterial(MapMaterial *MM, MapEntryMaterial entry){
    if (IsMapMFull(*MM)){
        MapEntryMaterial *temp = (MapEntryMaterial*)realloc(MapEntry(*MM), ((MaxEl(*MM)+10)*sizeof(MapEntryWahana)));
        if (temp != Nil){
            MaxEl(*MM) += 10;
            MapEntry(*MM) = temp;
        }
    }
    MapEntry(*MM)[NEff(*MM)] = entry;
    NEff(*MM)++;
}

/* Get Key-Value */
WAHANA MWGetWahana(MapWahana MW, int id){
    /* Prekondisi : wahana ada*/
    int rid = IsEntryWahana(MW, id);
    return value(MapEntry(MW)[rid]);
}

MATERIAL MMGetMaterial(MapMaterial MM, int id) {
    /* Prekondisi : material ada*/
    int rid = IsEntryMaterial(MM ,id);
    return value(MapEntry(MM)[rid]);
}

int MWGetKey(MapWahana MW, WAHANA whn){
    for (int i = 0; i < NEff(MW); i++) {
        if (isWahanaEqual(MWGetWahana(MW, i) , whn)) return i;
    }
    return -1;
}

WAHANA* MWListWahana(MapWahana MW){
    WAHANA* result = (WAHANA*) malloc(NEff(MW)*sizeof(WAHANA));
    int i;
    for(i=0;i <NEff(MW);i++){
        result[i] = value(MapEntry(MW)[i]);
    }
    return result;
}