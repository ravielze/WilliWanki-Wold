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

void UpdateMatriksWahana(AdrVertex* V) {

}