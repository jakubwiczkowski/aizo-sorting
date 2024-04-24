#include "data.h"

#include <iostream>
#include <random>

template <typename T>
data<T>::data(index_t size) {
    this->size = size;
    this->array = std::unique_ptr<T[]>(new T[size]);
}

template <typename T>
data<T>::data(index_t size, std::unique_ptr<T[]>& array_to_copy): data(size) {
    for (unsigned long i = 0; i < size; i++) {
        this->array[i] = array_to_copy[i];
    }
}

template <typename T>
data<T>::data(data<T>& to_copy): data(to_copy.get_size()) {
    for (index_t idx = 0; idx < to_copy.get_size(); idx++) {
        this->array[idx] = to_copy.get_at(idx);
    }
}

template <typename T>
data<T>::data() {
    this->size = 0;
    this->empty = true;
    this->array = nullptr;
}

template <typename T>
bool data<T>::is_empty() {
    return this->empty;
}

template <typename T>
T data<T>::get_at(index_t index) {
    return this->array[index];
}

template <typename T>
void data<T>::swap(index_t first, index_t second) {
    T temp = this->array[first];
    this->array[first] = this->array[second];
    this->array[second] = temp;
}

template <typename T>
void data<T>::set_at(index_t index, T value) {
    this->array[index] = value;
}

template <typename T>
index_t data<T>::get_size() const {
    return this->size;
}

template <typename T>
std::unique_ptr<data<T>> data<T>::subdivision(index_t start, index_t end) {
    index_t size = end - start;

    if (size == 0 || start > get_size() || end > get_size() || start >= end)
        return std::make_unique<data<T>>();

    auto new_data = std::make_unique<data<T>>(size);

    for (index_t idx = 0; idx < size; idx++) {
        (*new_data)[idx] = array[idx + start];
    }

    return new_data;
}

template <typename T>
std::unique_ptr<data<T>> data<T>::subdivide_to_end(index_t start) {
    return subdivision(start, get_size());
}

template <typename T>
bool data<T>::is_sorted() {
    if (get_size() == 1) return true;

    T prev = get_at(0);
    for (index_t idx = 1; idx < get_size(); idx++) {
        T curr = get_at(idx);

        if (prev > curr) return false;

        prev = curr;
    }

    return true;
}

template <typename T>
void data<T>::print() {
    for (index_t i = 0; i < get_size(); i++) {
        std::cout << get_at(i) << " ";
    }
}

template <typename T>
std::unique_ptr<T[]> data<T>::generate_random_data(index_t size) {
    return generate_random_data(size, std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
}

template <typename T>
std::unique_ptr<T[]> data<T>::generate_random_data(index_t size, T min, T max) {
    return generate_random_data(size, min, max);
}

template <>
std::unique_ptr<int[]> data<int>::generate_random_data(index_t size, int min, int max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution dist(min, max);

    auto arr = std::make_unique<int[]>(size);

    for (int i = 0; i < size; i++) {
        arr[i] = dist(mt);
    }

    return arr;
}

template <>
std::unique_ptr<float[]> data<float>::generate_random_data(index_t size, float min, float max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution dist(min, max);

    auto arr = std::make_unique<float[]>(size);

    for (int i = 0; i < size; i++) {
        arr[i] = dist(mt);
    }

    return arr;
}

template <typename T>
std::unique_ptr<T[]> data<T>::generate_sorted_data(index_t size, double sorted_part) {
    auto arr = std::make_unique<T[]>(size);

    const index_t max_sorted = size * sorted_part;

    for (index_t idx = 0; idx < max_sorted; idx++) {
        arr[idx] = idx;
    }

    const index_t to_fill = size - max_sorted;
    auto generated = generate_random_data(to_fill, arr[max_sorted - 1], static_cast<T>(size));

    for (index_t idx = max_sorted; idx < size; idx++) {
        arr[idx] = generated[idx - max_sorted];
    }

    return arr;
}

template <typename T>
std::unique_ptr<T[]> data<T>::generate_sorted_reversed_data(index_t size) {
    auto arr = generate_sorted_data(size, 1);
    auto reversed_array = std::make_unique<T[]>(size);

    for (index_t idx = 0; idx < size; idx++) {
        reversed_array[idx] = arr[size - idx - 1];
    }

    return reversed_array;
}
