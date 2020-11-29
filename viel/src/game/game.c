#include "game.h"


/* UNTUK INITIALIZATION GAME, BUKAN UNTUK BUAT GAME */
/* F.S  GAME SUDAH DIISI DENGAN DATA YANG DIPERLUKAN*/
GAME createGame() {
    GAME g;
    float m = 1000;
    JAM j;
    MakeJam(&j, 9, 0);
    int cd = 0;
    int et = 0;
    int at = 0;
    boolean mp = false;
    createManagerStorage(&g);
    createManagerStorage(&g);

    Money(g) = m;
    Time(g) = j;
    CurrDay(g) = cd;
    ExecTimes(g) = et;
    IsMP(g) = mp;
    actionTimes(g) = at;
    generateWeaboo(&g); /* GENERATING START QUEUE */
    
    MATRIKS Peta1, Peta2, Peta3, Peta4;

    InitPeta("../../database/peta/peta1.txt", &Peta1);
    InitPeta("../../database/peta/peta2.txt", &Peta2);
    InitPeta("../../database/peta/peta3.txt", &Peta3);
    InitPeta("../../database/peta/peta4.txt", &Peta4);

    Graph Gr = InitGraphPeta(Peta1, Peta2, Peta3, Peta4);
    Graf(g) = Gr;

    return g;
}

//si game nanya player mau ngapain?
//- build
//- beli material
//- upgrade
//- execute
//- undo

void move(GAME * g){
    printf("Intial Map\n");
    Graph G = Graf(*g);
    TulisMATRIKS(InfoMATRIKS(G));
    while (true) {
        STARTKATA();
        while (!EndKata){
            if (IsKataSama(CKata, CreateKata("W") ) || IsKataSama(CKata, CreateKata("w") ) ) {
                MovePlayer(&G, 0, -1);
            } else if (IsKataSama(CKata, CreateKata("A") ) || IsKataSama(CKata, CreateKata("a") ) ) {
                MovePlayer(&G, -1, 0);
            } else if (IsKataSama(CKata, CreateKata("S") ) || IsKataSama(CKata, CreateKata("s") ) ) {
                MovePlayer(&G, 0, 1);
            } else if (IsKataSama(CKata, CreateKata("D") ) || IsKataSama(CKata, CreateKata("d") ) ) {
                MovePlayer(&G, 1, 0);
            }
            
            ADVKATA();
        }

        TulisMATRIKS(InfoMATRIKS(G));
    }
}

void action(GAME * game) {
    char Ans[10];
    printf("Apa yang ingin dilakukan?\n");
    printf("  1. Bangun wahana      : build\n");
    printf("  2. Beli material      : buy\n");
    printf("  3. Upgrade wahana     : upgrade\n");
    printf("  4. Execute stack      : execute\n");
    printf("  5. Undo last action   : undo\n");
    printf("  6. Skip to main phase : main\n\n");
    printf("Masukkan perintah:\n");
    scanf("%s", Ans);

    if (strcmp(Ans, "build") == 0) {
        buildPush(game);
    } else if (strcmp(Ans, "buy") == 0) {
        buyMaterialPush(game);
    } else if (strcmp(Ans, "upgrade") == 0) {
        upgradePush(game);
    } else if (strcmp(Ans, "execute") == 0) {
        ExecutePhase(game);
    } else if (strcmp(Ans, "undo") == 0) {
        undo(game);
    } else if (strcmp(Ans, "main") == 0) {
        mainphase(game);
    } else {
        printf("'%s' bukan command yang valid.", Ans);
    }
}

