

#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include "../../algorithm.h"


template<typename T>
class heap_sort : public algorithm<T> {
public:
    [[nodiscard]] virtual int get_id() const;
    void sort(data<T>& to_sort);
    void create_heap(data<T>& to_heapify);
    void sift_down(data<T>& to_sift_down, index_t root, index_t end);

    index_t index_left_child(index_t index);
    index_t index_right_child(index_t index);
    index_t index_parent(index_t index);
};

template class heap_sort<int>;
template class heap_sort<float>;



#endif //HEAP_SORT_H
