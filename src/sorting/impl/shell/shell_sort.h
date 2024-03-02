#ifndef SHELL_SORT_H
#define SHELL_SORT_H
#include <functional>

#include "../../algorithm.h"

template<typename T>
class shell_sort : public algorithm<T> {
private:
    std::function<int(int, int)> generator_function;
public:
    explicit shell_sort(std::function<int(int, int)> generator_function) {
        this->generator_function = generator_function;
    };

    [[nodiscard]] virtual int get_id() const;
    void sort(data<T>& to_sort);
};

template class shell_sort<int>;
template class shell_sort<float>;


#endif //SHELL_SORT_H
