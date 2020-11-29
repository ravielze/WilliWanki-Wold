#include "stack.h"
#include "../constant/adt.h"
#include "../constant/selector.h"

int main() {
    /* CREATE EMPTY */
    Stack setek;
    MakeStack(&setek);
    Aksi aksi = createAksi(1, 's');

    /* IS EMPTY */
    printf("IS EMPTY\n");
    if (IsStackEmpty(setek)) printf("Stack kosong\n");

    /* IS FULL */
    printf("\nIS FULL\n");
    if (!IsStackFull(setek)) printf("Stack tidak penuh\n");
    
    /* pus pop */
    Aksi ak_si = createAksi(2, 'l');
    
    PushAksi(&setek, aksi);
    PopAksi(&setek, &ak_si);

    /* invers */
    Aksi aksi1, aksi2;
    aksi1 = createAksi(2, 'b');
    aksi2 = createAksi(3, 'm');
    PushAksi(&setek, aksi1);
    PushAksi(&setek, aksi2);
    
    printf("halo toper\n");
    Stack se_tek;
    MakeStack(&se_tek);
    InverseStack(&setek, &se_tek);
    
    /* IS ID IN SETEK */
    printf("\nPUNTEN ADA GA SIH IDNYA\n");
    // KEPOTONG DISINI(?) // ho oh oh ho KOBISA EROR
    if (isIDInStack(se_tek, 3)) printf("ADAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA lovelace\n");
    
    /* MUF */ // DISINI SEGMEN FOLTNYA
    Stack set_ek; // SET EK WKAKWAKWKKWAKAWKAWKWAKWAKAWKKWAKWAKAWKAWKKWAKWAKWAKAWKKWKWAK
    MoveStack(&se_tek, &set_ek);
    
    return 0;//
}