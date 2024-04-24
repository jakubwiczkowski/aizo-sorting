#ifndef DATA_H
#define DATA_H
#include <algorithm>
#include <memory>

/**
 * Typ reprezentujący indeksy w tablicach.
 * Jest unsigned, bo nie można mieć ujemnych indeksów.
 */
typedef unsigned int index_t;
typedef signed int s_index_t;

/**
 * Klasa reprezentująca tablice danych.
 *
 * @tparam T typ przetrzymywanych danych
 */
template <typename T>
class data {
    index_t size{};
    bool empty = false;
    std::unique_ptr<T[]> array;

public:
    /**
     * Konstruktor klasy przetrzymującej tablice
     *
     * @param size wielkość tablicy określona z gówy
     */
    explicit data(index_t size);

    /**
     * Konstruktor kopiujący dane ze zwykłej
     * tablicy C++
     *
     * @param size wielkość kopiowanej tablicy
     * @param array_to_cop tablica do skopiowania
     */
    data(index_t size, std::unique_ptr<T[]>& array_to_cop);

    /**
     * Konstruktor kopiujący.
     *
     * @param to_copy klasa reprezentująca tablice do skopiowania
     */
    data(data<T>& to_copy);
    data();

    /**
     * Konstruktor przenoszący własność
     * wskaźnika na dane.
     *
     * @param arg klasa reprezentująca tablice do przeniesienia
     */
    data(data<T>&& arg) noexcept : array(std::move(arg.array)) {
        arg.array = nullptr;
        this->empty = arg.empty;
        this->size = arg.size;
    }

    /**
     * Funkcja wypisująca tablice
     */
    void print();
    /**
     * Funkcja sprawdzająca czy tablica jest pusta
     *
     * @return czy tablica jest pusta
     */
    bool is_empty();

    /**
     * Zwraca wartość z tablicy na
     * danym indeksie.
     *
     * @param index indeks wartości
     * @return wartość spod indeksu
     */
    T get_at(index_t index);

    /**
     * Ustawia wartość na danym
     * indeksie w tablicy.
     *
     * @param index indeks, gdzie ma być ustawiona wartość
     * @param value wartość
     */
    void set_at(index_t index, T value);

    /**
     * Zamienia wartości na podanych indeksach
     * między sobą.
     *
     * @param first indeks pierwszej wartości
     * @param second indeks drugiej wartości
     */
    void swap(index_t first, index_t second);

    /**
     * Zwraca wielkość tablicy
     *
     * @return wielkość tablicy
     */
    [[nodiscard]] index_t get_size() const;

    /**
     * Zwraca podtablicę z danej tablicy.
     *
     * @param start indeks początku podtablicy
     * @param end indeks końca podtablicy
     * @return podtablica
     */
    std::unique_ptr<data<T>> subdivision(index_t start, index_t end);

    /**
     * Zwraca podtablicę od danego indeksu do końca.
     *
     * @param start indesk początku podtablicy
     * @return podtablica
     */
    std::unique_ptr<data<T>> subdivide_to_end(index_t start);

    /**
     * Sprawdza czy dane w tablicy są
     * posortowane rosnąco.
     *
     * @return czy tablica jest posortowana rosnąco
     */
    bool is_sorted();

    /**
     * Generuje tablice o losowych wartościach.
     *
     * @param size wielkość tablicy do wygenerowania
     * @return wygenerowana tablica
     */
    static std::unique_ptr<T[]> generate_random_data(index_t size);

    /**
     * Generuje tablice o losowych ograniczonych
     * wartościach.
     *
     * @param size wielkość tablicy do wygenerowania
     * @param min minimalna wartość
     * @param max maksymalna wartość
     * @return wygenerowana tablica
     */
    static std::unique_ptr<T[]> generate_random_data(index_t size, T min, T max);

    /**
     * Generuje posortowaną tablicę o danym
     * stopniu wypełnienia.
     *
     * @param size wielkość tablicy do wygenerowania
     * @param sorted_part jak duża część danych ma być posortowana
     * @return wygenerowana tablica
     */
    static std::unique_ptr<T[]> generate_sorted_data(index_t size, double sorted_part);

    /**
     * Generuje tablice o elementach
     * posortowanych malejąco.
     *
     * @param size
     * @return wygenerowana tablica
     */
    static std::unique_ptr<T[]> generate_sorted_reversed_data(index_t size);

    /**
     * Przeładowanie operatora [] pozwalające
     * na łatwiejszy dostęp do danych.
     *
     * @param idx indeks elementu
     * @return wartość elementu pod indeksem
     */
    T& operator[](index_t idx) { return array[idx]; }

    /**
     * Przeładowanie operatora [] pozwalające
     * na łatwiejszy dostęp do danych.
     *
     * @param idx indeks elementu
     * @return wartość elementu pod indeksem
     */
    const T& operator[](index_t idx) const { return array[idx]; }

    /**
     * Przeładowanie operatora = który
     * działa jak konstruktor przenoszącu.
     *
     * @param other dane do przeniesienia
     * @return przeniesiona tablica
     */
    data<T>& operator=(data<T>&& other) noexcept {
        this->array = std::move(other.array);
        other.array = nullptr;
        this->size = other.size;
        this->empty = other.empty;
        return *this;
    }
};

template class data<int>;
template class data<float>;

#endif //DATA_H
