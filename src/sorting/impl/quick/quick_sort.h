#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include "../../algorithm.h"

/**
 * Typ enumeracyjny określający położenie
 * pivota, które ma zostać użyte do sortowania.
 */
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
    /**
     * Algorytm sortowania szybkiego.
     *
     * @param position pozycja pivota używana w algorytmie
     */
    explicit quick_sort(pivot_postition position);
    [[nodiscard]] virtual int get_id() const;
    void sort(data<T>& to_sort) override;

    /**
     * Funkcja rekurencyjna zawierająca główną logikę
     * algorytmu quicksort.
     *
     * @param to_sort tablica do posortowania
     * @param low indeks od którego zacząć sortować
     * @param high indeks do którego należy posortować
     */
    void quicksort(data<T>& to_sort, index_t low, index_t high);
    /**
     * Funkcja dzieląca tablice na dwie części do posortowania.
     *
     * @param to_partition tablica do podzielenia
     * @param low minimalny indeks podtablicy
     * @param high maksymalny indeks podtablicy
     * @return miejsce w którym tablica powinna zostać podzielona
     */
    index_t partition(data<T>& to_partition, index_t low, index_t high);
};

static index_t generate_index(index_t from, index_t to);

template class quick_sort<int>;
template class quick_sort<float>;



#endif //QUICK_SORT_H
