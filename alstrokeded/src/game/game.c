#include "game.h"
/* UNTUK INITIALIZATION GAME, BUKAN UNTUK BUAT GAME */
/* F.S  GAME SUDAH DIISI DENGAN DATA YANG DIPERLUKAN*/
GAME createGame() {
    initRNG(); /* RANDOM INITIALIZATION  */
    GAME g;
    float m = 1000;
    JAM j;
    MakeJam(&j, 18, 0);
    boolean mp = false;
    Queue q; CreateEmptyQ(&q);
    createManagerStorage(&g);
    createManagerAction(&g);

    Money(g) = m;
    Time(g) = j;
    CurrDay(g) = 1;
    ExecTimes(g) = 0;
    IsMP(g) = mp;
    actionTimes(g) = 0;
    GameQueue(g) = q;
    
    MATRIKS Peta1, Peta2, Peta3, Peta4;

    InitPeta("./database/peta/peta1.txt", &Peta1);
    InitPeta("./database/peta/peta2.txt", &Peta2);
    InitPeta("./database/peta/peta3.txt", &Peta3);
    InitPeta("./database/peta/peta4.txt", &Peta4);

    initStorageManager("./database/wahana.txt", "./database/material.txt", "./database/treewahana.txt", &Smanag(g) );

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
void buildPush(GAME * game){
    int neffMW = NEff(SMappingW(Smanag(*game)));
    WAHANA* whnlist = MWListWahana(SMappingW(Smanag(*game)));

    // Print list wahana tersedia
    printf("Ingin membangun apa?\n");
    printf("List wahana tersedia : \n");

    int counter = 0;
    WAHANA select[neffMW];
    for (int i=0 ; i < neffMW; i++){
        WAHANA currwhn = whnlist[i];
        if (WahanaDasar(currwhn)){
            select[counter] = currwhn;
            printf("%d. ", (counter+1));
            printf("%s \n", NamaWhn(currwhn));
            counter++;
        }
    }    
    
    // Terima input wahana apa yang dibangun
    int selectuser;
    printf("Input nomor pilihan wahana :  ");
    scanf("%d", &selectuser);
    selectuser--;

    // Validasi
    if (selectuser < 0 || selectuser > counter) {
        printf("Input tidak valid.");
        return;
    }
    WAHANA whn_selected = select[selectuser];

    // Isi lokasi wahana berdasarkan lokasi player
    LokWhn(whn_selected) = getPlayer(Graf(*game));

    // Cek Apakah wahana bisa dibangun
    if (!IsBuildAbleSenpai(whn_selected, game)){
        printf("Wahana tidak bisa dibangun.\n");
    }
    else{
        MATERIAL bahan_whn_selected = Bahan(whn_selected);
        
        int idx_material_selected = SearchIdxMAT(StorageM(Smanag(*game)),bahan_whn_selected);
        MATERIAL * currMat = &(ItemOf(StorageM(Smanag(*game)), idx_material_selected));
        
        int jlhButuh = Punya(bahan_whn_selected);
        int jlhPunya = Punya(*currMat);

        // Cek apakah wahana sudah ada sebelumnya di manstor
        int idx_whn_selected = MWGetKey(SMappingW(Smanag(*game)), whn_selected);
        // Cek wahana ada di manact
        int idx_whn_manact = MWGetKey(AMappingW(Amanag(*game)), whn_selected);
        
        if (idx_whn_manact !=  -1){
            printf("Wahana sudah ada dalam rencana pembangunan.\n");
        }
        else if (SearchAL(StorageW(Smanag(*game)) , idx_whn_selected)){  
            printf("Wahana sudah pernah dibangun.\n");
        }
        else{   
            int time_remain = TimeRemaining(Amanag(*game));
            int time_for_build = DurasiBuild(whn_selected);

            float money_total = Money(*game);
            float money_for_build = HargaBuild(whn_selected);
            float money_used = MoneyUsed(Amanag(*game)); 

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
                // berhasil
                // Tambah action times
                actionTimes(*game)++;

                // Kurangin waktu
                TimeRemaining(Amanag(*game)) -= time_for_build;

                // Kurangin jlh material milik player
                Punya(*currMat) -= jlhButuh;

                // Tambahin duit di Amanag(*game)
                MoneyUsed(Amanag(*game)) += money_for_build;

                // Update Map
                UpdateMatriksWahana(&Graf(*game) , whn_selected);
                
                // Push aksi ke stack
                int id = Top(StackAksi(Amanag(*game))); id++;
                Aksi aksi_build = createAksi(id, 'b');
                PushAksi(&StackAksi(Amanag(*game)),aksi_build);
                AddEntryWahana(&(AMappingW(Amanag(*game))), CreateMapEWahana(id, whn_selected));
            }
        }
    }
}

