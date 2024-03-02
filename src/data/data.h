#ifndef DATA_H
#define DATA_H
#include <algorithm>
#include <memory>

typedef unsigned long index_t;
typedef signed long s_index_t;

template <typename T>
class data {
    index_t size{};
    bool empty = false;
    std::unique_ptr<T[]> array;

public:
    data(index_t size);
    data(index_t size, std::unique_ptr<T[]>& array_to_cop);
    data(data<T>& to_copy);
    data();
    data(data<T>&& arg) : array(std::move(arg.array)) {
        arg.array = nullptr;
        this->empty = arg.empty;
        this->size = arg.size;
    }

    void print();
    bool is_empty();

    T get_at(index_t index);
    void set_at(index_t index, T value);
    void swap(index_t first, index_t second);

    [[nodiscard]] index_t get_size() const;

    std::unique_ptr<data<T>> subdivision(index_t start, index_t end);
    std::unique_ptr<data<T>> subdivide_to_end(index_t start);

    bool is_sorted();

    static std::unique_ptr<data<T>>  sum(data<T>& left, data<T>& right);

    static std::unique_ptr<T[]> generate_random_data(index_t size);

    T& operator[](index_t idx) { return array[idx]; }
    const T& operator[](index_t idx) const { return array[idx]; }

    data<T>& operator=(data<T>&& other) noexcept {
        this->array = std::move(other.array);
        other.array = nullptr;
        this->size = other.size;
        this->empty = other.empty;
        return *this;
    }
};

template class data<int>;
template class data<float>;

#endif //DATA_H
