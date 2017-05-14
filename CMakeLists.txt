cmake_minimum_required(VERSION 3.7)
project(algorithms)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c print_array.c insertion_sort.c linear_search.c selection_sort.c merge_sort.c)
add_executable(algorithms ${SOURCE_FILES})
