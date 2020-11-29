#ifndef ADT_SELECTOR_H
#define ADT_SELECTOR_H

/* JAM */
#define Hour(J) (J).HH
#define Minute(J) (J).MM

/* POINT */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y

/* MATERIAL */
#define Nama(X) (X).NamaMaterial
#define Deskripsi(X) (X).Deskripsi
#define Satuan(X) (X).Satuan
#define Harga(X) (X).Harga
#define Waktu(X) (X).WaktuBeli
#define Punya(X) (X).Jumlah

/* WAHANA */
#define NamaWhn(W) (W).nama
#define TipeWhn(W) (W).tipewahana
#define DeskripsiWhn(W) (W).deskripsi
#define KpstsWhn(W) (W).kapasitas
#define History(W) (W).history
#define SizeWhn(W) (W).ukuran
#define HargaTiket(W) (W).hargatiket
#define RusakGakSih(W) (W).rusak
#define LokWhn(W) (W).lokasi
#define DurasiWhn(W) (W).durasi
#define WahanaDasar(W) (W).isDasar
#define Bahan(W) (W).bahan
#define UpgradeTree(W) (W).uptree
#define HargaBuild(W) (W).hargaBuild
#define InVertex(W) (W).vertex
#define DurasiBuild(W) (W).durasiBuild
#define QueueWahana(W) (W).antrian_wahana
#define PelangganCounter(W) (W).pelanggan_counter

/* ARRAY dan ARRAYMAT */
#define TI(T) (T).TI
#define ItemOf(T, i) (T).TI[(i)]
#define NEff(T) (T).NEff
#define MaxEl(T) (T).MaxEl

/* GRAPH */
#define InfoMATRIKS(P) (P)->InfoMATRIKS
#define Up(P) (P)->Up
#define Left(P) (P)->Left
#define Right(P) (P)->Right
#define Bottom(P) (P)->Bottom
#define VertexID(P) (P)->VertexID

/* LINKED LIST */
#define AInfo(P) ((P)->info)
// ALIAS ARROW INFO
#define ANext(P) ((P)->next)
// ALIAS ARROW NEXT
#define First(L) ((L).First)
#define Last(L) ((L).Last)

/* ADT MAP BUKAN PETA */
#define MapEntry(M) (M).TME
//define MaxEl(M) (M).MaxEl (Refer to punya Array diatas)
//define NEff(M) (M).NEff (Refer to punya Array diatas)
#define id(X) (X).id
#define value(X) (X).value

/* STACK */
#define Top(S) (S).TOP
#define InfoTop(S) (S).TA[(S).TOP]
//define MaxEl(S) (S).MaxEl (Refer to punya Array diatas)
#define IsiStack(S) (S).TA
#define IDAksi(A) (A).id
#define InfoAksi(A) (A).aksi

/* MATRIKS */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]
#define Xplayer(M) (M).Xplayer
#define Yplayer(M) (M).Yplayer

/* VISITOR */
#define todo(V) (V).todo
#define inrides(V) (V).inrides
#define patience(V) (V).patience
#define visitorid(V) (V).visitorid
#define entertime(V) (V).enterqueue

/* TREE */
#define Akar(P) (P)->info
//define Left(P) (P)->Left (Refer to punya Graph diatas)
//define Right(P) (P)->Right (Refer to punya Graph diatas)

/* QUEUE */
#define Head(Q) (Q).HEAD
#define InfoHead(Q) (Q).HEAD->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info
#define Prio(P) (P)->Prio

/* ACTION MANAGER - AMANAG */
#define manact MANAGER_ACTION
#define AMappingW(X) (X).DataWahana
#define AMappingM(X) (X).DataMaterial
#define StackAksi(X) (X).StackAksi
#define MoneyUsed(X) (X).MoneyUsed
#define TimeRemaining(X) (X).timeRemaining

/* STORAGE MANAGER - SMANAG */
#define manstor MANAGER_STORAGE
#define SMappingW(X) (X).ListWahana
#define LIDWahana(X) (X).LastIDWahana
#define StorageW(X) (X).StorageWahana
#define StorageM(X) (X).StorageMaterial

/* GAME */
#define GameQueue(G) (G).GameQueue
#define Pemain(G) (G).Pemain
#define Money(G) (G).Money
#define Time(G) (G).Time // JAM
#define CurrDay(G) (G).currentDay
#define ExecTimes(G) (G).executionTimes
#define IsMP(G) (G).isMainPhase
#define Amanag(G) (G).ActionManager
#define Smanag(G) (G).StorageManager
#define actionTimes(G) (G).actionTimes
#define Graf(X) (X).Graphhh
#endif