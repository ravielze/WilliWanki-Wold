#include <stdio.h>
#include <stdlib.h>
#include "game.h"

GAME createGame() {

}
/* Push sekali, napas, push lagi, repeat sampe anaknya keluar
    */
void build(GAME * game) {

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
void buyMaterial(GAME * game, int jumlah, int idMaterial){
    MapMaterial MM = SMappingM(Smanag(*game));

    MATERIAL mat = MMGetMaterial(MM,idMaterial);
    

}

/* Pop sekali
   waktu juga berkurang */
void undo(GAME * game){
    if (!IsStackEmpty(StackAksi(Amanag(*game)))){
        Aksi dump;
        PopAksi(&(StackAksi(Amanag(*game))),&dump); //pop dari stack
        WAHANA W = MWGetWahana(SMappingW(Amanag(*game)),IDAksi(dump)); //dapet data wahana
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