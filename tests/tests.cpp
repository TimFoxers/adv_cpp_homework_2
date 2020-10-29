#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include "consistent.h"
    #include "parallel.h"
}

std::string path;

double WorkTimeConsistent() {
    clock_t start = clock();
    consistent_alg();
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time of consistent algorithm - %f seconds\n", seconds);
    return seconds;
}

double WorkTimeParallel() {
    clock_t start = clock();
    parallel_alg();
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time of parallel algorithm - %f seconds\n", seconds);
    return seconds;
}

TEST(rw_comp, timetest1) {
    double time = WorkTimeConsistent(); //измерение времени последовательного алгоритма
    ASSERT_LT(time, 1);
}

TEST(rw_comp, timetest2) {
    double time = WorkTimeParallel(); //измерение времени параллельного алгоритма
    ASSERT_LT(time, 1);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}