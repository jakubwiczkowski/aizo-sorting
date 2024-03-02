#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "../data/data.h"


template<typename T>
class algorithm {
public:
    virtual void sort(data<T>& to_sort);
};



#endif //ALGORITHM_H
