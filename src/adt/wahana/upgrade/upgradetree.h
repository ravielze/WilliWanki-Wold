/* *** Definisi ABSTRACT DATA TYPE UPGRADE TREE *** */

#ifndef UPGRADE_TREE_H
#define UPGRADE_TREE_H

#include "../../boolean.h"
#include "../wahana.h"

typedef struct upgtree* other;
typedef struct upgtree {
    WAHANA data;
    other left,right;
} UPGRADE_TREE;

void createUpgradeTree(UPGRADE_TREE * uptree);

#endif