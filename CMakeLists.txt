cmake_minimum_required(VERSION 3.28)
project(aizo_sorting)

set(CMAKE_CXX_STANDARD 17)

add_executable(aizo_sorting_exe src/main.cpp
        src/data/data.h
        src/data/data.cpp
        src/sorting/algorithm.h
        src/sorting/algorithm.cpp
        src/sorting/impl/insertion/insertion_sort.h
        src/sorting/impl/insertion/insertion_sort.cpp
        src/sorting/impl/bubble/bubble_sort.cpp
        src/sorting/impl/bubble/bubble_sort.h
        src/sorting/impl/merge/merge_sort.cpp
        src/sorting/impl/merge/merge_sort.h
        src/sorting/impl/insertion/binary_insertion_sort.cpp
        src/sorting/impl/insertion/binary_insertion_sort.h
        src/sorting/impl/heap/heap_sort.cpp
        src/sorting/impl/heap/heap_sort.h
        src/sorting/impl/quick/quick_sort.cpp
        src/sorting/impl/quick/quick_sort.h
        src/sorting/impl/shell/shell_sort.cpp
        src/sorting/impl/shell/shell_sort.h
        src/menu/menu.cpp
        src/menu/menu.h
        src/menu/menu.cpp
        src/menu/menu.h
)
target_link_options(aizo_sorting_exe PRIVATE -static-libgcc -static-libstdc++ -lwinpthread -static)