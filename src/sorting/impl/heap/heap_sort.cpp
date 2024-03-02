#include "heap_sort.h"

template <typename T>
int heap_sort<T>::get_id() const {
    return 5;
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

// procedure heapsort(a, count) is
//     input: an unordered array a of length count
//
//     (Build the heap in array a so that largest value is at the root)
//     heapify(a, count)
//
//     (The following loop maintains the invariants that a[0:end−1] is a heap, and
//     every element a[end:count−1] beyond end is greater than everything before it,
//     i.e. a[end:count−1] is in sorted order.)
//     end ← count
//     while end > 1 do
//         (the heap size is reduced by one)
//         end ← end − 1
//         (a[0] is the root and largest value. The swap moves it in front of the sorted elements.)
//         swap(a[end], a[0])
//         (the swap ruined the heap property, so restore it)
//         siftDown(a, 0, end)

template <typename T>
void heap_sort<T>::create_heap(data<T>& to_heapify) {
    index_t start = index_parent(to_heapify.get_size() - 1) + 1;

    while (start > 0) {
        --start;

        sift_down(to_heapify, start, to_heapify.get_size());
    }
}

// procedure heapify(a, count) is
//     (start is initialized to the first leaf node)
//     (the last element in a 0-based array is at index count-1; find the parent of that element)
//     start ← iParent(count-1) + 1
//
//     while start > 0 do
//         (go to the last non-heap node)
//         start ← start − 1
//         (sift down the node at index 'start' to the proper place such that all nodes below
//          the start index are in heap order)
//         siftDown(a, start, count)
//     (after sifting down the root all nodes/elements are in heap order)

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

// (Repair the heap whose root element is at index 'start', assuming the heaps rooted at its children are valid)
// procedure siftDown(a, root, end) is
//     while iLeftChild(root) < end do    (While the root has at least one child)
//         child ← iLeftChild(root)       (Left child of root)
//         (If there is a right child and that child is greater)
//         if child+1 < end and a[child] < a[child+1] then
//             child ← child + 1
//
//         if a[root] < a[child] then
//             swap(a[root], a[child])
//             root ← child         (repeat to continue sifting down the child now)
//         else
//             (The root holds the largest element. Since we may assume the heaps rooted
//              at the children are valid, this means that we are done.)
//             return

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
