

#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H
#include "../../algorithm.h"


template<typename T>
class bubble_sort : public algorithm<T> {
public:
    [[nodiscard]] virtual int get_id() const;
    void sort(data<T>& to_sort);
};

template class bubble_sort<int>;
template class bubble_sort<float>;

#endif //BUBBLE_SORT_H
