#include "insertion_sort.h"

template <typename T>
int insertion_sort<T>::get_id() const {
    return 2;
}

template <typename T>
void insertion_sort<T>::sort(data<T>& to_sort) {
    index_t i = 1;
    while (i < to_sort.get_size()) {
        index_t j = i;
        while (j > 0 && to_sort.get_at(j - 1) > to_sort.get_at(j)) {
            to_sort.swap(j, j - 1);
            j = j - 1;
        }
        i = i + 1;
    }
}
