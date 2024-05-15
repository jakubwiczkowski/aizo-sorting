#include <iostream>
#include "shell_sort.h"

template <typename T>
shell_sort<T>::shell_sort(std::function<index_t(index_t, index_t)> generator_function, const bool reverse) {
    this->generator_function = generator_function;
    this->reverse = reverse;
}

template <typename T>
void shell_sort<T>::generate_gaps(index_t N) {
    std::unique_ptr<index_t[]> gap_values_temp = std::make_unique<index_t[]>(N);

    index_t final_size = 0;
    for (index_t k = 0; k < N; k++) {
        index_t generated_value = generator_function(N, k + 1);

        if (generated_value == 0) {
            break;
        }

        if (generated_value >= (N/2) + 1) break;

        gap_values_temp[k] = generated_value;
        ++final_size;
    }

    this->gaps = std::make_unique<index_t[]>(final_size);
    this->gaps_size = final_size;

    if (this->reverse) {
        for (index_t i = 0; i < final_size; i++) {
            gaps[i] = gap_values_temp[final_size - i - 1];
        }
    } else {
        for (index_t i = 0; i < final_size; i++) {
            gaps[i] = gap_values_temp[i];
        }
    }


//    for (index_t i = 0; i < final_size; i++) {
//        std::cout << gaps[i] << "\n";
//    }
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

        if (gap == 0) continue;

        for (index_t i = gap; i < to_sort.get_size(); i += gap) {
            if (i >= to_sort.get_size()) continue;

            T temp = to_sort[i];
            index_t j;
            for (j = i; (j >= gap) && (to_sort[j - gap] > temp); j -= gap){
                to_sort[j] = to_sort[j - gap];
            }
            to_sort[j] = temp;
        }
    }
}