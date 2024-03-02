#ifndef BINARY_INSERTION_SORT_H
#define BINARY_INSERTION_SORT_H
#include "../../algorithm.h"


template<typename T>
class binary_insertion_sort : public algorithm<T> {
public:
    [[nodiscard]] int get_id() const override;
    index_t binary_search(data<T>& to_sort, T item, index_t high, index_t low);
    void sort(data<T>& to_sort) override;
};

template class binary_insertion_sort<int>;
template class binary_insertion_sort<float>;



#endif //BINARY_INSERTION_SORT_H
