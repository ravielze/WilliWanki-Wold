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
#define POSLEFT(A) (A).left
#define POSRIGHT(A) (A).right

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

#endif