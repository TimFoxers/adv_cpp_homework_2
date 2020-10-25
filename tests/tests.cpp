#include <gtest/gtest.h>
#include <iostream>
#include <cerrno>
#include <fstream>

extern "C" {
    #include "consistent.h"
}

std::string path;

bool WorkTime() {
    clock_t start = clock();
    consistent_alg();
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time of consistent algorithm - %f seconds\n", seconds);
    return true;
}

TEST(rw_comp, timetest) {
    WorkTime();
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}