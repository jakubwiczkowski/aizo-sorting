

#ifndef MERGE_SORT_H
#define MERGE_SORT_H
#include "../algorithm.h"


template<typename T>
class merge_sort : public algorithm<T> {
public:
    void sort(data<T>& to_sort);
    data<T> merge(data<T> left, data<T> right);
};

template class merge_sort<int>;
template class merge_sort<float>;

#endif //MERGE_SORT_H
