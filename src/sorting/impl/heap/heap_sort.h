

#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include "../../algorithm.h"


template<typename T>
class heap_sort : public algorithm<T> {
public:
    [[nodiscard]] virtual int get_id() const override;
    void sort(data<T>& to_sort) override;

    /**
     * Funkcja tworząca strukturę kopca z
     * podanej jej tablicy.
     *
     * @param to_heapify tablica, z której należy zrobić kopiec
     */
    void create_heap(data<T>& to_heapify);
    /**
     * Funkcja przesuwająca nowy element root
     * na odpowiednie miejsce w kopcu.
     *
     * @param to_sift_down tablica w której kopiec ma być naprawiony
     * @param root indeks nowego korzenia
     * @param end indeks końca kopca
     */
    void sift_down(data<T>& to_sift_down, index_t root, index_t end);

    /**
     * Funkcja zwracająca lewe dziecko
     * danego elementu.
     *
     * @param index indeks ojca
     * @return indeks lewego dziecka
     */
    index_t index_left_child(index_t index);
    /**
     * Funkcja zwracająca prawe dziecko
     * danego elementu.
     *
     * @param index indeks ojca
     * @return indeks prawego dziecka
     */
    index_t index_right_child(index_t index);
    /**
     * Funkcja zwracająca ojca danego
     * elementu.
     *
     * @param index indeks dziecka
     * @return indeks ojca
     */
    index_t index_parent(index_t index);
};

template class heap_sort<int>;
template class heap_sort<float>;



#endif //HEAP_SORT_H
