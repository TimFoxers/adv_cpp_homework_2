#include "consistent.h"

void consistent_alg() {
    int size = 1000000;
    int *mas;
    mas = (int*)malloc(size);
    for(int i=0; i < size/sizeof(int); i++){
        mas[i] = i%4;
    }
    free(mas);
}

