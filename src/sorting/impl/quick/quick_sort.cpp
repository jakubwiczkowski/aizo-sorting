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
void quick_sort<T>::quicksort(data<T>& to_sort, index_t low, index_t high) {
    if (low >= high)
        return;

    index_t partition_idx = partition(to_sort, low, high);

    quicksort(to_sort, low, partition_idx);
    quicksort(to_sort, partition_idx + 1, high);
}

template <typename T>
index_t quick_sort<T>::partition(data<T>& to_partition, index_t low, index_t high) {
    index_t pivot_position;
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
            pivot_position = low + (high - low) / 2;
            break;
        }
        case RANDOM: {
            pivot_position = generate_index(low, high);
            break;
        }
    }

    T pivot = to_partition[pivot_position];

    index_t left = low, right = high;

    while (true) {
        while (to_partition[left] < pivot) ++left;
        while (to_partition[right] > pivot) --right;

        if (left < right) {
            to_partition.swap(left, right);
            ++left;
            --right;
        } else {
            if (right == high) right--;
            return right;
        }
    }
}

index_t generate_index(index_t from, index_t to) {
    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution dist(from, to);

    return dist(mt);
}
