#include "game.h"


/* UNTUK INITIALIZATION GAME, BUKAN UNTUK BUAT GAME */
/* F.S  GAME SUDAH DIISI DENGAN DATA YANG DIPERLUKAN*/
GAME createGame() {
    // // TODO: pemain belom ;(( mungkin di parameter masukin namanya?
    initRNG(); /* RANDOM INITIALIZATION  */
    GAME g;
    float m = 1000;
    JAM j;
    MakeJam(&j, 21, 0);
    int cd = 0;
    int et = 0;
    int at = 0;
    boolean mp = false;
    Queue q; CreateEmptyQ(&q);
    createManagerStorage(&g);
    createManagerAction(&g);

    Money(g) = m;
    Time(g) = j;
    CurrDay(g) = cd;
    ExecTimes(g) = et;
    IsMP(g) = mp;
    actionTimes(g) = at;
    GameQueue(g) = q;
    
    MATRIKS Peta1, Peta2, Peta3, Peta4;

    InitPeta("./database/peta/peta1.txt", &Peta1);
    InitPeta("./database/peta/peta2.txt", &Peta2);
    InitPeta("./database/peta/peta3.txt", &Peta3);
    InitPeta("./database/peta/peta4.txt", &Peta4);

    initStorageManager("./database/wahana.txt", "./database/material.txt", "./database/treewahana.txt", &Smanag(g) );

    Graph Gr = InitGraphPeta(Peta1, Peta2, Peta3, Peta4);
    Graf(g) = Gr;

    scanf("%d", &Pemain(g) );

    return g;
}

