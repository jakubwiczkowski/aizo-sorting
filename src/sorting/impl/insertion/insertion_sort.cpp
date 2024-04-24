#include "insertion_sort.h"

template <typename T>
int insertion_sort<T>::get_id() const {
    return 1;
}

template <typename T>
void insertion_sort<T>::sort(data<T>& to_sort) {
    for (index_t i = 1; i < to_sort.get_size(); i++) {
        T key = to_sort[i];
        index_t j = i;
        while (j > 0 && to_sort[j - 1] > key){
            to_sort[j] = to_sort[j - 1];
            j--;
        }
        to_sort[j] = key;
    }
}
