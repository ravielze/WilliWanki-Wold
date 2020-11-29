#ifndef _MAP_H_
#define _MAP_H_
#include "../constant/adt.h"
#include "../wahana/wahana.h"

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
int MWGetKey(MapWahana MW, WAHANA whn);

/* Get Value List */
WAHANA* MWListWahana(MapWahana MW);

#endif