#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>

#include "./data/data.h"
#include "menu/menu.h"
#include "sorting/impl/bubble/bubble_sort.h"
#include "sorting/impl/heap/heap_sort.h"
#include "sorting/impl/insertion/binary_insertion_sort.h"
#include "sorting/impl/insertion/insertion_sort.h"
#include "sorting/impl/merge/merge_sort.h"
#include "sorting/impl/quick/quick_sort.h"
#include "sorting/impl/shell/shell_sort.h"

enum supported_types {
    INT,
    FLOAT
};

const auto shell_function_first = [](const int n, const int k) {
    return floor(n / pow(2, k));
};

const auto shell_function_second = [](const int n, const int k) {
    return 2 * floor(n / pow(2, k + 1)) + 1;
};

const int all_alg_size = 11;

const algorithm<int>* int_algorithms[] = {
    new insertion_sort<int>(),
    new bubble_sort<int>(),
    new merge_sort<int>(),
    new binary_insertion_sort<int>(),
    new heap_sort<int>(),
    new quick_sort<int>(LEFT),
    new quick_sort<int>(MIDDLE),
    new quick_sort<int>(RIGHT),
    new quick_sort<int>(RANDOM),
    new shell_sort<int>(shell_function_first),
    new shell_sort<int>(shell_function_second)
};

int main() {
    const int array_sizes[] = {5};
    const int repeats = 1;
    // const int array_sizes[] = {2000, 4000, 8000, 16000, 32000, 64000, 128000};
    // const int array_sizes[] = {5};

    menu main_menu(2);
    main_menu.add_option(0, "Wykonaj wszystkie pomiary", [] {
        const int array_sizes[] = {2000, 4000, 8000, 16000, 32000, 64000, 128000};
    });
    main_menu.add_option(1, "Wyjście", [&main_menu] {
        main_menu.close();
    });
    // main_menu.open();

    auto** algorithms = new algorithm<int>*[]{
        // new insertion_sort<int>(),
        // new bubble_sort<int>(),
        // new merge_sort<int>(),
        // new binary_insertion_sort<int>(),
        // new heap_sort<int>(),
        new quick_sort<int>(MIDDLE)
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

                int_data.print();
                std::cout << "\n";

                std::cout << "  > Sortowanie...\n";
                const auto start_time = std::chrono::high_resolution_clock::now();
                algorithm->sort(int_data);
                const auto end_time = std::chrono::high_resolution_clock::now();

                total += std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();

                bool sorted = int_data.is_sorted();
                int_data.print();
                std::cout << "\n";
                std::cout << "  > Posortowane: " << sorted << "\n";

                if (!sorted) {
                    std::cout << "  > BŁĄD ALGORYTMU " << algorithm->get_id() << "!!!\n";
                    break;
                }
            }
            output_file << size << "," << (double)(total / repeats) << "\n";
        }

        output_file.close();
    }

    delete[] algorithms;

    return 0;
}
