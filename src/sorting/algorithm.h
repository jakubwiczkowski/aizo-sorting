#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "../data/data.h"


template<typename T>
class algorithm {
public:
    [[nodiscard]] virtual int get_id() const;
    virtual void sort(data<T>& to_sort);
};

template class algorithm<int>;


#endif //ALGORITHM_H
