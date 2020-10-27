#ifndef HW2_PARALLEL_H
#define HW2_PARALLEL_H
#include <pthread.h>
#include <stdio.h>
#include <malloc.h>

void parallel_alg();

void* threadFunc(void* data);

typedef struct data{
    int iterator;
    int value;
    int *array;
} data;

#endif //HW1_PARALLEL_H