void buildPush(GAME * game){
    manstor Manstor = Smanag(*game);
    MapWahana MW = SMappingW(Manstor);
    int neffMW = NEff(MW);
    WAHANA* whnlist = MWListWahana(MW);

    // Print list wahana tersedia
    printf("Ingin membangun apa?\n");
    printf("List wahana tersedia : \n");

    WAHANA select[neffMW];
    for (int i=0 ; i < neffMW; i++){
        WAHANA currwhn = whnlist[i];
        if (WahanaDasar(currwhn)){
            select[i] = currwhn;
            printf("%d. ", (i+1));
            printf("%s \n", NamaWahana(currwhn));
        }
    }    

    // Terima input wahana apa yang dibangun
    int selectuser;
    scanf("%d", &selectuser);
    selectuser--;
    WAHANA whn_selected = select[selectuser];

    // Cek Apakah wahana bisa dibangun
    if (!IsBuildAbleSenpai(whn_selected, game)){
        printf("Wahana tidak bisa dibangun.\n");
    }
    else{
        MATERIAL bahan_whn_selected = Bahan(whn_selected);

        ARRAYLISTMAT storageM = StorageM(Manstor);
        int idx_material_selected = SearchIdxMAT(storageM,bahan_whn_selected);
        MATERIAL * currMat = &ItemOf(storageM, idx_material_selected);
        
        int jlhButuh = Punya(bahan_whn_selected);
        int jlhPunya = Punya(*currMat);

        // Cek apakah wahana sudah ada sebelumnya
        ARRAYLIST storageW = StorageW(Manstor);
        int idx_whn_selected = MWGetKey(MW, whn_selected);
        
        if (!SearchAL(storageW , idx_whn_selected)){
            printf("Wahana sudah pernah dibangun.\n");
        }
        else{
            manact Manact = Amanag(*game);
            int time_remain = TimeRemaining(Manact);
            int time_for_build = DurasiBuild(whn_selected);

            if (jlhPunya < jlhButuh){
                printf("Bahan yang dipunya tidak mencukupi.\n");
            }
            else if (time_remain - time_for_build < 0){
                printf("Waktu tidak mencukupi.\n");
            }
            else{
                // Kurangin waktu 
                TimeRemaining(Manact) -= time_for_build;

                // Push aksi ke stack
                manact Manact = Amanag(*game);
                MapWahana MW_AM = AMappingW(Manact);
                Stack Stack_AM = StackAksi(Manact);        

                int id = Top(Stack_AM);
                Aksi aksi_build = createAksi(id, 'b');
                PushAksi(&Stack_AM,aksi_build);
                AddEntryWahana(&MW_AM, CreateMapEWahana(id, whn_selected));
            }
        }
    }
}

void buildPop(GAME * game){
    Aksi aksi_build;
    PopAksi(&(StackAksi(Amanag(*game))), &aksi_build);
    WAHANA whn_selected = MWGetWahana(AMappingW(Amanag(*game)), IDAksi(aksi_build));
    MATERIAL bahan_whn_selected = Bahan(whn_selected);

    manstor Manstor = Smanag(*game);

    ARRAYLISTMAT storageM = StorageM(Manstor);
    int idx_material_selected = SearchIdxMAT(storageM,bahan_whn_selected);
    MATERIAL * currMat = &ItemOf(storageM, idx_material_selected);
    
    int jlhButuh = Punya(bahan_whn_selected);
    
    // kurang jumlah material yang dipunyai player
    Punya(*currMat) -= jlhButuh;

    // kurang duit player
    Money(*game) -= HargaBuild(whn_selected);

    // Insert Wahana ke wahana storage
    ARRAYLIST whn_storage = StorageW(Manstor);

    MapWahana MW = SMappingW(Manstor);
    int idWahana = MWGetKey(MW,whn_selected);
    InsertLastAL(&whn_storage, idWahana);
}

/*  Upgrade Wahana 
    1. Print Tree Upgrade
    2. Pilih kanan atau kiri
    3. Cek resource dan uang dan waktu
    4. Push ke stack aksi */

