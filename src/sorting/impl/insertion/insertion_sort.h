#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H
#include "../../algorithm.h"


template<typename T>
class insertion_sort : public algorithm<T> {
public:
    int get_id() const override;
    void sort(data<T>& to_sort) override;
};

template class insertion_sort<int>;
template class insertion_sort<float>;

#endif //INSERTION_SORT_H
