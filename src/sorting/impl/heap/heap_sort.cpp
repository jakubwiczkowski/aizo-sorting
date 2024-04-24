#include "heap_sort.h"

template <typename T>
int heap_sort<T>::get_id() const {
    return 4;
}

template <typename T>
void heap_sort<T>::sort(data<T>& to_sort) {
    create_heap(to_sort);

    index_t end = to_sort.get_size();

    while (end > 1) {
        --end;

        to_sort.swap(end, 0);
        sift_down(to_sort, 0, end);
    }
}

template <typename T>
void heap_sort<T>::create_heap(data<T>& to_heapify) {
    index_t start = index_parent(to_heapify.get_size() - 1) + 1;

    while (start > 0) {
        --start;

        sift_down(to_heapify, start, to_heapify.get_size());
    }
}

template <typename T>
void heap_sort<T>::sift_down(data<T>& to_sift_down, index_t root, index_t end) {
    while (index_left_child(root) < end) {
        index_t child = index_left_child(root);

        if (child + 1 < end &&
            to_sift_down[child] < to_sift_down[child + 1]) {
            ++child;
        }

        if (to_sift_down[root] < to_sift_down[child]) {
            to_sift_down.swap(root, child);
            root = child;
        } else {
            return;
        }
    }
}

template <typename T>
index_t heap_sort<T>::index_left_child(index_t index) {
    return 2 * index + 1;
}

template <typename T>
index_t heap_sort<T>::index_right_child(index_t index) {
    return 2 * index + 2;
}

template <typename T>
index_t heap_sort<T>::index_parent(index_t index) {
    return (index - 1) / 2;
}
