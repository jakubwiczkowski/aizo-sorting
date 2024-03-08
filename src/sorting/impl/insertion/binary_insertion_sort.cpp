#include "binary_insertion_sort.h"

#include <cmath>
#include <iostream>

template <typename T>
int binary_insertion_sort<T>::get_id() const {
    return 4;
}

template <typename T>
index_t binary_insertion_sort<T>::binary_search(data<T>& to_sort, T item, index_t low, index_t high) {
    while (low != high) {
        index_t mid = low + (high - low) / 2;

        if (item < to_sort[mid])
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

// function binary_search_alternative(A, n, T) is
//     L := 0
//     R := n − 1
//     while L != R do
//         m := ceil((L + R) / 2)
//         if A[m] > T then
//             R := m − 1
//         else:
//             L := m
//     if A[L] = T then
//         return L
//     return unsuccessful

template <typename T>
void binary_insertion_sort<T>::sort(data<T>& to_sort) {
    if (to_sort.get_size() == 1) return;

    for (index_t i = 1; i < to_sort.get_size(); ++i) {
        T key = to_sort[i];
        index_t location = binary_search(to_sort, key, 0, i);

        for (index_t j = i; j > location; --j)
            to_sort[j] = to_sort[j - 1];

        to_sort[location] = key;
    }
}

// procedure binaryInsertionSort(Array)
//     for i = 1 to length(Array) do:
//         key = Array[i]
//         pos = binarySearch(Array, key, 0, i-1)
//         j = i
//         while j > pos
//             Array[j] = Array[j-1]
//             j = j-1
//         Array[pos] = key
//     end for
// end procedure
