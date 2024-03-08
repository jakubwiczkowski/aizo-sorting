#include "shell_sort.h"

#include <iostream>

template <typename T>
shell_sort<T>::shell_sort(std::function<index_t(index_t, index_t)> generator_function) {
    this->generator_function = generator_function;
}

template <typename T>
void shell_sort<T>::generate_gaps(index_t N) {
    std::unique_ptr<index_t[]> gap_values_temp = std::make_unique<index_t[]>(N - 1);

    index_t final_size = 0;
    for (index_t k = 0; k < N - 1; k++) {
        index_t generated_value = generator_function(N, k + 1);

        if (generated_value == 0) break;

        gap_values_temp[k] = generated_value;
        ++final_size;
    }

    this->gaps = std::make_unique<index_t[]>(final_size);
    this->gaps_size = final_size;

    for (index_t i = 0; i < final_size; i++)
        gaps[i] = gap_values_temp[i];
}

template <typename T>
int shell_sort<T>::get_id() const {
    return 9;
}

template <typename T>
void shell_sort<T>::sort(data<T>& to_sort) {
    generate_gaps(to_sort.get_size());

    for (int idx = 0; idx < this->gaps_size; idx++) {
        index_t gap = this->gaps[idx];
        for (index_t i = gap; i < to_sort.get_size(); ++i) {
            T temp = to_sort[i];
            index_t j;
            for (j = i; (j >= gap) && (to_sort[j - gap] > temp); j -= gap){
                to_sort[j] = to_sort[j - gap];
            }
            to_sort[j] = temp;
        }
    }
}
