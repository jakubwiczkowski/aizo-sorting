#include "merge_sort.h"

template <typename T>
void merge_sort<T>::sort(data<T>& to_sort) {
    if (to_sort.get_size() <= 1) return;

    index_t half = to_sort.get_size() / 2;

    auto left_elements = to_sort.subdivision(0, half);
    auto right_elements = to_sort.subdivision(half, to_sort.get_size());

    sort(*left_elements);
    sort(*right_elements);

    auto sorted_left = new data<T>(*left_elements);
    auto sorted_right = new data<T>(*right_elements);

    data<T>* merged = merge(sorted_left, sorted_right);

    for (index_t idx = 0; idx < merged->get_size(); idx++) {
        to_sort[idx] = (*merged)[idx];
    }

    delete left_elements, right_elements;

    delete merged;
}

template <typename T>
data<T>* merge_sort<T>::merge(data<T>* left, data<T>* right) {
    auto merged = new data<T>(left->get_size() + right->get_size());

    index_t current_idx = 0;
    while (!left->is_empty() && !right->is_empty()) {
        T current_left = (*left)[0];
        T current_right = (*right)[0];

        if (current_left <= current_right) {
            (*merged)[current_idx] = current_left;

            auto new_data = left->subdivide_to_end(1);
            delete left;
            left = new_data;
        } else {
            (*merged)[current_idx] = current_right;

            auto new_data = right->subdivide_to_end(1);
            delete right;
            right = new_data;
        }

        current_idx++;
    }

    while (!left->is_empty()) {
        (*merged)[current_idx] = (*left)[0];
        current_idx++;

        if (left->get_size() != 1) {
            auto new_data = left->subdivide_to_end(1);
            delete left;
            left = new_data;
        }
        else {
            delete left;
            left = new data<T>();
        }
    }

    while (!right->is_empty()) {
        (*merged)[current_idx] = (*right)[0];
        current_idx++;

        if (right->get_size() != 1) {
            auto new_data = right->subdivide_to_end(1);
            delete right;
            right = new_data;
        } else {
            delete right;
            right = new data<T>();
        }
    }

    delete left, right;

    return merged;
}