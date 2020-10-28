#include "parallel.h"

void* threadFunc(void* args){
    data* arg = (data*) args;
    for(int i=arg->value; i < arg->size/(4 * sizeof(int)); i+=4){
        arg->array[i] = arg->value;
    }
    pthread_exit(0);
}

void parallel_alg() {
    int size = 1000000;
    int *mas;
    mas = (int*)malloc(size);
    data temp;
    void* thread_data = NULL;

    //создаем идентификаторы потоков
    pthread_t thread[4];
    temp.array = mas;
    temp.size = size;
    temp.value = 0;
    pthread_create(&thread[0], NULL, threadFunc, (void*) &temp);
    temp.value = 1;
    pthread_create(&thread[1], NULL, threadFunc, (void*) &temp);
    temp.value = 2;
    pthread_create(&thread[2], NULL, threadFunc, (void*) &temp);
    temp.value = 3;
    pthread_create(&thread[3], NULL, threadFunc, (void*) &temp);
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    pthread_join(thread[2], NULL);
    pthread_join(thread[3], NULL);

    free(mas);
}