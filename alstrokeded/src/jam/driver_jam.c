#include "jam.h"
#include<stdio.h>

int main(){
    
    /* IsJamValid*/
    printf("CEK JAM VALID\n");
    if(!IsJamValid(24,61)){
        if(!IsJamValid(0,-1)){
            if(IsJamValid(23,59)) printf("JAM VALID\n");
        }
    }
    printf("\n");
    
    /* MakeJam */
    printf("MAKE JAM\n");
    JAM JTC1a,JTC1b;
    MakeJam(&JTC1a,0,0); TulisJam(JTC1a); printf("\n");
    MakeJam(&JTC1b,23,59); TulisJam(JTC1b); printf("\n");
    printf("\n");

    /* MakeJameFromMenit */
    printf("MAKE JAM FROM MENIT\n");
    JAM JTC2a,JTC2b;
    MakeJamFromMenit (&JTC2a, 120); TulisJam(JTC2a); printf("\n");
    MakeJamFromMenit (&JTC2b, 1439); TulisJam(JTC2b); printf("\n");
    printf("\n");

    /* TimeRemain */
    printf("TIME REMAIN\n");
    TimeRemain (JTC2a); printf("\n");
    TimeRemain (JTC2b); printf("\n");
    printf("\n");

    /* JamToMenit */
    printf("JAM TO MENIT\n");
    int JTC3a,JTC3b;
    JTC3a = JamToMenit (JTC2a); printf("%d\n",JTC3a);
    JTC3b = JamToMenit (JTC2b); printf("%d\n",JTC3b);
    printf("\n");

    /* Boolean Testing */
    printf("BOOLEAN TEST\n");
    JAM JTC4a,JTC4b,JTC4c;
    MakeJam(&JTC4a,10,10); MakeJam(&JTC4b,10,10); MakeJam(&JTC4c,10,9);
    printf("JEQ : "); if(JEQ(JTC4a,JTC4b)) printf("YESS\n");
    printf("JNEQ: "); if(JNEQ(JTC4a,JTC4c)) printf("YESS\n");
    printf("JLT  : "); if(JLT(JTC4c,JTC4b)) printf("YESS\n");
    printf("JGT  : "); if(JGT(JTC4a,JTC4c)) printf("YESS\n");
    printf("\n");

    /* NexPrevMenit */
    printf("NEXT AND PREV\n");
    JAM JTC5a;
    MakeJam(&JTC5a,0,0);
    printf("ORIGINAL : "); TulisJam(JTC5a); printf("\n");
    printf("AFT 10 M : "); TulisJam(NextNMenit(JTC5a,10)); printf("\n");
    printf("BFR 10 M : "); TulisJam(PrevNMenit(JTC5a,10)); printf("\n");
    printf("NXT MIN  : "); TulisJam(NextMenit(JTC5a)); printf("\n");
    printf("PRV MIN  : "); TulisJam(PrevMenit(JTC5a)); printf("\n");
    printf("\n");

    /* Durasi */
    printf("DURASI\n");
    JAM JTC6a, JTC6b, JTC6c;
    MakeJam(&JTC6a,0,0); MakeJam(&JTC6b,12,0); MakeJam(&JTC6c,23,59);
    printf("00.00-12.00\n"); printf("%d\n",Durasi(JTC6a,JTC6b));
    printf("00.00-23.59\n"); printf("%d\n",Durasi(JTC6a,JTC6c));
    printf("12.00-23.59\n"); printf("%d\n",Durasi(JTC6b,JTC6c));
    printf("\n");

    return 0;
}