#include "graph.h"

AdrVertex AlokasiVertex (MATRIKS M){
    /* Mengalokasi MATRIKS M dengan edge semuanya menunjuk Nil */
    AdrVertex adrM = (AdrVertex) malloc(sizeof(Vertex) );

    if (adrM != Nil) {
        InfoMATRIKS(adrM) = M;
        Up(adrM) = Nil;
        Left(adrM) = Nil;
        Right(adrM) = Nil;
        Bottom(adrM) = Nil;
    }

    return adrM;
}

Graph InitGraphPeta (MATRIKS M1, MATRIKS M2, MATRIKS M3, MATRIKS M4){
    /* Membuat Graf khusus untuk Peta menerima 4 matriks */
    AdrVertex V1 = AlokasiVertex(M1);
    AdrVertex V2 = AlokasiVertex(M2);
    AdrVertex V3 = AlokasiVertex(M3);
    AdrVertex V4 = AlokasiVertex(M4);

    Right(V1) = V2;
    Bottom(V1) = V4;

    Left(V2) = V1;
    Bottom(V2) = V3;

    Up(V3) = V2;
    Left(V3) = V4;

    Right(V4) = V3;
    Up(V4) = V1;

    return V1;
}

/* *** Update POSISI atau Wahana pada MATRIKS *** */
void MovePlayer (AdrVertex* V, int difX, int difY) {
    int Xbefore = Xplayer(InfoMATRIKS(*V) );
    int Ybefore = Yplayer(InfoMATRIKS(*V) );
    Xplayer(InfoMATRIKS(*V) ) += difX;
    Yplayer(InfoMATRIKS(*V) ) += difY;

    switch (Elmt(InfoMATRIKS(*V) , Yplayer(InfoMATRIKS(*V) ), Xplayer(InfoMATRIKS(*V) ) ) ) {
        case '#':
            Xplayer(InfoMATRIKS(*V) ) -= difX;
            Yplayer(InfoMATRIKS(*V) ) -= difY;
            printf("You've hit a wall!\n");
            break;
        case 'W':
            Xplayer(InfoMATRIKS(*V) ) -= difX;
            Yplayer(InfoMATRIKS(*V) ) -= difY;
            printf("You can't go to the Wahana!\n");
            break;
        case '>':
            Elmt(InfoMATRIKS(*V) , Ybefore, Xbefore) = '.';
            *V = Right(*V);

            for (int i = 0; i <= GetLastIdxBrs(InfoMATRIKS(*V) ); i++){
                for (int j = 0; j <= GetLastIdxKol(InfoMATRIKS(*V) ); j++){
                    if (Elmt(InfoMATRIKS(*V), i, j) == '<') {
                        Xplayer(InfoMATRIKS(*V) ) = j + 1;
                        Yplayer(InfoMATRIKS(*V) ) = i;
                    }
                }   
            }

            Elmt(InfoMATRIKS(*V) , Yplayer(InfoMATRIKS(*V) ), Xplayer(InfoMATRIKS(*V) ) ) = 'P';
            break;
        case '<':
            Elmt(InfoMATRIKS(*V) , Ybefore, Xbefore) = '.';
            *V = Left(*V);

            for (int i = 0; i <= GetLastIdxBrs(InfoMATRIKS(*V) ); i++){
                for (int j = 0; j <= GetLastIdxKol(InfoMATRIKS(*V) ); j++){
                    if (Elmt(InfoMATRIKS(*V), i, j) == '>') {
                        Xplayer(InfoMATRIKS(*V) ) = j - 1;
                        Yplayer(InfoMATRIKS(*V) ) = i;
                    }
                }   
            }

            Elmt(InfoMATRIKS(*V) , Yplayer(InfoMATRIKS(*V) ), Xplayer(InfoMATRIKS(*V) ) ) = 'P';
            break;
        case '^':
            Elmt(InfoMATRIKS(*V) , Ybefore, Xbefore) = '.';
            *V = Up(*V);

            for (int i = 0; i <= GetLastIdxBrs(InfoMATRIKS(*V) ); i++){
                for (int j = 0; j <= GetLastIdxKol(InfoMATRIKS(*V) ); j++){
                    if (Elmt(InfoMATRIKS(*V), i, j) == 'V') {
                        Xplayer(InfoMATRIKS(*V) ) = j;
                        Yplayer(InfoMATRIKS(*V) ) = i - 1;
                    }
                }   
            }

            Elmt(InfoMATRIKS(*V) , Yplayer(InfoMATRIKS(*V) ), Xplayer(InfoMATRIKS(*V) ) ) = 'P';
            break;
        case 'V':
            Elmt(InfoMATRIKS(*V) , Ybefore, Xbefore) = '.';
            *V = Bottom(*V);
            
            for (int i = 0; i <= GetLastIdxBrs(InfoMATRIKS(*V) ); i++){
                for (int j = 0; j <= GetLastIdxKol(InfoMATRIKS(*V) ); j++){
                    if (Elmt(InfoMATRIKS(*V), i, j) == '^') {
                        Xplayer(InfoMATRIKS(*V) ) = j;
                        Yplayer(InfoMATRIKS(*V) ) = i + 1;
                    }
                }   
            }

            Elmt(InfoMATRIKS(*V) , Yplayer(InfoMATRIKS(*V) ), Xplayer(InfoMATRIKS(*V) ) ) = 'P';
            break;
        default:
            Elmt(InfoMATRIKS(*V) , Ybefore, Xbefore) = '.';
            Elmt(InfoMATRIKS(*V) , Yplayer(InfoMATRIKS(*V) ), Xplayer(InfoMATRIKS(*V) ) ) = 'P';
            break;
    }
}

