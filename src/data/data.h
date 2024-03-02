#ifndef DATA_H
#define DATA_H

typedef unsigned long index_t;

template<typename T>
class data {
    index_t size{};
    bool empty = false;
    T* array;

public:
    data(index_t size);
    data(index_t size, T* array_to_copy);
    data(data<T>& to_copy);
    data();
    ~data();

    void print();
    bool is_empty();

    T get_at(index_t index);
    void set_at(index_t index, T value);
    void swap(index_t first, index_t second);

    [[nodiscard]] index_t get_size() const;

    data<T> subdivision(index_t start, index_t end);
    data<T> subdivide_to_end(index_t start);

    static data<T> sum(data<T>& left, data<T>& right);

    static T* generate_random_data(index_t size);
};

template class data<int>;
template class data<float>;

#endif //DATA_H
