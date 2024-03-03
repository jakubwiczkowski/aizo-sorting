#include "bubble_sort.h"

template <typename T>
int bubble_sort<T>::get_id() const {
    return 2;
}

template <typename T>
void bubble_sort<T>::sort(data<T>& to_sort) {
    index_t n = to_sort.get_size();

    while (n > 1) {
        index_t new_n = 0;
        for (index_t i = 1; i <= n - 1; i++) {
            if (to_sort.get_at(i - 1) < to_sort.get_at(i))
                continue;

            to_sort.swap(i - 1, i);
            new_n = i;
        }

        n = new_n;
    }
}
