#include "quick_sort.h"

template <typename T>
int quick_sort<T>::get_id() const {
    return 5;
}

template <typename T>
void quick_sort<T>::sort(data<T>& to_sort) {
    quicksort(to_sort, 0, to_sort.get_size() - 1);
}

template <typename T>
void quick_sort<T>::quicksort(data<T>& to_sort, s_index_t low, s_index_t high) {
    if (low >= high)
        return;

    s_index_t pivot = partition(to_sort, low, high);

    quicksort(to_sort, low, pivot - 1);
    quicksort(to_sort, pivot + 1, high);
}

template <typename T>
s_index_t quick_sort<T>::partition(data<T>& to_partition, s_index_t low, s_index_t high) {
    s_index_t pivot = to_partition[high];
    s_index_t i = low - 1;

    for (index_t j = low; j < high; j++) {
        if (to_partition[j] > pivot)
            continue;

        ++i;
        to_partition.swap(i, j);
    }

    ++i;
    to_partition.swap(i, high);

    return i;
}
