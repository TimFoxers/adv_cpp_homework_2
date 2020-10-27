#include "parallel.h"
#include <stdio.h>

void* threadFunc(void* args){
    data* arg = (data*) args;
    arg->array[arg->iterator] = arg->value;
    pthread_exit(0);
}

int parallel_alg() {
    int size = 250000;
    int mas[size];
    data temp;
    void* thread_data = NULL;

    //создаем идентификаторы потоков
    pthread_t thread[4];
    temp.array = mas;
    for(int i=0; i < size/4; i+=4){ //разделяем цикл на 4 потока, благодаря чему он проходит в 4 раза меньше итераций
        temp.iterator = i; // каждый поток присваивает одно из 4-х значений
        temp.value = 0;
        pthread_create(&thread[0], NULL, threadFunc, (void*) &temp);
        temp.iterator = i + 1;
        temp.value = 1;
        pthread_create(&thread[1], NULL, threadFunc, (void*) &temp);
        temp.iterator = i + 2;
        temp.value = 2;
        pthread_create(&thread[2], NULL, threadFunc, (void*) &temp);
        temp.iterator = i + 3;
        temp.value = 3;
        pthread_create(&thread[3], NULL, threadFunc, (void*) &temp);
        pthread_join(thread[0], NULL);
        pthread_join(thread[1], NULL);
        pthread_join(thread[2], NULL);
        pthread_join(thread[3], NULL);
    }

    return 0;
}