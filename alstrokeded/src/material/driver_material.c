#include "material.h"

int main(){
     /* IS EQ? */
    printf("IS EQUAL\n");
    MATERIAL M1 = createMaterial("a", "i", "d", 100, 40.0, 10);
    MATERIAL M2 = createMaterial("a", "i", "d", 100, 40.0, 10);
    if (isMaterialEqual(M1, M2))
    printf("Material 1 dengan material 2 mempunyai kemiripan 100 persen\n");
}