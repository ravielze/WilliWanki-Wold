#include "game.h"

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
        if (off == 1 || off == 2) {
            printf("List wahana tersedia : \n");
            
            int neffMW = NEff(StorageW(Smanag(*game)));
            WAHANA* whnlist = MWListWahana(SMappingW(Smanag(*game)));
            WAHANA select[neffMW];

            // int neffMW = NEff(SMappingW(Smanag(*game)));
            // WAHANA* whnlist = MWListWahana(SMappingW(Smanag(*game)));
            // WAHANA select[neffMW];
            // int counter = 0;
            // for (int i=0 ; i < neffMW; i++){
            //     WAHANA currwhn = whnlist[i];
            //     if (WahanaDasar(currwhn)){
            //         select[i] = currwhn;
            //         printf("%d. ", counter+1);
            //         printf("%s \n", NamaWhn(currwhn));
            //         counter++;
            //     }
            // }

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