#ifndef _MAP_H_
#define _MAP_H_
#include "../wahana/wahana.h"
#include "../material/material.h"
#include "../boolean.h"
#include <stdlib.h>

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

/* MATERIAL */
typedef struct{
    //MapEntryWahana TME[...];
    MapEntryWahana* TME;
    int MaxEl;
    int NEff;
} MapWahana;
typedef struct{
    MapEntryMaterial* TME;
    int MaxEl;
    int NEff;
} MapMaterial;

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

/* Make Empty */
void MakeEmptyMapWahana(MapWahana *MW,int max);
void MakeEmptyMapMaterial(MapMaterial *MM,int max);

/* Is Empty */
boolean IsMapWEmpty (MapWahana MW);
boolean IsMapMEmpty (MapMaterial MM);

/* Is Full */
boolean IsMapWFull(MapWahana MW);
boolean IsMapMFull(MapMaterial MM);

/* Search */
/* Return indeks entry dengan id tertentu, jika tidak ada, return -1 */
int IsEntryWahana(MapWahana MW, int id);
int IsEntryMaterial(MapMaterial MM, int id);

/* Delete Key */
/* IS PASTI ADA ID NYA GAMUNGKIN ENGGA GAMAU TAU FS IDNYA DAH ILANG BODO AMAT*/
void DeleteEntryWahana(MapWahana *MW,int id);
void DeleteEntryMaterial(MapMaterial *MM,int id);

/* Add Key */
void AddEntryWahana(MapWahana *MW,MapEntryWahana entry);
void AddEntryMaterial(MapMaterial *MM,MapEntryMaterial entry);

/* Get Key-Value */
WAHANA MWGetWahana(MapWahana MW, int id);
MATERIAL MMGetMaterial(MapMaterial MM, int id);
int MWGetKey(MapWahana MW, WAHANA whn); // TODO realisasi

/* Get Value List */
WAHANA* MWListWahana(MapWahana MW);

#endif