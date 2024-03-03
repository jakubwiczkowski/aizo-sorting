#include "shell_sort.h"

#include <iostream>

template <typename T>
shell_sort<T>::shell_sort(std::function<int(int, int)> generator_function) {
    this->generator_function = generator_function;
}

template <typename T>
void shell_sort<T>::generate_gaps(int N) {
    std::unique_ptr<int[]> gap_values_temp = std::make_unique<int[]>(N - 1);

    int final_size = 0;
    for (int k = 0; k < N - 1; k++) {
        int generated_value = generator_function(N, k + 1);

        if (generated_value == 0) break;

        gap_values_temp[k] = generated_value;
        ++final_size;
    }

    this->gaps = std::make_unique<int[]>(final_size);
    this->gaps_size = final_size;

    for (int i = 0; i < final_size; i++)
        gaps[i] = gap_values_temp[i];
}

template <typename T>
int shell_sort<T>::get_id() const {
    return 6;
}

template <typename T>
void shell_sort<T>::sort(data<T>& to_sort) {
    generate_gaps(to_sort.get_size());

    for (int idx = 0; idx < this->gaps_size; idx++) {
        int gap = this->gaps[idx];
        for (int i = gap; i < to_sort.get_size(); ++i) {
            T temp = to_sort[i];
            int j;
            for (j = i; (j >= gap) && (to_sort[j - gap] > temp); j -= gap){
                to_sort[j] = to_sort[j - gap];
            }
            to_sort[j] = temp;
        }
    }
}
