#ifndef SHELL_SORT_H
#define SHELL_SORT_H
#include <functional>

#include "../../algorithm.h"

template<typename T>
class shell_sort : public algorithm<T> {
    std::function<index_t(index_t, index_t)> generator_function;
    std::unique_ptr<index_t[]> gaps;
    int gaps_size;
    bool reverse;
public:
    /**
     * Algorytm sortowania Shella
     *
     * @param generator_function funkcja generująca sekwencje kroków uzywaną przez algorytm
     * @param reverse czy wygenerowana sekwencja ma być odwrócona (potrzebne przy niektórych sekwencjach)
     */
    explicit shell_sort(std::function<index_t(index_t, index_t)> generator_function, bool reverse);

    /**
     * Funkcja generująca sekwencję kroków do sortowania,
     * zapisana jest ona w zmiennej gaps.
     *
     * @param N wielkość tablicy do posortowania
     */
    void generate_gaps(index_t N);

    [[nodiscard]] int get_id() const override;
    void sort(data<T>& to_sort) override;
};

template class shell_sort<int>;
template class shell_sort<float>;


#endif //SHELL_SORT_H
