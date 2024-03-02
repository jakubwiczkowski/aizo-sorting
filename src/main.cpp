#include <chrono>
#include <iostream>

#include "./data/data.h"
#include "sorting/impl/bubble/bubble_sort.h"
#include "sorting/impl/heap/heap_sort.h"
#include "sorting/impl/insertion/binary_insertion_sort.h"
#include "sorting/impl/insertion/insertion_sort.h"
#include "sorting/impl/merge/merge_sort.h"
#include "sorting/impl/quick/quick_sort.h"

int main() {
    // const int array_sizes[] = {1000, 2000, 5000, 10000, 20000, 50000, 100000};
    const int array_sizes[] = {15};

    binary_insertion_sort<int> alg = binary_insertion_sort<int>();

    std::cout << "=== ALGORYTM " << alg.get_id() << " ===\n";
    for (auto size : array_sizes) {
        std::cout << "# Pomiary dla wielkości " << size << " elementów\n";
        std::cout << "  > Generacja losowych wartości\n";
        auto arr = data<int>::generate_random_data(size);

        std::cout << "  > Przekopiowanie wartości\n";
        auto int_data = data(size, arr);

        int_data.print();
        std::cout << "\n";

        std::cout << "  > Sortowanie...\n";
        const auto start_time = std::chrono::high_resolution_clock::now();
        alg.sort(int_data);
        const auto end_time = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        int_data.print();
        std::cout << "\n";
        std::cout << "  > Posortowane: " << int_data.is_sorted() << "\n";
        std::cout << "  > Koniec sortowania w " << duration << " ms\n";
    }

    return 0;
}
