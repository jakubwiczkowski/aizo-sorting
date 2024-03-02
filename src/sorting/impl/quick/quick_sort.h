#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include "../../algorithm.h"

template<typename T>
class quick_sort : public algorithm<T> {
public:
    [[nodiscard]] virtual int get_id() const;
    void sort(data<T>& to_sort);

    void quicksort(data<T>& to_sort, index_t low, index_t high);
    index_t partition(data<T>& to_partition, index_t low, index_t high);
};

template class quick_sort<int>;
template class quick_sort<float>;



#endif //QUICK_SORT_H
