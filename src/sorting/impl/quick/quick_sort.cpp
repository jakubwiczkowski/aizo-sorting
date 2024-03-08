#include "quick_sort.h"
#include <random>

template <typename T>
quick_sort<T>::quick_sort(pivot_postition postition) {
    this->pivot_pos = postition;
}

template <typename T>
int quick_sort<T>::get_id() const {
    return 5 + this->pivot_pos;
}

template <typename T>
void quick_sort<T>::sort(data<T>& to_sort) {
    quicksort(to_sort, 0, to_sort.get_size() - 1);
}

template <typename T>
void quick_sort<T>::quicksort(data<T>& to_sort, s_index_t low, s_index_t high) {
    if (low >= high)
        return;

    s_index_t partition_idx = partition(to_sort, low, high);

    quicksort(to_sort, low, partition_idx - 1);
    quicksort(to_sort, partition_idx + 1, high);
}

template <typename T>
s_index_t quick_sort<T>::partition(data<T>& to_partition, s_index_t low, s_index_t high) {
    s_index_t pivot_position;
    switch (this->pivot_pos) {
        case LEFT: {
            pivot_position = low;
            break;
        }
        case RIGHT: {
            pivot_position = high;
            break;
        }
        case MIDDLE: {
            pivot_position = (low + high) / 2;
            break;
        }
        case RANDOM: {
            pivot_position = generate_index(low, high);
            break;
        }
    }
    T pivot = to_partition[pivot_position];
    s_index_t i = low - 1;

    for (index_t j = low; j < high; j++) {
        if (to_partition[j] <= pivot) {
            ++i;
            to_partition.swap(i, j);
        }
    }

    ++i;
    to_partition.swap(i, pivot_position);

    return i;
}

s_index_t generate_index(s_index_t from, s_index_t to) {
    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution dist(from, to);

    return dist(mt);
}
