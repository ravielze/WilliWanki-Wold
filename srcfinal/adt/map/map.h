#ifndef _MAP_H_
#define _MAP_H_
#include "../wahana/wahana.h"
#include "../material/material.h"
#include "../plane/area.h"
#include "../boolean.h"

#define Nil NULL

/* WAHANA */
typedef struct {
    int id;
    WAHANA value;
} MapEntryWahana;
typedef struct {
    int id;
    MATERIAL value;
} MapEntryMaterial;
typedef struct {
    int id;
    AREA value;
} MapEntryArea;

/* MATERIAL */
typedef struct{
    MapEntryWahana* TME;
    int MaxEl;
    int NEff;
} MapWahana;
typedef struct{
    MapEntryMaterial* TME;
    int MaxEl;
    int NEff;
} MapMaterial;
typedef struct{
    MapEntryArea* TME;
    int MaxEl;
    int NEff;
} MapArea;

/*** Selektor ***/
#define MapEntry(M) (M).TME
#define MaxEl(M) (M).MaxEl
#define NEff(M) (M).NEff
#define id(X) (X).id
#define value(X) (X).value

/*** Operasi ***/
/* CreateMap */
MapEntryWahana CreateMapEWahana(int id, WAHANA W);
MapEntryMaterial CreateMapEMaterial(int id, MATERIAL M);
MapEntryArea CreateMapEArea(int id, AREA A);

/* Make Empty */
void MakeEmptyMapWahana(MapWahana *MW,int max);
void MakeEmptyMapMaterial(MapMaterial *MM,int max);
void MakeEmptyMapArea(MapArea *MA,int max);

/* Is Empty */
boolean IsMapWEmpty (MapWahana MW);
boolean IsMapMEmpty (MapMaterial MM);
boolean IsMapAEmpty (MapArea MA);

/* Is Full */
boolean IsMapWFull(MapWahana MW);
boolean IsMapMFull(MapMaterial MM);
boolean IsMapAFull(MapArea MA);

/* Search */
/* Return indeks entry dengan id tertentu, jika tidak ada, return -1 */
int IsEntryWahana(MapWahana MW, int id);
int IsEntryMaterial(MapMaterial MM, int id);
int IsEntryArea(MapArea MA, int id);

/* Delete Key */
/* IS PASTI ADA ID NYA GAMUNGKIN ENGGA GAMAU TAU FS IDNYA DAH ILANG BODO AMAT*/
void DeleteEntryWahana(MapWahana *MW,int id);
void DeleteEntryMaterial(MapMaterial *MM,int id);
void DeleteEntryArea(MapArea *MA,int id);

/* Add Key */
void AddEntryWahana(MapWahana *MW,MapEntryWahana entry);
void AddEntryMaterial(MapMaterial *MM,MapEntryMaterial entry);
void AddEntryArea(MapArea *MA, MapEntryArea entry);

/* Get Key-Value */
WAHANA MWGetWahana(MapWahana MW, int id);
MATERIAL MMGetMaterial(MapMaterial MM, int id);
AREA MAGetMaterial(MapArea MA, int id);

#endif