void buildPop(GAME * game) {
    Aksi aksi_build;
    PopAksi(&(StackAksi(Amanag(*game))), &aksi_build);
    int rid = IsEntryWahana(AMappingW(Amanag(*game)), IDAksi(aksi_build));
    WAHANA whn_selected = value(MapEntry(AMappingW(Amanag(*game)))[rid]);
    MATERIAL bahan_whn_selected = Bahan(whn_selected);

    // // Tes print lokasi
    // TulisPoint(LokWhn(whn_selected));
    // POINT point_player = getPlayer(Graf(*game));
    // TulisPoint(point_player);

    int idx_material_selected = SearchIdxMAT(StorageM(Smanag(*game)),bahan_whn_selected);
    MATERIAL * currMat = &ItemOf(StorageM(Smanag(*game)), idx_material_selected);
    
    int jlhButuh = Punya(bahan_whn_selected);
    
    // kurang jumlah material yang dipunyai player
    Punya(*currMat) -= jlhButuh;

    // kurang duit player
    Money(*game) -= HargaBuild(whn_selected);

    // Delete Entry wahana, add entry baru dengan lokasi benar
    int idWahana = MWGetKey(SMappingW(Smanag(*game)),whn_selected);
    DeleteEntryWahana(&(SMappingW(Smanag(*game))), idWahana);
    AddEntryWahana(&(SMappingW(Smanag(*game))), CreateMapEWahana(idWahana, whn_selected));

    // Insert Wahana ke wahana storage
    InsertLastAL(&(StorageW(Smanag(*game))), idWahana);

}

