#include "shell_sort.h"

template <typename T>
int shell_sort<T>::get_id() const {
    return 7;
}

template <typename T>
void shell_sort<T>::sort(data<T>& to_sort) {

}

// # Sort an array a[0...n-1].
// gaps = [701, 301, 132, 57, 23, 10, 4, 1]  # Ciura gap sequence
//
// # Start with the largest gap and work down to a gap of 1
// # similar to insertion sort but instead of 1, gap is being used in each step
// foreach (gap in gaps)
// {
// # Do a gapped insertion sort for every elements in gaps
// # Each loop leaves a[0..gap-1] in gapped order
//     for (i = gap; i < n; i += 1)
//     {
// # save a[i] in temp and make a hole at position i
//         temp = a[i]
//         # shift earlier gap-sorted elements up until the correct location for a[i] is found
//         for (j = i; (j >= gap) && (a[j - gap] > temp); j -= gap)
//         {
//             a[j] = a[j - gap]
//         }
// # put temp (the original a[i]) in its correct location
//         a[j] = temp
//     }
// }