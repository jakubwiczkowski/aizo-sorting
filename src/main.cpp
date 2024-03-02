#include <chrono>
#include <iostream>

#include "./data/data.h"
#include "sorting/impl/merge_sort.h"

int main() {
    // const int array_sizes[] = {10000, 20000, 50000, 100000, 200000, 500000};
    const int array_sizes[] = {5};

    auto ins_alg = merge_sort<int>();
    const auto arr = new int[5]{1, 8, 7, 3, 4};

    for (auto size : array_sizes) {
        std::cout<<"# Pomiary dla wielkości " << size << " elementów\n";
        std::cout<<"  > Generacja losowych wartości\n";
        // const auto arr = data<int>::generate_random_data(size);

        std::cout<<"  > Przekopiowanie wartości\n";
        auto int_data = data(size, arr);

        int_data.print();
        std::cout<<"\n";

        std::cout<<"  > Sortowanie...\n";
        const auto start_time = std::chrono::high_resolution_clock::now();
        ins_alg.sort(int_data);
        const auto end_time = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        std::cout<<"  > Koniec sortowania w " << duration << "ms\n";

        int_data.print();
    }

    delete[] arr;

    return 0;
}