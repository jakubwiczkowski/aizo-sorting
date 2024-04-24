#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "../data/data.h"


/**
 * Klasa definiująca kształt podklas
 * które implementują algorytmy.
 *
 * @tparam T - typ danych do sortowania
 */
template<typename T>
class algorithm {
public:
    /**
     * Zwraca unikalne ID algorytmu.
     *
     * @return ID algorytmu
     */
    [[nodiscard]] virtual int get_id() const;

    /**
     * Sortuje daną tablice in-place.
     *
     * @param to_sort tablica do posortowania
     */
    virtual void sort(data<T>& to_sort);
};

template class algorithm<int>;
template class algorithm<float>;


#endif //ALGORITHM_H
