#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include "../../algorithm.h"

enum pivot_postition {
    LEFT,
    MIDDLE,
    RIGHT,
    RANDOM
};

template<typename T>
class quick_sort : public algorithm<T> {
    pivot_postition pivot_pos;
public:
    explicit quick_sort(pivot_postition postition);
    [[nodiscard]] virtual int get_id() const;
    void sort(data<T>& to_sort) override;

    void quicksort(data<T>& to_sort, s_index_t low, s_index_t high);
    s_index_t partition(data<T>& to_partition, s_index_t low, s_index_t high);
};

static s_index_t generate_index(s_index_t from, s_index_t to);

template class quick_sort<int>;
template class quick_sort<float>;



#endif //QUICK_SORT_H
