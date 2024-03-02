cmake_minimum_required(VERSION 3.28)
project(aizo_sorting)

set(CMAKE_CXX_STANDARD 17)

add_executable(aizo_sorting_exe src/main.cpp
        src/data/data.h
        src/data/data.cpp
        src/sorting/algorithm.h
        src/sorting/algorithm.cpp
        src/sorting/impl/insertion_sort.h
        src/sorting/impl/insertion_sort.cpp
        src/sorting/impl/bubble_sort.cpp
        src/sorting/impl/bubble_sort.h
        src/sorting/impl/merge_sort.cpp
        src/sorting/impl/merge_sort.h
)
