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