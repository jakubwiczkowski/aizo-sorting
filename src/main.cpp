#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>

#include "./data/data.h"
#include "sorting/impl/bubble/bubble_sort.h"
#include "sorting/impl/heap/heap_sort.h"
#include "sorting/impl/insertion/binary_insertion_sort.h"
#include "sorting/impl/insertion/insertion_sort.h"
#include "sorting/impl/merge/merge_sort.h"
#include "sorting/impl/quick/quick_sort.h"
#include "sorting/impl/shell/shell_sort.h"

int main() {
    const int array_sizes[] = {5000};
    const int repeats = 50;
    // const int array_sizes[] = {2000, 4000, 8000, 16000, 32000, 64000, 128000};
    // const int array_sizes[] = {5};

    auto** algorithms = new algorithm<int>*[] {
        // new insertion_sort<int>(),
        // new bubble_sort<int>(),
        // new merge_sort<int>(),
        // new heap_sort<int>(),
        new quick_sort<int>(),
        // new shell_sort<int>([](const int n, const int k) {
        //     return floor(n / pow(2, k));
        // }),
        // new shell_sort<int>([](const int n, const int k) {
        //     return 2 * floor(n / pow(2, k + 1)) + 1;
        // })
    };
    int alg_count = 1;

    for (int idx = 0; idx < alg_count; idx++) {
        algorithm<int>* algorithm = algorithms[idx];
        std::string file_name = std::to_string(algorithm->get_id()).append("_out.txt");
        std::ofstream output_file(file_name, std::ios::app);

        std::cout << "=== ALGORYTM " << algorithm->get_id() << " ===\n";
        for (auto size : array_sizes) {
            std::cout << "# Pomiary dla wielkości " << size << " elementów\n";

            signed long total = 0;
            for (int i = 0; i < repeats; i++) {
                std::cout << "  > Generacja losowych wartości nr " << i + 1 << "\n";
                auto arr = data<int>::generate_random_data(size);

                std::cout << "  > Przekopiowanie wartości\n";
                auto int_data = data(size, arr);

                std::cout << "  > Sortowanie...\n";
                const auto start_time = std::chrono::high_resolution_clock::now();
                algorithm->sort(int_data);
                const auto end_time = std::chrono::high_resolution_clock::now();

                total += std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

                bool sorted = int_data.is_sorted();
                std::cout << "  > Posortowane: " << sorted << "\n";
            }
            output_file << size << "," << (double) (total / repeats) << "\n";
        }

        output_file.close();
    }

    delete[] algorithms;

    return 0;
}
