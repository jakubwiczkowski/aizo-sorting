#include "bubble_sort.h"

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

// procedure bubbleSort(A : list of sortable items)
//     n := length(A)
//     repeat
//         newn := 0
//         for i := 1 to n - 1 inclusive do
//             if A[i - 1] > A[i] then
//                 swap(A[i - 1], A[i])
//                 newn := i
//             end if
//         end for
//         n := newn
//     until n ≤ 1
// end procedure