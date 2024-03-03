#ifndef SHELL_SORT_H
#define SHELL_SORT_H
#include <functional>

#include "../../algorithm.h"

template<typename T>
class shell_sort : public algorithm<T> {
private:
    std::function<int(int, int)> generator_function;
    std::unique_ptr<int[]> gaps;
    int gaps_size;
public:
    explicit shell_sort(std::function<int(int, int)> generator_function);

    void generate_gaps(int N);

    [[nodiscard]] virtual int get_id() const;
    void sort(data<T>& to_sort);
};

template class shell_sort<int>;
template class shell_sort<float>;


#endif //SHELL_SORT_H
