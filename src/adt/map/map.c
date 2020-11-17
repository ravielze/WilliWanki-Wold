#include "map.h"

/*** Operasi ***/
/* CreateMap */
MapEntryWahana CreateMapEWahana(int id, WAHANA W){
    MapEntryWahana MW;
    id(MW) = id;
    value(MW) = W;
    return MW;    
}

MapEntryMaterial CreateMapEMaterial(int id, MATERIAL M){
    MapEntryMaterial MM;
    id(MM) = id;
    value(MM) = M;
    return MM;
}

/* Make Empty */
void MakeEmptyWahana(MapWahana *MW,int max){
    MapEntry(*MW) = (MapWahana*)malloc(max*sizeof(MapWahana));
    MaxEl(*MW) = max;
    NEff(*MW) = 0;
}

void MakeEmptyMaterial(MapMaterial *MM, int max){
    MapEntry(*MM) = (MapMaterial*)malloc(max*sizeof(MapMaterial));
    MaxEl(*MM) = max;
    NEff(*MM) = 0;
}

/* SEARCHHHHHHHHHHHHHHHHHHH */
/* Return indeks entry dengan id tertentu, jika tidak ada, return 999 */
int IsEntryWahana(MapWahana *MW, int sid){
    for (int i = 0; i<Neff(*MW); i++){
        if (id(MapEntry(*MW)[i]) == sid) return i;
    }
    return 999;
}
int IsEntryMaterial(MapMaterial *MM, int sid){
    for (int i = 0; i<Neff(*MM); i++){
        if (id(MapEntry(*MM)[i]) == sid) return i;
    }
    return 999;
}

/* Delete Key */
/* IS PASTI ADA ID NYA GAMUNGKIN ENGGA GAMAU TAU
   FS IDNYA DAH ILANG BODO AMAT*/
void DeleteEntryWahana(MapWahana *MW,int id){
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

void DeleteEntryMaterial(MapMaterial *MM,int id){
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
/* Is Full */
boolean IsMapWFull(MapWahana MW){
    return (NEff(MW) == MaxEl(MW));
}

boolean IsMapMFull(MapMaterial MM){
    return (NEff(MM) == MaxEl(MM));
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