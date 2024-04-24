#include "binary_insertion_sort.h"

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
