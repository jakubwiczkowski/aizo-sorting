#include "binary_insertion_sort.h"

template <typename T>
int binary_insertion_sort<T>::get_id() const {
    return 4;
}

template <typename T>
index_t binary_insertion_sort<T>::binary_search(data<T>& to_sort, T item, index_t high, index_t low) {
    if (high <= low)
        return (item > to_sort[low]) ?
                (low + 1) : low;

    index_t mid = (low + high) / 2;

    if (item == to_sort[mid])
        return mid + 1;

    if (item > to_sort[mid])
        return binary_search(to_sort, item,
                            mid + 1, high);
    return binary_search(to_sort, item, low,
                        mid - 1);
}

template <typename T>
void binary_insertion_sort<T>::sort(data<T>& to_sort) {
    if (to_sort.get_size() == 1) return;

    for (s_index_t idx = 1; idx < to_sort.get_size(); idx++) {
        s_index_t j = idx;
        T selected = to_sort[idx];

        const index_t location = binary_search(to_sort, selected, 0, j);

        while (j > location) {
            to_sort[j] = to_sort[j - 1];
            j--;
        }

        to_sort[location] = selected;
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
