#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include "consistent.h"
    #include "parallel.h"
}

std::string path;

bool WorkTimeConsistent() {
    clock_t start = clock();
    consistent_alg();
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time of consistent algorithm - %f seconds\n", seconds);
    return true;
}

bool WorkTimeParallel() {
    clock_t start = clock();
    parallel_alg();
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time of parallel algorithm - %f seconds\n", seconds);
    return true;
}

TEST(rw_comp, timetest1) {
    WorkTimeConsistent(); //измерение времени последовательного алгоритма
}

TEST(rw_comp, timetest2) {
    WorkTimeParallel(); //измерение времени параллельного алгоритма
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}