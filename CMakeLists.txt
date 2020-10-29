project(hw2)
cmake_minimum_required(VERSION 3.9)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)


add_executable(run src/main.c src/consistent.c include/consistent.h src/parallel.c include/parallel.h)
target_include_directories(run PUBLIC include)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(run Threads::Threads)

add_executable(tests tests/tests.cpp src/consistent.c include/consistent.h src/parallel.c include/parallel.h)
find_package(GTest REQUIRED)
target_include_directories(tests PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
target_include_directories(tests PUBLIC include)
enable_testing()
add_test(gtests ./tests)