//si game nanya player mau ngapain?
//- build
//- beli material
//- upgrade
//- execute
//- undo

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
            printf("%s \n", NamaWhn(currwhn));
        }
    }    
    
    // TODO validasi
    // Terima input wahana apa yang dibangun
    int selectuser;
    scanf("%d", &selectuser);
    selectuser--;
    WAHANA whn_selected = select[selectuser];

    // Isi lokasi wahana berdasarkan lokasi player
    AdrVertex vertex = Graf(*game);
    POINT player_lokasi = getPlayer(vertex);
    LokWhn(whn_selected) = player_lokasi;
    printf("lokasi wahana sama dengan lokasi player\n"); //remove later

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
        
        if (SearchAL(storageW , idx_whn_selected)){
            printf("Wahana sudah pernah dibangun.\n");
        }
        else{
            manact Manact = Amanag(*game);
            int time_remain = TimeRemaining(Manact);
            int time_for_build = DurasiBuild(whn_selected);

            float money_total = Money(*game);
            float money_for_build = HargaBuild(whn_selected);
            float money_used = MoneyUsed(Manact); 

            if (jlhPunya < jlhButuh){
                printf("Bahan yang dipunya tidak mencukupi.\n");
            }
            else if (time_remain - time_for_build < 0){
                printf("Waktu tidak mencukupi.\n");
            }
            else if (money_used + money_for_build > money_total) {
                printf("Uang tidak mencukupi.\n");
            }
            else{
                // Tambah action times
                actionTimes(*game)++;
                printf("action times bertambah\n"); //remove later

                // Kurangin waktu
                TimeRemaining(Manact) -= time_for_build;
                printf("time remaining berkurang\n"); //remove later

                // Tambahin duit di Manact
                MoneyUsed(Manact) += money_for_build;
                printf("money used bertambah\n"); //remove later

                // Update Map
                UpdateMatriksWahana(&vertex , whn_selected);
                printf("map di update\n"); //remove later

                // Push aksi ke stack
                manact Manact = Amanag(*game);
                MapWahana MW_AM = AMappingW(Manact);
                Stack Stack_AM = StackAksi(Manact);
                
                int id = Top(Stack_AM);
                Aksi aksi_build = createAksi(id, 'b');
                PushAksi(&Stack_AM,aksi_build);
                AddEntryWahana(&MW_AM, CreateMapEWahana(id, whn_selected));
                printf("aksi dipush ke stack\n");
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

/* Repair Wahana */
void Repair(GAME *game){
    WAHANA whn_tobe_repaired;
    manstor Manstor = Smanag(*game);
    ARRAYLIST storageW = StorageW(Manstor);

    // Traversal dekat wahana di list wahana
    int i = 0;
    boolean found = false;

    // Ambil posisi player
    AdrVertex vertex = Graf(*game);
    POINT point_player = getPlayer(vertex);

    while (!found && i < NEff(storageW)) {
        getWahana(&Manstor, ItemOf(storageW, i), &whn_tobe_repaired);

        if (isNearWahana(point_player, whn_tobe_repaired)) {
            found = true;
        } else {
            i++;
        }
    }    

    // Cek player near suatu wahana
    if (found){
        printf("Tidak berdiri di sekitar wahana.\n");
    }
    else{
        // Cek kondisi wahana
        boolean whn_rusak = RusakGakSih(whn_tobe_repaired);
        if (!whn_rusak){
            printf("Wahana tidak rusak, perbaiki matamu saja hehe.\n");
        }
        else{
            // Waktu repair = 1/2 * waktu build
            // int waktu_repair = DurasiBuild(whn_tobe_repaired);
            // Harga repair = 1/2 * harga build
            float harga_repair = HargaBuild(whn_tobe_repaired);
            
            // Cek uang cukup atau tidak
            if (Money(*game) < harga_repair){
                printf("Bokek bos, cari duit dulu.\n");
            }
            else{
                // Tambah action times
                actionTimes(*game)++;

                // TODO : Kurangin waktu

                // Kurangin duit player
                Money(*game) -= harga_repair;

                // Set boolean rusak dari wahana menjadi tidak rusak
                RusakGakSih(whn_tobe_repaired) = false;
            }
        }
    }
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

        // Ambil posisi player
        AdrVertex vertex = Graf(*game);
        POINT point_player = getPlayer(vertex);

        if (isNearWahana(point_player, currwhn)) {
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

            float money_total = Money(*game);
            float money_for_upgrade = HargaBuild(whn_up);
            float money_used = MoneyUsed(Manact);

            if (jlhPunya < jlhButuh){
                printf("Bahan yang dipunya tidak mencukupi.\n");
            } 
            else if (time_remain - time_for_build < 0){
                printf("Waktu tidak mencukupi.\n");
            } 
            else if (money_used + money_for_upgrade > money_total) {
                printf("Uang tidak mencukupi.\n");
            }
            else {
                // Tambah action times
                actionTimes(*game)++;

                // Kurangin waktu
                TimeRemaining(Manact) -= time_for_build;
                
                // Kurangin duit di Manact   
                MoneyUsed(Manact) -= money_for_upgrade;

                // Samain lokasi whn_up dengan wahana yg akan di upgrade
                LokWhn(whn_up) = LokWhn(W);

                // Push aksi ke stack
                manact Manact = Amanag(*game);
                MapWahana MW_AM = AMappingW(Manact);
                Stack Stack_AM = StackAksi(Manact);

                int id = Top(Stack_AM);
                Aksi aksi_up = createAksi(id, 'u');
                PushAksi(&Stack_AM, aksi_up);
                AddEntryWahana(&MW_AM, CreateMapEWahana(id, whn_up));
            }
        }
    }
}

void upgradePop(GAME *game) {
    Aksi aksi_up; /* ID WAHANA */
    PopAksi(&(StackAksi(Amanag(*game))), &aksi_up);
    WAHANA whn_up = MWGetWahana(AMappingW(Amanag(*game)), IDAksi(aksi_up));
    MATERIAL bahan_whn_up = Bahan(whn_up);
        
    manstor Manstor = Smanag(*game);
    
    // Apus wahana dasarnya 
    POINT lokasi_whn = LokWhn(whn_up);
    WAHANA whn_before = getWahanaFromPoint(lokasi_whn, Manstor);
    MapWahana MW = AMappingW(Amanag(*game));
    int key = MWGetKey(MW, whn_before);
    deleteWahana(&Manstor, key);
    // Jangan lupa lokasi whn_beforenya jadi null(?) lagi

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

    MapWahana MWd = SMappingW(Manstor);
    int idWahana = MWGetKey(MWd,whn_up);
    InsertLastAL(&whn_storage, idWahana);

    // TODO: Update keterangan wahana baru -> afaik point, history, 
    /*
    List history;  -> copy ke whn_up, whn_before jadi null
    boolean rusak; -> whn_before jadi false
    POINT lokasi;  -> whn_up jadi lokasi whn_before, whn_before jadi null(?)
    int vertex;    -> 
    */
    // AAA PUYENG
    InsertLastAL(&whn_storage, idWahana);

    // TODO: Update keterangan wahana baru -> afaik point, history, 
    /*
    List history;  -> copy ke whn_up, whn_before jadi null
    boolean rusak; -> whn_before jadi false
    POINT lokasi;  -> whn_up jadi lokasi whn_before, whn_before jadi null(?)
    int vertex;    -> 
    */
    // AAA PUYENG
    InsertLastAL(&whn_storage, idWahana);

    // TODO: Update keterangan wahana baru -> afaik point, history, 
    /*
    List history;  -> copy ke whn_up, whn_before jadi null
    boolean rusak; -> whn_before jadi false
    POINT lokasi;  -> whn_up jadi lokasi whn_before, whn_before jadi null(?)
    int vertex;    -> 
    */
    // AAA PUYENG
    InsertLastAL(&whn_storage, idWahana);

    // TODO: Update keterangan wahana baru -> afaik point, history, 
    /*
    List history;  -> copy ke whn_up, whn_before jadi null
    boolean rusak; -> whn_before jadi false
    POINT lokasi;  -> whn_up jadi lokasi whn_before, whn_before jadi null(?)
    int vertex;    -> 
    */
    // AAA PUYENG
    InsertLastAL(&whn_storage, idWahana);

    // TODO: Update keterangan wahana baru -> afaik point, history, 
    /*
    List history;  -> copy ke whn_up, whn_before jadi null
    boolean rusak; -> whn_before jadi false
    POINT lokasi;  -> whn_up jadi lokasi whn_before, whn_before jadi null(?)
    int vertex;    -> 
    */
    // AAA PUYENG
    InsertLastAL(&whn_storage, idWahana);

    // TODO: Update keterangan wahana baru -> afaik point, history, 
    /*
    List history;  -> copy ke whn_up, whn_before jadi null
    boolean rusak; -> whn_before jadi false
    POINT lokasi;  -> whn_up jadi lokasi whn_before, whn_before jadi null(?)
    int vertex;    -> 
    */
    // AAA PUYENG
}

void buyMaterialPush(GAME * game){
    manstor Manstor = Smanag(*game);
    manact Manact = Amanag(*game);

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
    float total_money = Money(*game);
    float money_used = MoneyUsed(Manact);

    int time_remain = TimeRemaining(Manact);
    int time_for_buy = Waktu(mat_selected);

    if (money_used + hargaBeli > total_money){
        printf("Uang tidak mencukupi.\n");
    }
    else if (time_remain - time_for_buy < 0){
            printf("Waktu tidak mencukupi.\n");
    }
    else{
        // Tambah action times
        actionTimes(*game)++;
        printf("Action times bertambah.\n"); // remove later

        // Push Aksi
        MapMaterial MM_AM = AMappingM(Manact);
        Stack Stack_AM = StackAksi(Manact);  
        TimeRemaining(Manact) -= time_for_buy;

        int id = Top(Stack_AM);
        Aksi aksi_buy = createAksi(id, 'm');
        PushAksi(&Stack_AM,aksi_buy);
        AddEntryMaterial(&MM_AM, CreateMapEMaterial(id, mat_selected));
        printf("Aksi dipush.\n"); // remove later
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
    AdrVertex V = Graf(*game);
    // Cek tabrakan sama office sama antrian sama tembok - aldi
    if (isCollideWahanaBuilding(V, thefkinwahana)) return false;
    // Cek tabrakan sama yang plan - viel
    if (!IsStackEmpty(StackAksi(Manak))){
        for (int i = 0; i < Top(StackAksi(Manak)); i++){
            if ((InfoAksi(IsiStack(StackAksi(Manak))[i])) == 'b'){
                WAHANA temp;
                getWahanaa(&Manak, IDAksi(IsiStack(StackAksi(Manak))[i]), &temp);
                if (isCollide(temp,thefkinwahana)) return false;
            }
        }
    }
    // Cek tabrakan sama yang udah dibuat - viel
    for (int i = 0; i < NEff(StorageW(Manstor));i++){
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

        manact Manact = Amanag(*game);
        AdrVertex V = Graf(*game);

        Aksi dump;
        PopAksi(&(StackAksi(Amanag(*game))), &dump); // POPPPPPPP
        
        // money money money & time
        if (InfoAksi(dump) == 'm') {
            MATERIAL M = MMGetMaterial(AMappingM(Manact), IDAksi(dump));
            MoneyUsed(Manact) -= (Harga(M) * Punya(M));
            TimeRemaining(Manact) += (Waktu(M) * Punya(M));
        }
        else {
            WAHANA W = MWGetWahana(AMappingW(Manact), IDAksi(dump));
            MoneyUsed(Manact) -= HargaBuild(W);
            TimeRemaining(Manact) += DurasiBuild(W);
            if (InfoAksi(dump) == 'b') {
                DeleteMatriksWahana(&V, W);
            }
        }
    }
}

/* langsung ke main phase dan kosongkan stack */
void mainphase(GAME * game) {
    // TODO: state main phase,
    Aksi temp;
    while (!IsStackEmpty(StackAksi(Amanag(*game)))) {
        PopAksi(&(StackAksi(Amanag(*game))), &temp);
    }
    // ini ke main phase
}

/* InverseStack, terus pop 1 per 1 terus jalanin */
void ExecutePhase(GAME * game) {
    // TODO: state main phase
    Stack target;
    Aksi temp;
    MakeStack(&target);
    InverseStack(&(StackAksi(Amanag(*game))), &target);
    MoveStack(&target, &(StackAksi(Amanag(*game))));
    
    /* Do stack actions */
    while (!IsStackEmpty(StackAksi(Amanag(*game)))) {
        temp = InfoTop(StackAksi(Amanag(*game)));
        if (InfoAksi(temp) == 'b') buildPop(game);
        else if (InfoAksi(temp) == 'u') upgradePop(game);
        else if (InfoAksi(temp) == 'm') buyMaterialPop(game);
    }

    ExecTimes(*game)++;
    if (ExecTimes(*game) < CurrDay(*game)) {
        /* After finish building */
        GeneratePengunjung(game); /* GENERATING START QUEUE */
    }
}

void Serve(GAME * g) {
    qaddress A = Head(GameQueue(*g));
    int indexx;

    

    while (A != Nil && inrides(Info(A))) {//Traversal untill found somone not in rides or till end of queue
        A = Next(A);
        indexx++;
    }
    if (A != Nil) { /* Found Visitor foremost Visitor that is not in rides */
        /* Get used data */
        ElTypeQ fmv;
        int cprio = Prio(A);

        /* Send visitor to wahana */
        int idwahanatoride = todonow(fmv); /* TO DO : GATAU QUEUE WAHANA DIMANA, JADI GATAU MAU DIAPAIN WAKAWKWAKKAW */
        Visitor V = fmv;
        WAHANA thewahana = MWGetWahana(SMappingW(Smanag(*g)),idwahanatoride);
        enqueueWahana(&thewahana, V);
        Money(*g) += HargaTiket(thewahana);

        /* Delete from todo list */
        Aksi dump;
        PopAksi(&todo(V),&dump); 
        /* Re enter queue with prio + 1 */
        if (IsStackEmpty(todo(V))) { /* Visitor has completed his/her to do list */
            DequeueN(&(GameQueue(*g)),&fmv,indexx);
        }
        else { /* Visitor has not yet completed his/her to do list */
            DequeueN(&(GameQueue(*g)),&fmv,indexx); //TODO topher
            Enqueue(&GameQueue(*g),fmv,cprio+1);
        }
    }
}

void GeneratePengunjung (GAME * g) {
    Visitor genV;
    int maxVisitor = 5; /* CHANGE THIS TO CHANGE NUMBER OF VISITOR */
    int theVisitor = rand() & maxVisitor;

    /* Check if there a wahana exist or not */
    if (!IsALEmpty(StorageW(Smanag(*g)))){
        int id;
        for (int i = 0; i < theVisitor; i++){
            id = theVisitor-i; /* Create Visitor id */
            genV = SpawnVisitor(id,g);
            Enqueue(&GameQueue(*g),genV,0); /* Put Visitor in queue with 0 priority at start */
        }
    }
}

/* Ambil wahana yang ingin dinaiki (paling atas stack) */
int todonow(Visitor v){
    int idwahana = -1;
    if (!IsStackEmpty(todo(v))){
        idwahana = IDAksi(InfoTop(todo(v)));
        return idwahana;
    }
    return idwahana;
}

/* Spawn Visitor */
Visitor SpawnVisitor(int id, GAME * g){
    Visitor v;
    int startpatience = 10; /* EDIT THIS TO CHANGE START PATIENCE, 0 PATIENCE MEANS VISITOR LEAVE */
    visitorid(v) = id;
    todo(v) = generateToDo(g);
    patience(v) = startpatience;
    entertime(v) = Time(*g);
    inrides(v) = false;
    return v;
}

/* Menggenerate to do list Visitor */
Stack generateToDo(GAME *g){
    Stack S;

    int todocap = 10; /* jumlah wahana yang akan dinaiki */

    ARRAYLIST ownedrides = StorageW(Smanag(*g));

    int totaltodo = rand() % todocap;
    int i = 1;
    int selectedid; Aksi selectedAksi;
    while (i < NEff(ownedrides) && i < totaltodo){
        selectedid = rand() % (NEff(ownedrides));
        if (!isIDInStack(S,selectedid)) {
            selectedAksi = createAksi(ItemOf(ownedrides, selectedid),'r');
            PushAksi(&S,selectedAksi);
        }
    }
    return S;
}

/* Force all Visitor to quit if its night time */
void deleteWeaboo(GAME* g) {
    int neff = NEff(StorageW(Smanag(*g) ) );
    // ARRAYLIST temp;
    for (int i = 0; i < neff; i++){
        WAHANA WW = MWGetWahana(SMappingW(Smanag(*g) ), ItemOf(StorageW(Smanag(*g) ), i) ); /* dapet wahana */
        int doctorNEffario = NBElmtQ(QueueWahana(WW));
        for (int j = 0; j < doctorNEffario;j++){
            // temp = StorageW(Smanag(*g));
            dequeueWahana(&WW);
        }
    }
}

/* Update the Visitor patience and priority depending on the time they enter/re-enter the queue */
void updateWeaboo(GAME*g) {
    JAM time_now = Time(*g);
    Queue antrian = GameQueue(*g);
    int jlh_weaboo = NBElmtQ(antrian);

    qaddress P = Head(antrian);
    for (int i = 0; i < jlh_weaboo ; i++){
        Visitor currV = Info(P);
        JAM time_Visitor = entertime(currV);
        long durasi = Durasi(time_Visitor , time_now);

        // Waktu update kesabaran : 10 menit
        long waktu_update_kesabaran = 30;
        
        if (durasi > waktu_update_kesabaran){
            int kesabaran_turun = durasi % waktu_update_kesabaran;
            patience(currV) -= kesabaran_turun;

            // TODO : JAM tiap Visitor di update tiap kesabaran naik (?)
            int menit_hilang = kesabaran_turun * waktu_update_kesabaran;
            entertime(currV) = NextNMenit(time_Visitor,menit_hilang);
        }
    }
}

/* Visitor coming back to queue after the rides */
void getbacktoWeaboo(GAME*g,WAHANA*w) {
    /* TO DO : GET VISITOR FROM WAHANA, CURRENTLY UNKNOW SINCE WAHANA DOESNT HAVE QUEUE */
    /* Get visitor id from dequeued wahana */
    int vid = dequeueWahana(w); 

    qaddress A = Head(GameQueue(*g));
    while (A != Nil && visitorid(Info(A)) != vid) A = Next(A); /* Travesal until visitorid(A) is vid */
    if (visitorid(Info(A)) == vid) inrides(Info(A)) = false; /* Visitor has yet finished rides he/she want */
    /* else : Visitor is not found in main queue (has finished all rides he/she wanted) */
}

time_t t;

void initRNG(){
    srand((unsigned) time(&t));
}
//NOTE jgn lupa kasih fungsi kalau tiba2 wahana rusak, atau emang udah ada subtitusinya?
/*

void angryWeaboo(GAME*g,int id){
    if (visitorid(Info(Head(GameQueue(*g)))) == id) {
        ElTypeQ dump;
        Dequeue (&GameQueue(*g), &dump);
        Head(GameQueue(*g)) = Next(Head(GameQueue(*g)));
    } else {
        qaddress A = Head(GameQueue(*g));
        while (visitorid(Info(Next(A))) != id) A = Next(A);
    }
}

*/
void WahanaGoBoomBoom(WAHANA*w,GAME*g){
    int WILLITBREAK = rand() % 100;
    ElTypeQ v;
    if (WILLITBREAK < 15) {
        RusakGakSih(*w) = true;
        qaddress A; int cid;
        int cnt; Visitor dump;
        int ZaPrio = Prio(Head(GameQueue(*g))) + 1;
        for (int i = 0; i < NBElmtQ(QueueWahana(*w)); i++){
            Dequeue(&QueueWahana(*w),&v);
void WahanaGoBoomBoom(WAHANA*w,GAME*g){
    int WILLITBREAK = rand() % 100;
    ElTypeQ v;
    if (WILLITBREAK < 15) {
        RusakGakSih(*w) = true;
        qaddress A; int cid;
        int cnt; Visitor dump;
        int ZaPrio = Prio(Head(GameQueue(*g))) + 1;
        for (int i = 0; i < NBElmtQ(QueueWahana(*w)); i++){
            Dequeue(&QueueWahana(*w),&v);
void WahanaGoBoomBoom(WAHANA*w,GAME*g){
    int WILLITBREAK = rand() % 100;
    ElTypeQ v;
    if (WILLITBREAK < 15) {
        RusakGakSih(*w) = true;
        qaddress A; int cid;
        int cnt; Visitor dump;
        int ZaPrio = Prio(Head(GameQueue(*g))) + 1;
        for (int i = 0; i < NBElmtQ(QueueWahana(*w)); i++){
            Dequeue(&QueueWahana(*w),&v);
            cid = visitorid(v);
            A = Head(GameQueue(*g)); cnt = 0;
            while(A != Nil && visitorid(Info(A)) != cid){
                A = Next(A);
                cnt++;
            }
            visitorid(v) = false;
            DequeueN(&GameQueue(*g),&dump,cnt);
            Enqueue(&GameQueue(*g),v,ZaPrio);
        }
    }
}

/* Get wahana dari point */
WAHANA getWahanaFromPoint(POINT P, manstor ms) {
    // Load lists
    ARRAYLIST list_wahana = StorageW(ms);
    MapWahana map_wahana = SMappingW(ms);
    
    int neff_list_wahana = NEff(list_wahana);

    // Search for wahana
    boolean found = false;
    WAHANA curr_whn;
    int i = 0;
    while (!found && i < neff_list_wahana) {
        
        curr_whn = MWGetWahana(map_wahana, ItemOf(list_wahana, i));

        // Bandingkan point
        if (PEQ(P, LokWhn(curr_whn))) {
            found = true;
        } else {
            i++;
        }
    }
    return curr_whn;
}

/* Tick Waktu N Menit */
void TickTime(GAME *game , int mnt_ticks){
    JAM jam_skrg = Time(*game);

    // Tambah variabel jam global
    jam_skrg = NextNMenit(jam_skrg, mnt_ticks);

    // Cek Hari (Main Phase) udah habis atau blm, kalau habsi pindah ke prep
    JAM jam_buka; MakeJam(&jam_buka, 9, 0);
    JAM jam_tutup; MakeJam(&jam_tutup, 18,0);
    int durasi_main = Durasi(jam_buka, jam_tutup);

    int durasi_skrgtobuka = Durasi(jam_buka , jam_skrg);
    if (durasi_skrgtobuka >= durasi_main){
        GoToPrepare(game);
    }
    else{
        // Cek apakah kesabaran visitor naik
        updateWeaboo(game);
    }
}

/* Go to Preparation Phase */
void GoToPrepare(GAME *game){
    // Tambah variabel jumlah day yang sudah dilewati
    CurrDay(*game)++;

    // Ganti boolean IsMainPhase
    IsMP(*game) = false;

    // Usir semua pelanggan
    deleteWeaboo(game);
}