void UpdateMatriksWahana(AdrVertex* V, WAHANA W) {
    if (!(SizeWhn(W) >= NBrsEff(InfoMATRIKS(*V) ) - 1 || SizeWhn(W) <= NKolEff(InfoMATRIKS(*V) ) - 1 ) ){
        Elmt(InfoMATRIKS(*V), Ordinat(LokWhn(W) ), Absis(LokWhn(W) ) ) = 'W';

        int startI = Ordinat(LokWhn(W) ) - SizeWhn(W)/2;
        int endI = Ordinat(LokWhn(W) ) + SizeWhn(W)/2;
        int startJ = Absis(LokWhn(W) ) - SizeWhn(W)/2;
        int endJ = Absis(LokWhn(W) ) + SizeWhn(W)/2;

        for (int i = startI; i <= endI; i++) {
            for (int j = startJ; j <= endJ; j++) {
                Elmt(InfoMATRIKS(*V), i, j) = 'W';
            }
        }

        boolean playerPositionFound = false;
        for (int i = startI - 1; (i <= endI + 1) && !playerPositionFound; i++) {
            for (int j = startJ - 1; (j <= endJ + 1) && !playerPositionFound; j++) {
                if (Elmt(InfoMATRIKS(*V), i, j) == '#' 
                    || Elmt(InfoMATRIKS(*V), i, j) == 'O' 
                    || Elmt(InfoMATRIKS(*V), i, j) == 'A' 
                    || Elmt(InfoMATRIKS(*V), i, j) == 'W') continue;
                else {
                    Xplayer(InfoMATRIKS(*V) ) = j;
                    Yplayer(InfoMATRIKS(*V) ) = i;
                    playerPositionFound = true;
                }
            }
        }
    }
}

/* *** Mengecek Wahana tertabrak Wall atau Antrian atau Office *** */
boolean isCollideWahanaBuilding(AdrVertex* V, WAHANA W) {
    boolean isCollided = false;

    for (int i = Ordinat(LokWhn(W) ); (i <= Ordinat(LokWhn(W) ) + SizeWhn(W)/2) && !isCollided; i++){
        for (int j = Absis(LokWhn(W) ); (j <= Absis(LokWhn(W) ) + SizeWhn(W)/2) && !isCollided; j++){
            if (Elmt(InfoMATRIKS(*V), i, j) == '#' || Elmt(InfoMATRIKS(*V), i, j) == 'O' || Elmt(InfoMATRIKS(*V), i, j) == 'A'){
                isCollided = true;
            }
        }
    }

    for (int i = Ordinat(LokWhn(W) ); (i <= Ordinat(LokWhn(W) ) + SizeWhn(W)/2) && !isCollided; i++){
        for (int j = Absis(LokWhn(W) ); (j >= Absis(LokWhn(W) ) - SizeWhn(W)/2) && !isCollided; j--){
            if (Elmt(InfoMATRIKS(*V), i, j) == '#' || Elmt(InfoMATRIKS(*V), i, j) == 'O' || Elmt(InfoMATRIKS(*V), i, j) == 'A'){
                isCollided = true;
            }
        }
    }

    for (int i = Ordinat(LokWhn(W) ); (i >= Ordinat(LokWhn(W) ) + SizeWhn(W)/2) && !isCollided; i--){
        for (int j = Absis(LokWhn(W) ); (j <= Absis(LokWhn(W) ) + SizeWhn(W)/2) && !isCollided; j++){
            if (Elmt(InfoMATRIKS(*V), i, j) == '#' || Elmt(InfoMATRIKS(*V), i, j) == 'O' || Elmt(InfoMATRIKS(*V), i, j) == 'A'){
                isCollided = true;
            }
        }
    }

    for (int i = Ordinat(LokWhn(W) ); (i >= Ordinat(LokWhn(W) ) + SizeWhn(W)/2) && !isCollided; i--){
        for (int j = Absis(LokWhn(W) ); (j >= Absis(LokWhn(W) ) + SizeWhn(W)/2) && !isCollided; j--){
            if (Elmt(InfoMATRIKS(*V), i, j) == '#' || Elmt(InfoMATRIKS(*V), i, j) == 'O' || Elmt(InfoMATRIKS(*V), i, j) == 'A'){
                isCollided = true;
            }
        }
    }

    return isCollided;
}

boolean isNear(AdrVertex* V, char X){
    return (Elmt(InfoMATRIKS(*V), Yplayer(InfoMATRIKS(*V) ) + 1, Xplayer(InfoMATRIKS(*V) ) ) == X 
            || Elmt(InfoMATRIKS(*V), Yplayer(InfoMATRIKS(*V) ) - 1, Xplayer(InfoMATRIKS(*V) ) ) == X
            || Elmt(InfoMATRIKS(*V), Yplayer(InfoMATRIKS(*V) ), Xplayer(InfoMATRIKS(*V) ) + 1) == X 
            || Elmt(InfoMATRIKS(*V), Yplayer(InfoMATRIKS(*V) ), Xplayer(InfoMATRIKS(*V) ) - 1) == X );
}