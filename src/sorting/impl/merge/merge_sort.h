#ifndef MERGE_SORT_H
#define MERGE_SORT_H
#include "../../algorithm.h"


template<typename T>
class merge_sort : public algorithm<T> {
public:
    [[nodiscard]] virtual int get_id() const;
    void sort(data<T>& to_sort) override;
    std::unique_ptr<data<T>> merge(std::unique_ptr<data<T>>& left, std::unique_ptr<data<T>>& right);
};

template class merge_sort<int>;
template class merge_sort<float>;

#endif //MERGE_SORT_H
