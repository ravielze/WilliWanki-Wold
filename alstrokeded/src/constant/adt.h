#ifndef ADT_H
#define ADT_H
#include "selector.h"
#include "definition.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "../boolean.h"

#include "../game/game.h"


/* JAM */
typedef struct {
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
} JAM;

/* POINT */
typedef struct {
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;

/* MATERIAL */
typedef struct Mtrl{
    //Untuk kepemilikan/pembelian
    char NamaMaterial[100];
    char Deskripsi[255];
    char Satuan[50];
    int Jumlah;

    //Untuk penjualan
    float Harga;
    int WaktuBeli;
} MATERIAL;

/* WAHANA */
typedef struct Whn{
    char nama[100];
    char tipewahana[100];
    char deskripsi[255];

    int kapasitas;
    int ukuran; //Harus ganjil dan >= 1
    float hargatiket;
    boolean rusak;

    POINT lokasi;
    int durasi;
    boolean isDasar;
    float hargaBuild; 
    int vertex; 
    int durasiBuild; 
    
    BinTree uptree;
    MATERIAL bahan;

    Queue antrian_wahana; 
} WAHANA;

/* AKSI */
typedef struct {
  int id;
  char aksi;
} Aksi;
/* char aksi definition:
'b' for build yeahh
'm' for buy material
'u' upgradeeeeeeeeeeeeeee
'r' RIDE
*/

/* ARRAYLIST */
typedef struct {
    ainfotype *TI;
    int NEff;
    int MaxEl;
} ARRAYLIST;

/* ARRAYLISTMATERIAL */
typedef struct {
    minfotype *TI;
    int NEff;
    int MaxEl;
} ARRAYLISTMAT; 

/* MATRIKS */
typedef int Mindeks; /* Mindeks baris, kolom */
typedef char MElType; 
typedef struct { 
	MElType Mem[99+1][99+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
    int Xplayer;
    int Yplayer;
} MATRIKS;

/* VERTEX GRAF */
typedef struct vertex* AdrVertex;
typedef struct vertex {
    int VertexID;
    MATRIKS InfoMATRIKS;
    AdrVertex Up;
    AdrVertex Left;
    AdrVertex Right;
    AdrVertex Bottom;
} Vertex;
typedef AdrVertex Graph;

/* Linked List */
typedef int LLElType;
typedef struct tLLNode* LLaddress;
typedef struct tLLNode {
    LLElType info;
    LLaddress next;
} LLNode;
typedef struct {
    LLaddress First, Last;
} List;

/* ADT MAP BUKAN PETA */
typedef struct {
    int id;
    WAHANA value;
} MapEntryWahana;
typedef struct{
    MapEntryWahana* TME;
    int MaxEl;
    int NEff;
} MapWahana;

typedef struct {
    int id;
    MATERIAL value;
} MapEntryMaterial;
typedef struct{
    MapEntryMaterial* TME;
    int MaxEl;
    int NEff;
} MapMaterial;

/* STACK BUKAN SETEK */
typedef struct {
  int MaxEl;
  Aksi *TA; 
  int TOP; 
} Stack;

/* Visitor */
typedef struct{
    int visitorid;
    Stack todo;
    int patience;
    JAM enterqueue;
    boolean inrides;
} Visitor;

/* TREE */
typedef int TRElType;
typedef struct ttNode *taddress;
typedef struct ttNode {
    TRElType info;
    taddress Left;
    taddress Right;
} TRNode;
typedef taddress BinTree;

/* QUEUE */
typedef Visitor ElTypeQ;
typedef struct qNode* qaddress;
typedef struct qNode {
   ElTypeQ Info;
   qaddress Next;
   int Prio;
} queueNode;
typedef struct { qaddress HEAD;
               } Queue;

/* ACTION MANAGER - AMANAG */
typedef struct{
    MapWahana DataWahana;
    MapMaterial DataMaterial;
    Stack StackAksi;
    float MoneyUsed;
    int timeRemaining; //dalam menit
} MANAGER_ACTION;

/* STORAGE MANAGER - SMANAG */
typedef struct{
    MapWahana ListWahana; //Map untuk listing Wahana yang tersedia
    int LastIDWahana;
    MapMaterial ListMaterial; //Map Untuk listing Material yang
    int LastIDMaterial;
    ARRAYLIST StorageWahana; // Array List ID Wahana yang dipunyai
    ARRAYLISTMAT StorageMaterial; // Array List semua material yang tersedia
} MANAGER_STORAGE;

/* GAME */
typedef struct{
    char* Pemain;
    float Money;
    JAM Time;

    int currentDay;
    int executionTimes;
    int actionTimes;
    boolean isMainPhase; // penanda phase

    manstor StorageManager; // ini untuk semua hal yang dimiliki player
    manact ActionManager; // ini untuk semua aksi yang akan dilakukan

    Queue GameQueue; // ini untuk antrian
    Graph Graf;
} GAME;
#endif