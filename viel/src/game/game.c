#include <stdio.h>
#include <stdlib.h>
#include "game.h"

GAME createGame() {

}
void action(GAME * game){
    //si game nanya player mau ngapain?
    //- build
    //- beli material
    //- upgrade
    //- execute
    //- undo
    //- mainphase
    char * Ans;
    printf("Apa yang ingin dilakukan?\n");
    scanf("%s", &Ans);    
}

void 

void build(GAME * game) {
    manstor Manstor = Smanag(*game);
    MapWahana MW = SMappingW(Manstor);
    int neffMW = NEff(MW);
    WAHANA* whnlist = MWListWahana(MW);

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

    int selectuser;
    scanf("%d", &selectuser);
    selectuser--;
    WAHANA whn_selected = select[selectuser];
    MATERIAL bahan_whn_selected = Bahan(whn_selected);
    

    ARRAYLISTMAT storageM = StorageM(Manstor);
    int idx_material_selected = SearchIdxMAT(storageM,bahan_whn_selected);
    MATERIAL * currMat = &ItemOf(storageM, idx_material_selected);

    
    int jlhButuh = Punya(bahan_whn_selected);
    int jlhPunya = Punya(*currMat);
    
    
    //TODO dilanjutin, ada masalah materia
    if (jlhPunya < jlhButuh){
        printf("Bahan yang dipunya tidak mencukupi.\n");
    }
    else{
        Punya(*currMat) -= jlhButuh;
    }
    

    /*  Build Wahana
    1. Print List Wahana Dasar -> lgsg aja loop semua wahana yg ada trus print kalau WahanaDasar(W) == true
    2. Pilih wahana dasar -> berarti scanf trus simpen ke WAHANA w
    3. Cek resource dan uang dan waktu -> 
    */
}
/*  Upgrade Wahana 
    1. Print Tree Upgrade
    2. Pilih kanan atau kiri
    3. Cek resource dan uang dan waktu
    4. Push ke stack aksi */
void upgrade(GAME * game){

}

/*  Buy Material
    - Cek input
    - Cek eksistensi id material yang dibeli
    - Kurangi variabel uang global sesuai jumlah
    - 
 */
void buyMaterial(GAME * game, int jumlahBeli, MATERIAL * mat){
    float harga = Harga(*mat) * jumlahBeli;

    if (Money(*game) < harga){
        printf("Uang tidak mencukupi.");
    }
    else{
        Punya(*mat) += jumlahBeli;
        Money(*game) -= harga;
    }

}

// INI MASIH SEREM
/* Pop sekali
   waktu juga berkurang */
void undo(GAME * game){
    if (!IsStackEmpty(StackAksi(Amanag(*game)))){
        Aksi dump;
        PopAksi(&(StackAksi(Amanag(*game))),&dump); //pop dari stack
        WAHANA W = MWGetWahana(AMappingW(Amanag(*game)),IDAksi(dump)); //dapet data wahana
        long total_time = JamToDetik(BuildTime(*game));
        long last_time = JamToDetik(DurasiBangun(W));
        long difference_time = total_time - last_time;
        JAM time_after;
        MakeJamFromDetik(&time_after, difference_time);
        BuildTime(*game) = time_after;
        // MakeJamFromDetik(&BuildTime(*game),JamToDetik(BuildTime(*game))-JamToDetik(DurasiBangun(W)));//kurang waktu total buat bangun
        // apa perlu lakukan sesuatu ke area(?)
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
    Stack target;
    Aksi temp;
    MakeEmpty(&target);
    InverseStack(&(StackAksi(Amanag(*game))), &target);
    while (!IsStackEmpty(target)) {
        PopAksi(&target, &temp);
        // terus ini harusnya execute gitu tergantung dari aksi tempnya naon
    }
}

boolean IsBuildAbleSenpai(WAHANA thefkinwahana,GAME *game){
    manact Manak = Amanag(*game);
    manstor Manstor = Smanag(*game);
    // Cek tabrakan sama yang plan
    if (IsStackEmpty(StackAksi(Manak))){
        for (int i = 0; i < Top(StackAksi(Manak)); i++){
            if ((InfoAksi(IsiStack(StackAksi(Manak))[i])) == 'b'){
                *AFK*
            }
        }
    }
    // Cek tabrakan sama yang udah dibuat
    for (int i = 0; i < Neff(StorageW(Manstor));i++){
        if (isCollide(thefkinwahana,MWGetWahana(SMappingW(Manstor),i))) return false;
    }
}