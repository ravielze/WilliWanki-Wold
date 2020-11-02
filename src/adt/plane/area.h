/* *** Definisi ABSTRACT DATA TYPE AREA *** */

#ifndef AREA_H
#define AREA_H

#include "../boolean.h"
#include "point.h"

typedef struct {
	POINT left;
	POINT right;
} AREA;

/* *** Notasi Akses: Selektor AREA *** */
#define POSL(A) (A).left // Alias POS LEFT
#define POSR(A) (A).right // Alias POS RIGHT

/**
 * OOOOOO
 * OXXXBO
 * OXXXXO
 * OAXXXO
 * OOOOOO
 * 
 * A = POINT left
 * X = Didalam Area
 * O = Diluar Area
 * B = POINT right
 * 
 * Asumsi left selalu dibawah kiri, dan right selalu diatas kanan
*/

/* *** Definisi Prototipe Primitif *** */
/* *** Validasi Terhadap Type *** */
boolean isAreaValid(POINT P1, POINT P2);
void fixArea(AREA *A);
/* Digunakan untuk mengubah POS LEFT POS RIGHT sesuai Asumsi */
/* Prekondisi: A sudah memiliki point. */

/* *** Konstruktur Area *** */
void MakeArea(AREA *A, POINT P1, POINT P2);
/* Prekondisi: P1 dan P2 Adalah point yang valid untuk membuat sebuah area. */

/* *** Operasi Relasional *** */
boolean AEQ (AREA A1, AREA A2);
boolean ANEQ (AREA A1, AREA A2);

/* *** Operasi Lain-Lain *** */
float AWidth(AREA A);
/* Mencari Panjang Area secara Horizontal*/

float AHeight(AREA A);
/* Mencari Panjang Area secara Vertikal*/

float ASize(AREA A);
/* Mendapatkan ukuran/luas dari sebuah area */
void AGeser(AREA *A, float deltaX, float deltaY);
/* Menggeser Area sebanyak deltaX horizontal dan deltaY vertikal */
void AMirror(AREA *A, boolean SbX);
/* Memindahkan Area dengan pencerminan terhadap salah satu sumbu */
void Putar(AREA *A, float Sudut);
/* Memutar sebuah area */

boolean IsInside(POINT P, AREA A);
/* Mengecek apakah poin didalam area */


#endif