#include "storagemanager.h"

void createManagerStorage(GAME * game){
    manstor ms;

    LIDWahana(ms) = -1;

    ARRAYLIST AL;
    CreateEmptyAL(&AL, 10);
    StorageW(ms) = AL;

    ARRAYLISTMAT ALM;
    CreateEmptyMAT(&ALM, 10);
    StorageM(ms) = ALM;

    MapWahana MapWhn;
    MakeEmptyMapWahana(&MapWhn, 10);
    SMappingW(ms) = MapWhn;
    

    Smanag(*game) = ms;
}

void initStorageManager(char* wahanafilename, char* materialfilename, char* treefilename, manstor* ms){
    int N;
    WAHANA whn;
    FILE* MaterialFile = fopen(materialfilename, "r");

    // printf("A");
    fscanf(MaterialFile, "%d\n", &N);
    // printf("MATERIAL:\n");
    while(N--){
        char nama[1000]; char desc[1000]; char satuan[1000]; int jmlh; float harga; int waktu;
        fscanf(MaterialFile, "%s %s %s %d %f %d\n", nama, desc, satuan, &jmlh, &harga, &waktu);
        MATERIAL mat = createMaterial(nama, desc, satuan, jmlh, harga, waktu);
        ScreateMaterial(ms, mat);
    }

    fclose(MaterialFile);

    FILE* WahanaFile = fopen(wahanafilename, "r");
    // printf("WAHANA:\n");
    fscanf(WahanaFile, "%d\n", &N);
    MATERIAL mat;
    while(N != 0){
        char namawhn[1000]; char tipewhn[1000]; char deskripsi[1000]; int kpstswhn; int sizewhn; float hargatiket; boolean rusakgasi; int durasi; boolean iswahanadasar; float hargabuild; int vertex; int durasibuild;
        char nama[1000]; char desc[1000]; char satuan[1000]; int jmlh; float harga; int waktu;
        fscanf(WahanaFile, "%s %s %s %d %d %f %d %d %d %f %d %d\n", namawhn, tipewhn, deskripsi, &kpstswhn, &sizewhn, &hargatiket, &rusakgasi, &durasi, &iswahanadasar, &hargabuild, &vertex, &durasibuild);
        fscanf(WahanaFile, "%s %s %s %d %f %d\n", nama, desc, satuan, &jmlh, &harga, &waktu);

        whn = createWahana(namawhn, tipewhn, deskripsi, kpstswhn, sizewhn, hargatiket, rusakgasi, durasi, iswahanadasar, hargabuild, vertex, durasibuild);
        mat = createMaterial(nama, desc, satuan, jmlh, harga, waktu);
        Bahan(whn) = mat;
        Akar(UpgradeTree(whn)) = N;
        ScreateWahana(ms, whn);
        N--;
        // printf("%s\n", NamaWhn(whn));

    }
    fclose(WahanaFile);

    // printf("\nTREE:\n");
    FILE* TreeFile = fopen(treefilename, "r");
    fscanf(TreeFile, "%d\n", &N);
    while(N--){
        // Ngeloop setiap relasi yang ada 
        // 0 1 2 3
        // Nil
        // 1 2
        int from, to;
        char LeftorRight;

        fscanf(TreeFile, "%d %c %d\n", &from, &LeftorRight, &to);
        MWGetWahana(&(SMappingW(*ms)), from, &whn);
        printf("%s\n", NamaWhn(whn) );
        BinTree newDaun = AlokasiT(to);
        if (newDaun != Nil){
            if (LeftorRight == 'L') {
                Left(UpgradeTree(whn) ) = newDaun; 
            } else {
                Right(UpgradeTree(whn) ) = newDaun; 
            }
        }

        // PrintTree(UpgradeTree(whn), 2);

        int idWahana = MWGetKey(SMappingW(*ms) , whn);
        DeleteEntryWahana(&(SMappingW(*ms)), idWahana);
        AddEntryWahana(&(SMappingW(*ms)), CreateMapEWahana(idWahana, whn) );
    }
    
    fclose(TreeFile);
}


void ScreateWahana(manstor * ms, WAHANA whn){
/* Menambahkan wahana ke mapwahana global game */
    LIDWahana(*ms)++;
    MapEntryWahana MEW = CreateMapEWahana(LIDWahana(*ms),whn);
    AddEntryWahana(&(SMappingW(*ms)), MEW);
}

void addWahana(manstor * ms, int id){
/* Menambahkan wahana ke storage JIKA belum ada */
    if(!SearchAL(StorageW(*ms),id)){
        InsertLastAL(&StorageW(*ms),id);
    }
}

void deleteWahana(manstor * ms, int id){
/* Delete wahana dengan id tertentu pada storage JIKA ada */
    int i = SearchIdxAL(StorageW(*ms),id);
    if(SearchAL(StorageW(*ms), id)){
        DeleteNAL(&StorageW(*ms),i);
    }
}

void ScreateMaterial(manstor * ms, MATERIAL mat){
/* Menambahkan wahana ke array list material global game */
    ARRAYLISTMAT ALM = StorageM(*ms);
    InsertLastMAT(&ALM, mat);

    StorageM(*ms) = ALM;
}

void getWahana(manstor * ms, int id, WAHANA* whn) {
    WAHANA W;
    MWGetWahana(&(SMappingW(*ms)), id, &W);
    *whn = W;
}