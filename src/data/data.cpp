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
std::unique_ptr<data<T>>  data<T>::sum(data<T>& left, data<T>& right) {
    index_t cumulative_size = left.get_size() + right.get_size();

    std::unique_ptr<data<T>> combined_data = std::make_unique<data<T>>(cumulative_size);

    for (index_t idx = 0; idx < left.get_size(); idx++) {
        (*combined_data)[idx] = left.get_at(idx);
    }

    for (index_t idx = 0; idx < right.get_size(); idx++) {
        (*combined_data)[idx + left.get_size()] = right.get_at(idx);
    }

    return combined_data;
}

template <>
std::unique_ptr<int[]> data<int>::generate_random_data(index_t size) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution dist(1, 20);

    auto arr = std::make_unique<int[]>(size);

    for (int i = 0; i < size; i++) {
        arr[i] = dist(mt);
    }

    return arr;
}

template <>
std::unique_ptr<float[]> data<float>::generate_random_data(index_t size) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist(1, 20);

    auto arr = std::make_unique<float[]>(size);

    for (int i = 0; i < size; i++) {
        arr[i] = dist(mt);
    }

    return arr;
}