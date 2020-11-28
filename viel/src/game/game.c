#include <stdio.h>
#include <stdlib.h>
#include "game.h"

GAME createGame() {

}
/* Push sekali, napas, push lagi, repeat sampe anaknya keluar
    */
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
    
    //TODO cek is collide / tabrakan sama wahana lain
    MapMaterial MM = SMappingM(Manstor);
    MATERIAL * matlist = MMListMaterial(MM);
    int neffMM = NEff(MM);
    
    for (int i=0; i < neffMM; i++){
        MATERIAL currmat = matlist[i];
        if (isMaterialEqual(currmat,bahan_whn_selected)){
            
        }
    }

    int jlhButuh = Punya(bahan_whn_selected);
    int jlhPunya = Punya
    

    /*  Build Wahana
    1. Print List Wahana Dasar -> lgsg aja loop semua wahana yg ada trus print kalau WahanaDasar(W) == true
    2. Pilih wahana dasar -> berarti scanf trus simpen ke WAHANA w
    3. Cek resource dan uang dan waktu -> 
    4. Push ke stack aksi */
// lu tanya mau bangun apa pake scanf berarti
// cek bahannya cukup atau engga
// kalau cukup, masukin ke stack aksi
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