/* Repair Wahana */
void Repair(GAME *game){
    WAHANA whn_tobe_repaired;
    

    // Traversal dekat wahana di list wahana
    int i = 0;
    boolean found = false;

    // Ambil posisi player
    
    POINT point_player = getPlayer(Graf(*game));

    while (!found && i < NEff(StorageW(Smanag(*game)))) {
        getWahana(&Smanag(*game), ItemOf(StorageW(Smanag(*game)), i), &whn_tobe_repaired);

        if (isNearWahana(point_player, whn_tobe_repaired)) {
            found = true;
        } else {
            i++;
        }
    }    

    // Cek player near suatu wahana
    if (!found){
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
            int waktu_repair = DurasiBuild(whn_tobe_repaired);
            // Harga repair = 1/2 * harga build
            float harga_repair = HargaBuild(whn_tobe_repaired);
            
            // Cek uang cukup atau tidak
            if (Money(*game) < harga_repair){
                printf("Bokek bos, cari duit dulu.\n");
            }
            else{
                // Tambah action times
                actionTimes(*game)++;

                // Jalanin waktu
                TickTime(game, waktu_repair);

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

    // Traversal dekat wahana di list wahana
    int i = 0;
    boolean found = false;

    // Ambil posisi player
    POINT point_player = getPlayer(Graf(*game));

    while (!found && i < NEff(StorageW(Smanag(*game)))) {
        // MWGetWahana ->
        MWGetWahana(&(SMappingW(Smanag(*game) )), ItemOf(StorageW(Smanag(*game)), i), &W);
        // printf("Nama Wahana di UPGRADE: %s\n", NamaWhn(W) );
        // printf("Ukuran Wahana di UPGRADE: %d\n", SizeWhn(W) );
        // printf("Lokasi Wahana di UPGRADE:");TulisPoint(LokWhn(W) );printf("\n"); // (-1, -1)
        if (isNearWahana(point_player, W)) {
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

        // PrintTree(UpgradeTree(W), 2);
        if (Left(UpgradeTree(W) ) == Nil && Right(UpgradeTree(W) ) == Nil){
            printf("Tidak ada upgrade yang tersedia.\n");
            return;
        }
        boolean isLeftAvailable = false;
        boolean isRightAvailable = false;
        printf("List:\n");
        if (Left(UpgradeTree(W)) != Nil){
            int IDL = Akar(Left(UpgradeTree(W)));
            getWahana(&(Smanag(*game)), IDL, &(Upgrade[0]));
            printf("  1. %s\n", NamaWhn(Upgrade[0]));
            isLeftAvailable = true;
        }
        if (Right(UpgradeTree(W)) != Nil){
            int IDR = Akar(Right(UpgradeTree(W)));
            getWahana(&(Smanag(*game)), IDR, &(Upgrade[(isLeftAvailable ? 1 : 0)]));
            printf("  %d. %s\n", (isLeftAvailable ? 2 : 1), NamaWhn(Upgrade[(isLeftAvailable ? 1 : 0)]));
            isRightAvailable = true;
        }
        
        
        // Terima input wahana apa yang dibangun
        int Ans;
        scanf("%d", &Ans);
        if (Ans <= 0 || Ans > 2 || (Ans > isRightAvailable+isLeftAvailable)){
            printf("Tidak valid.\n");
            return;
        }
        Ans--;

        // Wahana tujuan upgrade!
        WAHANA whn_up = Upgrade[Ans];
        MATERIAL bahan_whn_up = Bahan(whn_up);

        int idx_material_up = SearchIdxMAT(StorageM(Smanag(*game)), bahan_whn_up);
        MATERIAL * currMat = &ItemOf(StorageM(Smanag(*game)), idx_material_up);
        
        int jlhButuh = Punya(bahan_whn_up);
        int jlhPunya = Punya(*currMat);

        // Cek apakah wahana sudah ada sebelumnya
        int idx_whn_up = MWGetKey(SMappingW(Smanag(*game)), whn_up);
        
        if (SearchAL(StorageW(Smanag(*game)), idx_whn_up)){
            printf("Wahana sudah pernah dibangun.\n");
        } else {
            int time_remain = TimeRemaining(Amanag(*game));
            int time_for_build = DurasiBuild(whn_up);

            float money_total = Money(*game);
            float money_for_upgrade = HargaBuild(whn_up);
            float money_used = MoneyUsed(Amanag(*game));

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
                
                // Kurang bahan yang kepake
                Punya(*currMat) -= jlhButuh;

                // Kurangin waktu
                TimeRemaining(Amanag(*game)) -= time_for_build;
                
                // Tambah money used
                MoneyUsed(Amanag(*game)) += money_for_upgrade;

                // Samain lokasi whn_up dengan wahana yg akan di upgrade
                LokWhn(whn_up) = LokWhn(W);
                
                // Delete Entry wahana lama
                int idWahana = MWGetKey(SMappingW(Smanag(*game)),W);
                DeleteEntryWahana(&(SMappingW(Smanag(*game))), idWahana);

                // Push aksi ke stack
                int id = Top(StackAksi(Amanag(*game))); id++;
                Aksi aksi_up = createAksi(id, 'u');
                PushAksi(&StackAksi(Amanag(*game)), aksi_up);
                
                AddEntryWahana(&(AMappingW(Amanag(*game))), CreateMapEWahana(id, whn_up));

                printf("Wahana berhasil diupgrade\n");
            }
        }
    }

}

void upgradePop(GAME *game) {
    Aksi aksi_up; /* ID WAHANA */
    PopAksi(&(StackAksi(Amanag(*game))), &aksi_up);
    WAHANA whn_up;
    MWGetWahana(&(AMappingW(Amanag(*game))), IDAksi(aksi_up), &whn_up);
    MATERIAL bahan_whn_up = Bahan(whn_up);
    
    // Apus wahana dasarnya 
    POINT lokasi_whn = LokWhn(whn_up);
    WAHANA whn_before = getWahanaFromPoint(lokasi_whn, Smanag(*game));
    int key = MWGetKey(AMappingW(Amanag(*game)), whn_before);
    deleteWahana(&Smanag(*game), key);
    // Jangan lupa lokasi whn_beforenya jadi null(?) lagi

    
    int idx_material_up = SearchIdxMAT(StorageM(Smanag(*game)),bahan_whn_up);
    MATERIAL * currMat = &ItemOf(StorageM(Smanag(*game)), idx_material_up);
    
    int jlhButuh = Punya(bahan_whn_up);
    
    // kurang jumlah material yang dipunyai player
    Punya(*currMat) -= jlhButuh;

    // kurang duit player
    Money(*game) -= HargaBuild(whn_up);    

    // Update keterangan wahana baru 
    History(whn_up) = History(whn_before);
    InsertLastLL(&History(whn_up), MWGetKey(SMappingW(Smanag(*game)), whn_before));
    MakeEmptyLL(&History(whn_before));

    setRusak(&whn_before, false);
    MakePoint(&LokWhn(whn_before), -1, -1);

    // Delete Entry wahana, add entry baru dengan lokasi benar
    int idWahana = MWGetKey(SMappingW(Smanag(*game)),whn_up);
    DeleteEntryWahana(&(SMappingW(Smanag(*game))), idWahana);
    AddEntryWahana(&(SMappingW(Smanag(*game))), CreateMapEWahana(idWahana, whn_up));

    // Insert Wahana ke wahana storage
    InsertLastAL(&(StorageW(Smanag(*game))), idWahana);
}

void buyMaterialPush(GAME * game){

    // Print List Material
    printf("Ingin membeli apa?\n");
    printf("List Material tersedia :\n");
        
    // ARRAYLISTMAT isinya smua material
    MATERIAL * matList = TI(StorageM(Smanag(*game)));
    MATERIAL select[NEff(StorageM(Smanag(*game)))];
    for (int i=0 ; i < NEff(StorageM(Smanag(*game))) ; i++){
        MATERIAL currMat = matList[i];
        select[i] = currMat;
        printf("%d. ", (i+1));
        printf("%s \n" , Nama(currMat));
    }

    printf("Input jumlah material diikuti nomor pilihan material :  ");
    // Terima input jumlah bahan
    int jumlahBeli;
    scanf("%d", &jumlahBeli);

    // Terima input jenis material
    int selectuser;
    scanf("%d", &selectuser);
    if (selectuser > NEff(StorageM(Smanag(*game))) || selectuser <= 0 || jumlahBeli <= 0){
        printf("Tidak valid.");
        return;
    }
    
    selectuser--;
    MATERIAL mat_selected = select[selectuser];
    // Ubah nilai jumlah pada material yang akan di assert menjadi jumlah yang dibeli
    Punya(mat_selected) = jumlahBeli;

    float hargaBeli = Harga(mat_selected) * jumlahBeli;
    float total_money = Money(*game);
    float money_used = MoneyUsed(Amanag(*game));

    int time_remain = TimeRemaining(Amanag(*game));
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

        // Kurangin waktu remaining
        TimeRemaining(Amanag(*game)) -= time_for_buy * jumlahBeli;

        // Tambahin duit di Amanag(*game)
        MoneyUsed(Amanag(*game)) += hargaBeli;
        printf("money used bertambah\n"); //remove later

        // Push Aksi
        int id = Top(StackAksi(Amanag(*game))); id++;
        Aksi aksi_buy = createAksi(id, 'm');
        PushAksi(&(StackAksi(Amanag(*game))),aksi_buy);
        AddEntryMaterial(&(AMappingM(Amanag(*game))), CreateMapEMaterial(id, mat_selected));
    }
} 

void buyMaterialPop(GAME * game) {
    Aksi aksi_buymat;
    PopAksi(&(StackAksi(Amanag(*game))), &aksi_buymat);
    MATERIAL mat_selected;
    MMGetMaterial(&(AMappingM(Amanag(*game))), IDAksi(aksi_buymat), &mat_selected);

    int idx_material_selected = SearchIdxMAT(StorageM(Smanag(*game)),mat_selected);
    printf("Id material selected : %d\n" , idx_material_selected);

    int jlhBeli = Punya(mat_selected);

    // tambah jumlah material yang dipunyai player
    Punya(ItemOf(StorageM(Smanag(*game)), idx_material_selected)) += jlhBeli;
    printf("Material ditambah\n");
    // kurang uang pemain
    printf("Jlh Beli : %d\n" , jlhBeli);
    printf("Harga Mat : %f\n" , Harga(ItemOf(StorageM(Smanag(*game)), idx_material_selected)));
    float harga = Harga(ItemOf(StorageM(Smanag(*game)), idx_material_selected)) * jlhBeli;
    printf("Harga Total : %f\n" , harga);
    printf("Uang pemain sebelumnya : %f\n", Money(*game));
    Money(*game) -= harga;
    printf("Uang pemain sesudahnya : %f\n\n", Money(*game));
}

boolean IsBuildAbleSenpai(WAHANA thefkinwahana,GAME *game) {
    // manstor Smanag(*game) = Smanag(*game);
    
    // Cek tabrakan sama office sama antrian sama tembok - aldi
    if (isCollideWahanaBuilding(Graf(*game), thefkinwahana)) return false;
    // Cek tabrakan sama yang plan - viel
    if (!IsStackEmpty(StackAksi(Amanag(*game)))){
        for (int i = 0; i < Top(StackAksi(Amanag(*game))); i++){
            if ((InfoAksi(IsiStack(StackAksi(Amanag(*game)))[i])) == 'b'){
                WAHANA temp;
                getWahanaa(&Amanag(*game), IDAksi(IsiStack(StackAksi(Amanag(*game)))[i]), &temp);
                if (isCollide(temp,thefkinwahana)) return false;
            }
        }
    }
    // Cek tabrakan sama yang udah dibuat - viel
    WAHANA whnx;
    for (int i = 0; i < NEff(StorageW(Smanag(*game)));i++){
        MWGetWahana(&(SMappingW(Smanag(*game))), i, &whnx);
        if (isCollide(thefkinwahana, whnx)) return false;
    }
    // Lewat semua cek
    return true;
}

/* Pop sekali
   waktu juga berkurang */
void undo(GAME * game){
    // printf("Dipanggil dmn sih d PLG luar kah?\n");
    if (!IsStackEmpty(StackAksi(Amanag(*game)))) {
        // ngurusin total aksi yeeeeeeeeeee 
        actionTimes(*game)--;

        Aksi dump;
        PopAksi(&(StackAksi(Amanag(*game))), &dump); // POPPPPPPP
        // printf("Dipanggil dmn sih d luar kah?\n");
        // money money money & time
        if (InfoAksi(dump) == 'm') {
            // printf("Dipanggil dmn sih 1?\n");
            MATERIAL M;
            MMGetMaterial(&(AMappingM(Amanag(*game))), IDAksi(dump), &M);
            MoneyUsed(Amanag(*game)) -= (Harga(M) * Punya(M));
            TimeRemaining(Amanag(*game)) += (Waktu(M) * Punya(M));
        } else {
            WAHANA W;
            MWGetWahana(&(AMappingW(Amanag(*game))), IDAksi(dump), &W);
            // printf("%d\n", SizeWhn(W) ); // 0
            MoneyUsed(Amanag(*game)) -= HargaBuild(W);
            TimeRemaining(Amanag(*game)) += DurasiBuild(W);

            // Delete entry pada amanag
            DeleteEntryWahana(&(AMappingW(Amanag(*game))) , IDAksi(dump));

            if (InfoAksi(dump) == 'B' || InfoAksi(dump) == 'b') {
                // printf("Dipanggil dmn sih?\n");
                DeleteMatriksWahana(&(Graf(*game)), W);
            } // UTK U TIDAK PERLU DELETE MATRIKS WAHANA KARENA U SUDAH DIPASTIKAN MEMILIKI UKURAN WAHANA YANG SAMA
        }

        printf("Aksi terakhir berhasil terundo\n");
    }
}

/* langsung ke main phase dan kosongkan stack */
void mainphase(GAME * game) {
    if (CurrDay(*game) <= ExecTimes(*game)){
        printf("Anda sudah melakukan execution/main hari ini.");
        return;
    }
    // cek main phase
    if (IsMP(*game)){
        printf("Lagi main phase bang..\n");
    }
    else{
        IsMP(*game) = true;
        CurrDay(*game)++;
        Aksi temp;
        while (!IsStackEmpty(StackAksi(Amanag(*game)))) {
            PopAksi(&(StackAksi(Amanag(*game))), &temp);
        }
        // Generate Antrian
        GeneratePengunjung(game);
        TimeRemaining(Amanag(*game)) = 720;
        JAM jam_buka; MakeJam(&jam_buka, 6, 0);
        Time(*game) = jam_buka;
        ExecTimes(*game)++;
    }
}

/* InverseStack, terus pop 1 per 1 terus jalanin */
void ExecutePhase(GAME * game) {
    if (CurrDay(*game) <= ExecTimes(*game)){
        printf("Anda sudah melakukan execution/main hari ini.");
        return;
    }
    // cek main phase
    if (IsMP(*game)){
        printf("Lagi main phase bang..\n");
    }
    else{
        printf("Eksekusi..\n");
        // pindah state main phase
        IsMP(*game) = true;
        Stack target;
        Aksi temp;
        MakeStack(&target);
        InverseStack(&(StackAksi(Amanag(*game))), &target);
        MoveStack(&target, &(StackAksi(Amanag(*game))));
        
        /* Do stack actions */
        while (!IsStackEmpty(StackAksi(Amanag(*game) ) ) ) {
            temp = InfoTop(StackAksi(Amanag(*game)));
            if (InfoAksi(temp) == 'b') buildPop(game);
            else if (InfoAksi(temp) == 'u') upgradePop(game);
            else if (InfoAksi(temp) == 'm'){
                buyMaterialPop(game);
            }
        }
        GeneratePengunjung(game);

        // Set variabel jam ke jam buka
        JAM jam_buka; MakeJam(&jam_buka, 6, 0);
        Time(*game) = jam_buka;

        TimeRemaining(Amanag(*game)) = 720;
        // Generate Antrian
        GeneratePengunjung(game);
        
        ExecTimes(*game)++;
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
        ElTypeQ fmv = Info(A);
        int cprio = Prio(A);
        
        /* Send visitor to wahana */
        int idwahanatoride = todonow(fmv);
        Visitor V = fmv;
        WAHANA thewahana;
        MWGetWahana(&(SMappingW(Smanag(*g))), idwahanatoride, &thewahana);
        enqueueWahana(&thewahana, V);
        Money(*g) += HargaTiket(thewahana);
        printf("Nama Wahana : %s" , NamaWhn(thewahana) );
        printf("Harga Tiket : %f\n", HargaTiket(thewahana));

        // Delete Entry wahana, add entry baru dengan Queue baru
        int idWahana = MWGetKey(SMappingW(Smanag(*g)),thewahana);
        DeleteEntryWahana(&(SMappingW(Smanag(*g))), idWahana);
        AddEntryWahana(&(SMappingW(Smanag(*g))), CreateMapEWahana(idWahana, thewahana));

        /* Success Message */
        printf("Berhasil Menge-SERVE\n");
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

    int totaltodo = rand() % todocap;
    int i = 1;
    int selectedid; Aksi selectedAksi;
    while (i < NEff(StorageW(Smanag(*g))) && i < totaltodo){
        selectedid = rand() % (NEff(StorageW(Smanag(*g))));
        if (!isIDInStack(S,selectedid)) {
            selectedAksi = createAksi(ItemOf(StorageW(Smanag(*g)), selectedid),'r');
            PushAksi(&S,selectedAksi);
        }
    }
    return S;
}

/* Force all Visitor to quit if its night time */
void deleteWeaboo(GAME* g) {
    /* REMOVE VISITOR FROM MAIN QUEUE */
    ElTypeQ trash;
    while (IsEmptyQ((GameQueue(*g)))) {
        Dequeue(&GameQueue(*g),&trash);
    }

    int neff = NEff(StorageW(Smanag(*g) ) );
    for (int i = 0; i < neff; i++){
        WAHANA WW;
        MWGetWahana(&(SMappingW(Smanag(*g) )), ItemOf(StorageW(Smanag(*g) ), i), &WW); /* dapet wahana */
        int doctorNEffario = NBElmtQ(QueueWahana(WW));
        for (int j = 0; j < doctorNEffario;j++){
            // temp = StorageW(Smanag(*g));
            dequeueWahana(&WW);
        }
    }
}

void angryWeaboo(GAME*g,int id){
    if (visitorid(Info(Head(GameQueue(*g)))) == id) {
        ElTypeQ dump;
        Dequeue (&GameQueue(*g), &dump);
        Head(GameQueue(*g)) = Next(Head(GameQueue(*g)));
    } else {
        int cnt;
        qaddress A = Head(GameQueue(*g));
        ElTypeQ trashWeaboo;
        while (visitorid(Info(Next(A))) != id) {
            A = Next(A);
            cnt++;
        }
        DequeueN(&GameQueue(*g),&trashWeaboo,cnt);
    }
}

/* Update the Visitor patience and priority depending on the time they enter/re-enter the queue */
void updateWeaboo(GAME*g) {
    JAM time_now = Time(*g);
    int jlh_weaboo = NBElmtQ(GameQueue(*g));

    // qaddress P = Head(GameQueue(*g));
    for (int i = 0; i < jlh_weaboo ; i++){
        // Visitor currV = Info(P);
        // Visitor currV = Info(Head(GameQueue(*g)));
        // JAM time_Visitor = entertime(currV);
        JAM time_Visitor = entertime(Info(Head(GameQueue(*g))));

        int durasi = Durasi(time_Visitor , time_now);

        // Waktu update kesabaran : 10 menit
        int waktu_update_kesabaran = 30;
        
        if (durasi > waktu_update_kesabaran){
            int kesabaran_turun = durasi % waktu_update_kesabaran;
            patience(Info(Head(GameQueue(*g)))) -= kesabaran_turun;

            int menit_hilang = kesabaran_turun * waktu_update_kesabaran;
            entertime(Info(Head(GameQueue(*g)))) = NextNMenit(time_Visitor,menit_hilang);

            // Cek apakah kesabaran habis
            if (patience(Info(Head(GameQueue(*g)))) <= 0){
                angryWeaboo(g, visitorid(Info(Head(GameQueue(*g)))));
            }
        }
    }
}

/* Update the Visitor patience and priority depending on the time they enter/re-enter the queue on Wahana*/
void updateWeabooWahana(GAME*g , WAHANA * whn){
    JAM time_now = Time(*g);
    int jlh_weaboo = NBElmtQ(QueueWahana(*whn));

    // qaddress P = Head(GameQueue(*g));
    for (int i = 0; i < jlh_weaboo ; i++){
        // Visitor currV = Info(P);
        // Visitor currV = Info(Head(QueueWahana(*g)));
        // JAM time_Visitor = entertime(currV);
        int durasi_main = DurasiWhn(*whn);
        int durasi_adadiwahana = Durasi(entertime(Info(Head(QueueWahana(*whn)))) , time_now);
        
        if (durasi_main > durasi_adadiwahana){
            // Enqueue balik ke antrian utama
            getbacktoWeaboo(g,whn);
        }
    }
}

/* prekondisi : stack pasti isi */
void printAnime(Stack S, GAME*g) {
    printf("(");
    Aksi ID;
    MapWahana list_anime;
    WAHANA animenya;
    while (!IsStackEmpty(S)) {
        PopAksi(&S, &ID);
        list_anime = SMappingW(Smanag(*g));
        MWGetWahana(&list_anime, IDAksi(ID), &animenya);
        printf("%s", NamaWhn(animenya));
        if (!IsStackEmpty(S)) printf(",");
    }
    printf(")");
}

// Antrian [1/5] :
// (Wangky’s Universe), kesabaran: 5

// Antrian [2/5] :
// (Wangky’s Universe), kesabaran: 4
// (uWucoaster, Engi’s Descent, Wangky’s Universe), kesabaran: 5

void printWeaboo(GAME* g){
    qaddress A = Head(GameQueue(*g));
    Visitor WEABOO;
    Stack Todo;
    while(A != Nil){
        WEABOO = Info(A);
        if(!inrides(WEABOO)){
            Todo = todo(WEABOO);
            printAnime(Todo,g);
            printf(", kesabaran: %d\n",patience(WEABOO));
        }
        A = Next(A);
    }
}


/* Visitor coming back to queue after the rides */
void getbacktoWeaboo(GAME*g,WAHANA*w) {
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


void WahanaGoBoomBoom(WAHANA*w,GAME*g){
    int WILLITBREAK = rand() % 100;
    ElTypeQ v;
    if (WILLITBREAK < 15) {
        printf("Wahana %s rusak cuy...", NamaWhn(*w));
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
    
    int neff_list_wahana = NEff(StorageW(ms));

    // Search for wahana
    boolean found = false;
    WAHANA curr_whn;
    int i = 0;
    while (!found && i < neff_list_wahana) {
        
        MWGetWahana(&(SMappingW(ms)), ItemOf(StorageW(ms), i), &curr_whn);

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
    // Tambah variabel jam global
    Time(*game) = NextNMenit(Time(*game), mnt_ticks);
    TimeRemaining(Amanag(*game)) -= 1;
    int totalwahana = NEff(StorageW(Smanag(*game)));
    WAHANA whnx;
    for (int i = 0; i < totalwahana; i++){
        getWahana(&(Smanag(*game)), ItemOf(StorageW(Smanag(*game)),i), &whnx);
        WahanaGoBoomBoom(&whnx, game);
    }

    // Cek Hari (Main Phase) udah habis atau blm, kalau habsi pindah ke prep
    JAM jam_buka; MakeJam(&jam_buka, 6, 0);
    JAM jam_tutup; MakeJam(&jam_tutup, 18,0);
    int durasi_main = Durasi(jam_buka, jam_tutup);

    int durasi_skrgtobuka = Durasi(jam_buka , Time(*game));

    if (durasi_skrgtobuka > durasi_main){
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

    MakeStack(&(StackAksi(Amanag(*game))));
    MoneyUsed(Amanag(*game) ) = 0;
    TimeRemaining(Amanag(*game) ) = 720;
    actionTimes(*game) = 0;
    
    // Reset Jam
    JAM jam_buka; MakeJam(&jam_buka, 6, 0);
    Time(*game) = jam_buka;

    // Usir semua pelanggan
    deleteWeaboo(game);
}

/* Office Detail */
void office_detail(GAME *game){
    // Cek is near office
    // Ambil posisi player
    
    if (!isNear(Graf(*game) , 'O')){
        printf("Pergi ke office dulu bos..\n");
    }
    else{
        int off;
        printf("Masukkan perintah:\n1. Details\n2. Report\n3. Exit\n");
        scanf("%d", &off);
        
        if (off == 3) {
            printf("Keluar dari office..\n\n");
        }
        else if (off == 1 || off == 2) {
            printf("List wahana tersedia : \n");
            
            int neffMW = NEff(StorageW(Smanag(*game)));
            // int neffMW = NEff(SMappingW(Smanag(*game)));
            ainfotype* whnlist = TI(StorageW(Smanag(*game)));
            MapWahana MW = SMappingW(Smanag(*game));
            // WAHANA* whnlist = MWListWahana(SMappingW(Smanag(*game)));
            WAHANA select[neffMW];
            int counter = 0;
            WAHANA currwhn;

            if (neffMW == 0) {
                printf("Anda belum membangun wahana sama sekali\n");
                return;
            }

            for (int i=0 ; i < neffMW; i++) {
                MWGetWahana(&MW, whnlist[i], &currwhn);
                select[i] = currwhn;
                printf("%d. ", counter+1);
                printf("%s \n", NamaWhn(currwhn));
                counter++; 
            }

            // Terima input wahana apa yang dibangun
            int selectuser;
            printf("Input nomor pilihan wahana :  ");
            scanf("%d", &selectuser);
            selectuser--;
            WAHANA whn_selected = select[selectuser];

            if (off == 1) printWahanaOffice(whn_selected, game);
            else {
                WAHANA THEWAHANA;
                for (int i=0;i<NEff(StorageW(Smanag(*game)));i++){
                    MWGetWahana(&(SMappingW(Smanag(*game))),ItemOf(StorageW(Smanag(*game)),i), &THEWAHANA);
                    printf("%s | Pelanggan : %d\n", NamaWhn(THEWAHANA),PelangganCounter(THEWAHANA));
                    float penjualan = (PelangganCounter(THEWAHANA) * 1.0F) * HargaTiket(THEWAHANA);
                    printf("%s | Penjualan : %f\n", NamaWhn(THEWAHANA), penjualan);
                }
            }
        }
        else {
            printf("Command tidak ditemukan atau tidak tepat saatnya.");
            office_detail(game);
        }
    }
}

void printWahana (WAHANA w, GAME*g) {
    printf("Nama    : %s\n",NamaWhn(w));
    printf("Lokasi  : "); TulisPoint(LokWhn(w));

    // Upgrade
    printf("\nUpgrade : ");
    WAHANA CWHN;
    printf("[");
    if (Left(UpgradeTree(w)) != Nil) {
        MWGetWahana(&(SMappingW(Smanag(*g))), Akar(Left(UpgradeTree(w))), &CWHN);
        printf("%s",NamaWhn(CWHN));
    }
    if (Right(UpgradeTree(w)) != Nil) {
        MWGetWahana(&(SMappingW(Smanag(*g))), Akar(Right(UpgradeTree(w))), &CWHN);
        printf("%s",NamaWhn(CWHN));
    }
    printf("]\n");

    // History
    printf("History : "); 
    LLaddress a = First(History(w));
    
    while(a != Nil){
        MWGetWahana(&(SMappingW(Smanag(*g))), AInfo(a), &CWHN);
        if (ANext(a) == Nil) printf("%s",NamaWhn(CWHN));
        else {
            printf("%s -> ",NamaWhn(CWHN));
        }
        a = ANext(a);
    }
    // Status
    printf("\nStatus  : ");
    if (RusakGakSih(w)) printf("Tidak berfungsi\n");
    else printf("Berfungsi\n");
}

void printWahanaOffice (WAHANA w,GAME*g) {
    printf("Nama      : %s\n", NamaWhn(w));
    printf("Tipe      : %s\n", TipeWhn(w));
    printf("Harga     : %f\n", HargaTiket(w));
    printf("Lokasi    : "); TulisPoint(LokWhn(w));
    printf("\nDeskripsi : %s\n", DeskripsiWhn(w)); 
    printf("Kapasitas : %d\n", KpstsWhn(w));

    // History
    printf("History   : ");
    LLaddress a = First(History(w));
    WAHANA CWHN;
    while(a != Nil){
        MWGetWahana(&(SMappingW(Smanag(*g))), AInfo(a), &CWHN);
        if (ANext(a) == Nil) printf("%s",NamaWhn(CWHN));
        else {
            printf("%s -> ",NamaWhn(CWHN));
        }
        a = ANext(a);
    }
    
    
    printf("Durasi    : %d\n", DurasiWhn(w));
    printf("Ukuran    : %d\n", SizeWhn(w));
}

/* Detail di samping wahana */
void detail(GAME *game){
    WAHANA W;

    // Traversal dekat wahana di list wahana
    int i = 0;
    boolean found = false;

    // Ambil posisi player
    POINT point_player = getPlayer(Graf(*game));

    while (!found && i < NEff(StorageW(Smanag(*game)))) {
        getWahana(&(Smanag(*game)), ItemOf(StorageW(Smanag(*game)), i), &W);

        if (isNearWahana(point_player, W)) {
            found = true;
        } else {
            i++;
        }
    }

    if (!found){
        printf("Tidak berada di dekat suatu wahana.\n");
    }
    else{
        printWahana(W,game);
    }

}