void upgradePush(GAME * game) {
    WAHANA W;
    manstor Manstor = Smanag(*game);
    ARRAYLIST storageW = StorageW(Manstor);
    
    // Traversal dekat wahana di list wahana
    int i = 0;
    boolean found = false;
    WAHANA whn_ada[NEff(storageW)];
    while (!found && i < NEff(storageW)) {
        WAHANA currwhn = whn_ada[i];
        int X = Xplayer(InfoMATRIKS(Graf(*game)));
        int Y = Yplayer(InfoMATRIKS(Graf(*game)));
        POINT point_player;
        MakePoint (&point_player, X, Y);
        if (IsNearWahana(point_player, currwhn)) {
            W = currwhn;
            found = true;
        } else {
            i++;
        }
    }

    // Jika tidak berdiri di sekitar wahana, prematurely end the function
    if (!found) {
        printf("Tidak berdiri di sekitar wahana.\n");
    } else {
        printf("Ingin melakukan upgrade apa?\n");

        // Print Tree Upgrade
        // void printUpTree(WAHANA W);
        WAHANA Upgrade[2];

        int IDL = Akar(Left(UpgradeTree(W)));
        int IDR = Akar(Right(UpgradeTree(W)));
        getWahana(&Manstor, IDL, &(Upgrade[0]));
        getWahana(&Manstor, IDR, &(Upgrade[1]));
        
        printf("List:\n");
        printf("  1. %s\n", NamaWhn(Upgrade[0]));
        printf("  2. %s\n", NamaWhn(Upgrade[1]));

        // Terima input wahana apa yang dibangun
        int Ans;
        scanf("%d", &Ans);
        Ans--;

        // Wahana tujuan upgrade!
        WAHANA whn_up = Upgrade[Ans];
        MATERIAL bahan_whn_up = Bahan(whn_up);

        ARRAYLISTMAT storageM = StorageM(Manstor);
        int idx_material_up = SearchIdxMAT(storageM, bahan_whn_up);
        MATERIAL * currMat = &ItemOf(storageM, idx_material_up);
        
        int jlhButuh = Punya(bahan_whn_up);
        int jlhPunya = Punya(*currMat);

        // Cek apakah wahana sudah ada sebelumnya
        int idx_whn_up = MWGetKey(SMappingW(Manstor), whn_up);
        
        if (!SearchAL(storageW, idx_whn_up)){
            printf("Wahana sudah pernah dibangun.\n");
        } else {
            manact Manact = Amanag(*game);
            int time_remain = TimeRemaining(Manact);
            int time_for_build = DurasiBuild(whn_up);

            if (jlhPunya < jlhButuh){
                printf("Bahan yang dipunya tidak mencukupi.\n");
            } 
            else if (time_remain - time_for_build < 0){
                printf("Waktu tidak mencukupi.\n");
            } else {
                // Push aksi ke stack
                manact Manact = Amanag(*game);
                MapWahana MW_AM = AMappingW(Manact);
                Stack Stack_AM = StackAksi(Manact);
                TimeRemaining(Manact) -= time_for_build;  

                int id = Top(Stack_AM);
                Aksi aksi_up = createAksi(id, 'u');
                PushAksi(&Stack_AM, aksi_up);
                AddEntryWahana(&MW_AM, CreateMapEWahana(id, whn_up));
            }
        }
        // TODO: Remove wahana sebelumnya ATAU edit IsNearWahana untuk upgrade maksimum
    }
}

void upgradePop(GAME *game) {
    Aksi aksi_up;
    PopAksi(&(StackAksi(Amanag(*game))), &aksi_up);
    WAHANA whn_up = MWGetWahana(AMappingW(Amanag(*game)), IDAksi(aksi_up));
    MATERIAL bahan_whn_up = Bahan(whn_up);

    manstor Manstor = Smanag(*game);

    ARRAYLISTMAT storageM = StorageM(Manstor);
    int idx_material_up = SearchIdxMAT(storageM,bahan_whn_up);
    MATERIAL * currMat = &ItemOf(storageM, idx_material_up);
    
    int jlhButuh = Punya(bahan_whn_up);
    
    // kurang jumlah material yang dipunyai player
    Punya(*currMat) -= jlhButuh;

    // kurang duit player
    Money(*game) -= HargaBuild(whn_up);    

    // Insert Wahana ke wahana storage
    ARRAYLIST whn_storage = StorageW(Manstor);

    MapWahana MW = SMappingW(Manstor);
    int idWahana = MWGetKey(MW,whn_up);
    InsertLastAL(&whn_storage, idWahana);
}

void buyMaterialPush(GAME * game){
    manstor Manstor = Smanag(*game);

    // Print List Material
    printf("Ingin membeli apa?\n");
    printf("List Material tersedia :\n");
        
    // ARRAYLISTMAT isinya smua material    
    ARRAYLISTMAT mat_storage = StorageM(Manstor);
    MATERIAL * matList = TI(mat_storage);
    MATERIAL select[NEff(mat_storage)];
    for (int i=0 ; i < NEff(mat_storage) ; i++){
        MATERIAL currMat = matList[i];
        select[i] = currMat;
        printf("%d. ", (i+1));
        printf("%s \n" , Nama(currMat));
    }

    // Terima input jumlah bahan
    int jumlahBeli;
    scanf("%d", &jumlahBeli);

    // Terima input jenis material
    int selectuser;
    scanf("%d", &selectuser);
    selectuser--;
    MATERIAL mat_selected = select[selectuser];
    // Ubah nilai jumlah pada material yang akan di assert menjadi jumlah yang dibeli
    Punya(mat_selected) = jumlahBeli;

    float hargaBeli = Harga(mat_selected) * jumlahBeli;

    manact Manact = Amanag(*game);
    int time_remain = TimeRemaining(Manact);
    int time_for_buy = Waktu(mat_selected);

    if (Money(*game) < hargaBeli){
        printf("Uang tidak mencukupi.");
    }
    else if (time_remain - time_for_buy < 0){
            printf("Waktu tidak mencukupi.\n");
    }
    else{
        // Push Aksi
        manact Manact = Amanag(*game);
        MapMaterial MM_AM = AMappingM(Manact);
        Stack Stack_AM = StackAksi(Manact);  
        TimeRemaining(Manact) -= time_for_buy;

        int id = Top(Stack_AM);
        Aksi aksi_build = createAksi(id, 'm');
        PushAksi(&Stack_AM,aksi_build);
        AddEntryMaterial(&MM_AM, CreateMapEMaterial(id, mat_selected));
    }
}

