/* *** Definisi ABSTRACT DATA TYPE UPGRADE TREE *** */

#ifndef UPGRADE_TREE_H
#define UPGRADE_TREE_H

#include "../boolean.h"
#include "../wahana/wahana.h"

typedef struct upgtree* other;
typedef struct upgtree {
    WAHANA wahana;
    float price;
    other left,right;
} UPGRADE_TREE;

#define Price(UT) (UT).price
#define Wahana(UT) (UT).wahana

#endif