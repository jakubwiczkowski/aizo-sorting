#include "merge_sort.h"

#include <iostream>

template <typename T>
void merge_sort<T>::sort(data<T>& to_sort) {
    if (to_sort.get_size() <= 1) return;

    index_t half = to_sort.get_size() / 2;

    data<T> left_elements = to_sort.subdivision(0, half);
    data<T> right_elements = to_sort.subdivision(half, to_sort.get_size());

    // std::cout << "left: ";
    // left_elements.print();
    // std::cout << " / " << left_elements.get_size() << std::endl;
    // std::cout << "right: ";
    // right_elements.print();
    // std::cout << " / " << right_elements.get_size() << std::endl;

    sort(left_elements);
    sort(right_elements);

    data<T> sorted_left = data<T>(left_elements);
    data<T> sorted_right = data<T>(right_elements);

    sorted_left.print();
    std::cout << "\n";
    sorted_right.print();
    std::cout << "\n";

    data<T> merged = merge(left_elements, right_elements);

    for (index_t idx = 0; idx < merged.get_size(); idx++) {
        to_sort.set_at(idx, merged.get_at(idx));
    }
}

template <typename T>
data<T> merge_sort<T>::merge(data<T> left, data<T> right) {
    std::cout << "# Merging \n > L: ";
    left.print();
    std::cout << "\n > R: ";
    right.print();
    std::cout << "\n";
    data<T> merged = data<T>(left.get_size() + right.get_size());

    index_t current_idx = 0;
    while (!left.is_empty() && !right.is_empty()) {
        T current_left = left.get_at(0);
        T current_right = right.get_at(0);

        if (current_left <= current_right) {
            std::cout<<" > L\n";
            merged.set_at(current_idx, current_left);

            left = left.subdivide_to_end(1);
        } else {
            std::cout<<" > R\n";
            merged.set_at(current_idx, current_right);

            right = right.subdivide_to_end(1);
        }

        current_idx++;
    }

    std::cout << " > left in left: ";
    left.print();
    std::cout << "\n";

    std::cout << " > left in right: ";
    right.print();
    std::cout << "\n";

    while (!left.is_empty()) {
        std::cout<<" > |L rest|\n";
        merged.set_at(current_idx, left.get_at(0));
        current_idx++;

        left = left.subdivide_to_end(1);
    }

    while (!right.is_empty()) {
        std::cout<<" > |R rest|\n";
        merged.set_at(current_idx, right.get_at(0));
        current_idx++;

        right = right.subdivide_to_end(1);
    }

    std::cout << " > merged: ";
    merged.print();
    std::cout << "\n";

    return merged;
}

// function merge(left, right) is
//     var result := empty list
//
//     while left is not empty and right is not empty do
//         if first(left) ≤ first(right) then
//             append first(left) to result
//             left := rest(left)
//         else
//             append first(right) to result
//             right := rest(right)
//
//     // Either left or right may have elements left; consume them.
//     // (Only one of the following loops will actually be entered.)
//     while left is not empty do
//         append first(left) to result
//         left := rest(left)
//     while right is not empty do
//         append first(right) to result
//         right := rest(right)
//     return result