void buyMaterialPop(GAME * game) {
    Aksi aksi_buymat;
    PopAksi(&(StackAksi(Amanag(*game))), &aksi_buymat);
    MATERIAL mat_selected = MMGetMaterial(AMappingM(Amanag(*game)), IDAksi(aksi_buymat));

    manstor Manstor = Smanag(*game);

    ARRAYLISTMAT storageM = StorageM(Manstor);
    int idx_material_selected = SearchIdxMAT(storageM,mat_selected);
    MATERIAL * currMat = &ItemOf(storageM, idx_material_selected);

    int jlhBeli = Punya(mat_selected);

    // tambah jumlah material yang dipunyai player
    Punya(*currMat) += jlhBeli;
    // kurang uang pemain
    float harga = Harga(*currMat) * jlhBeli;
    Money(*game) -= harga;
}

boolean IsBuildAbleSenpai(WAHANA thefkinwahana,GAME *game) {
    // TODO: keliatannya plan ga perlu(?) karena d spek tuh langsung d kasih liat wahana tuh dmna
    manact Manak = Amanag(*game);
    manstor Manstor = Smanag(*game);
    //TODO implement iscollide dari graf buat ngecek nabrak A, O atau tembok
    // Cek tabrakan sama yang plan
    if (!IsStackEmpty(StackAksi(Manak))){
        for (int i = 0; i < Top(StackAksi(Manak)); i++){
            if ((InfoAksi(IsiStack(StackAksi(Manak))[i])) == 'b'){
                WAHANA temp;
                getWahanaa(&Manak, IDAksi(IsiStack(StackAksi(Manak))[i]), &temp);
                if (isCollide(temp,thefkinwahana)) return false;
            }
        }
    }
    // Cek tabrakan sama yang udah dibuat
    for (int i = 0; i < Neff(StorageW(Manstor));i++){
        if (isCollide(thefkinwahana,MWGetWahana(SMappingW(Manstor),i))) return false;
    }
    // Lewat semua cek
    return true;
}

/* Pop sekali
   waktu juga berkurang */
void undo(GAME * game){
    if (!IsStackEmpty(StackAksi(Amanag(*game)))) {
        // ngurusin total aksi yeeeeeeeeeee 
        actionTimes(*game)--;

        Aksi dump;
        PopAksi(&(StackAksi(Amanag(*game))), &dump); // POPPPPPPP
        
        // money money money & time
        float action_price = MoneyUsed(Amanag(*game));
        if (InfoAksi(dump) == 'b' || InfoAksi(dump) == 'u') {
            WAHANA W = MWGetWahana(AMappingW(Amanag(*game)), IDAksi(dump)); // yeet data wahana cuy
            MoneyUsed(Amanag(*game)) -= HargaBuild(W);
            TimeRemaining(Amanag(*game)) += DurasiBuild(W);
        }
        else {
            MATERIAL M = MMGetMaterial(AMappingM(Amanag(*game)), IDAksi(dump)); // yeet data material cuy
            MoneyUsed(Amanag(*game)) -= (Harga(M) * Punya(M));
            TimeRemaining(Amanag(*game)) += (WaktuBeli(M) * Punya(M));
        }
    }
}

/* langsung ke main phase dan kosongkan stack */
void mainphase(GAME * game) {
    Aksi temp;
    while (!IsStackEmpty(StackAksi(Amanag(*game)))) {
        Pop(&(StackAksi(Amanag(*game))), &temp);
    }
    // ini ke main phase
}

/* InverseStack, terus pop 1 per 1 terus jalanin */
void ExecutePhase(GAME * game) {
    // print money skrg, 
    Stack target;
    Aksi temp;
    MakeEmpty(&target);
    InverseStack(&(StackAksi(Amanag(*game))), &target);
    MoveStack(&target, &(StackAksi(Amanag(*game))));    
    while (!IsStackEmpty(StackAksi(Amanag(*game)))) {
        PopAksi(&(StackAksi(Amanag(*game))), &temp);
        if (InfoAksi(temp) == 'b') buildPop(game);
        else if (InfoAksi(temp) == 'u') upgradePop(game);
        else if (InfoAksi(temp) == 'm') buyMaterialPop(game);
    }
}

void Serve(GAME * game) {
    weabooGoToConcert(game);
}