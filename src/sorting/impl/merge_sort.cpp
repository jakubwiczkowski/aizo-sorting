#include "merge_sort.h"

template <typename T>
void merge_sort<T>::sort(data<T>& to_sort) {
    if (to_sort.get_size() <= 1) return;

    index_t half = to_sort.get_size() / 2;

    auto left_elements = to_sort.subdivision(0, half);
    auto right_elements = to_sort.subdivision(half, to_sort.get_size());

    sort(*left_elements);
    sort(*right_elements);

    auto merged = std::move(merge(left_elements, right_elements));

    for (index_t idx = 0; idx < merged->get_size(); idx++) {
        to_sort[idx] = (*merged)[idx];
    }
}

template <typename T>
std::unique_ptr<data<T>> merge_sort<T>::merge(std::unique_ptr<data<T>>& left, std::unique_ptr<data<T>>& right) {
    auto merged = std::make_unique<data<T>>(left->get_size() + right->get_size());

    index_t current_idx = 0;
    while (!left->is_empty() && !right->is_empty()) {
        T current_left = (*left)[0];
        T current_right = (*right)[0];

        if (current_left <= current_right) {
            (*merged)[current_idx] = current_left;

            left = left->subdivide_to_end(1);
        } else {
            (*merged)[current_idx] = current_right;

            right = right->subdivide_to_end(1);
        }

        current_idx++;
    }

    while (!left->is_empty()) {
        (*merged)[current_idx] = (*left)[0];
        current_idx++;

        if (left->get_size() != 1) {
            left = left->subdivide_to_end(1);
        }
        else {
            left = std::make_unique<data<T>>();
        }
    }

    while (!right->is_empty()) {
        (*merged)[current_idx] = (*right)[0];
        current_idx++;

        if (right->get_size() != 1) {
            right = right->subdivide_to_end(1);
        }
        else {
            right = std::make_unique<data<T>>();
        }
    }

    return merged;
}