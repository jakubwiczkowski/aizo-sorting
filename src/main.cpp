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

/**
 * Wspierane typy przez aplikacje.
 */
enum supported_type {
    INT,
    FLOAT
};

/**
 * Funkcje generująca kroki do algorytmu Shella.
 */
const auto shell_function_first = [](const index_t n, const index_t k) -> index_t {
    return floor(n / pow(2, k)); // theta (n^2)
};

const auto shell_function_second = [](const index_t n, const index_t k) -> index_t {
    return pow(2, k) - 1; // theta (n^(3/2))
};

/**
 * Lista badanych algorytmów o typie int.
 * Potrzebna do automatycznego zbierania danych.
 */
algorithm<int> *int_algorithms[] = {
        new shell_sort<int>(shell_function_first, false),
        new shell_sort<int>(shell_function_second, true),
        new quick_sort<int>(LEFT),
        new quick_sort<int>(MIDDLE),
        new quick_sort<int>(RIGHT),
        new quick_sort<int>(RANDOM),
        new heap_sort<int>(),
        new insertion_sort<int>(),
        // new binary_insertion_sort<int>()
        // new bubble_sort<int>(),
        // new merge_sort<int>()
};

/**
 * Lista badanych algorytmów o typie float.
 * Potrzebna do automatycznego zbierania danych.
 */
algorithm<float> *float_algorithms[] = {
//        new shell_sort<float>(shell_function_first),
//        new shell_sort<float>(shell_function_second),
//        new quick_sort<float>(LEFT),
//        new quick_sort<float>(MIDDLE),
//        new quick_sort<float>(RIGHT),
//        new quick_sort<float>(RANDOM),
        new heap_sort<float>(),
//        new insertion_sort<float>(),
        // new binary_insertion_sort<int>()
        // new bubble_sort<int>(),
        // new merge_sort<int>()
};


/**
 * Sekcja predefiniowanych algorytmów potrzebna
 * do menu selekcji algorytmu.
 */
shell_sort<int> shell_first_instance_int(shell_function_first, true);
shell_sort<int> shell_second_instance_int(shell_function_second, false);
quick_sort<int> quick_left_instance_int(LEFT);
quick_sort<int> quick_middle_instance_int(MIDDLE);
quick_sort<int> quick_right_instance_int(RIGHT);
quick_sort<int> quick_random_instance_int(RANDOM);
heap_sort<int> heap_instance_int = heap_sort<int>();
insertion_sort<int> insertion_instance_int = insertion_sort<int>();

shell_sort<float> shell_first_instance_float(shell_function_first, true);
shell_sort<float> shell_second_instance_float(shell_function_second, false);
quick_sort<float> quick_left_instance_float(LEFT);
quick_sort<float> quick_middle_instance_float(MIDDLE);
quick_sort<float> quick_right_instance_float(RIGHT);
quick_sort<float> quick_random_instance_float(RANDOM);
heap_sort<float> heap_instance_float = heap_sort<float>();
insertion_sort<float> insertion_instance_float = insertion_sort<float>();

/**
 * Punkt wejściowy programu.
 * Ma w sobie logikę całego menu.
 */
int main() {
    bool display_values = false;
    supported_type type = INT;
    algorithm<int> *picked_algorithm_int = nullptr;
    algorithm<float> *picked_algorithm_float = nullptr;
    data<int> int_data;
    data<float> float_data;

    menu data_type_menu(2);
    data_type_menu.add_option(0, "int (32 bit signed) -> 0", [&type, &data_type_menu] {
        type = INT;
        data_type_menu.close();
    });
    data_type_menu.add_option(1, "float (32 bit signed) -> 1", [&type, &data_type_menu] {
        type = FLOAT;
        data_type_menu.close();
    });

    menu algorithm_menu(8);
    algorithm_menu.add_option(0, "Shell sort (floor(n / pow(2, k)))",
                              [&type, &picked_algorithm_int, &picked_algorithm_float, &algorithm_menu] {
                                  if (type == INT) {
                                      picked_algorithm_int = &shell_first_instance_int;
                                  } else {
                                      picked_algorithm_float = &shell_first_instance_float;
                                  }
                                  algorithm_menu.close();
                              });
    algorithm_menu.add_option(1, "Shell sort (2 * floor(n / pow(2, k + 1)) + 1)",
                              [&type, &picked_algorithm_int, &picked_algorithm_float, &algorithm_menu] {
                                  if (type == INT) {
                                      picked_algorithm_int = &shell_second_instance_int;
                                  } else {
                                      picked_algorithm_float = &shell_second_instance_float;
                                  }
                                  algorithm_menu.close();
                              });
    algorithm_menu.add_option(2, "Quick sort (pivot: left)",
                              [&type, &picked_algorithm_int, &picked_algorithm_float, &algorithm_menu] {
                                  if (type == INT) {
                                      picked_algorithm_int = &quick_left_instance_int;
                                  } else {
                                      picked_algorithm_float = &quick_left_instance_float;
                                  }
                                  algorithm_menu.close();
                              });
    algorithm_menu.add_option(3, "Quick sort (pivot: middle)",
                              [&type, &picked_algorithm_int, &picked_algorithm_float, &algorithm_menu] {
                                  if (type == INT) {
                                      picked_algorithm_int = &quick_middle_instance_int;
                                  } else {
                                      picked_algorithm_float = &quick_middle_instance_float;
                                  }
                                  algorithm_menu.close();
                              });
    algorithm_menu.add_option(4, "Quick sort (pivot: right)",
                              [&type, &picked_algorithm_int, &picked_algorithm_float, &algorithm_menu] {
                                  if (type == INT) {
                                      picked_algorithm_int = &quick_right_instance_int;
                                  } else {
                                      picked_algorithm_float = &quick_right_instance_float;
                                  }
                                  algorithm_menu.close();
                              });
    algorithm_menu.add_option(5, "Quick sort (pivot: random)",
                              [&type, &picked_algorithm_int, &picked_algorithm_float, &algorithm_menu] {
                                  if (type == INT) {
                                      picked_algorithm_int = &quick_random_instance_int;
                                  } else {
                                      picked_algorithm_float = &quick_random_instance_float;
                                  }
                                  algorithm_menu.close();
                              });
    algorithm_menu.add_option(6, "Heap sort",
                              [&type, &picked_algorithm_int, &picked_algorithm_float, &algorithm_menu] {
                                  if (type == INT) {
                                      picked_algorithm_int = &heap_instance_int;
                                  } else {
                                      picked_algorithm_float = &heap_instance_float;
                                  }
                                  algorithm_menu.close();
                              });
    algorithm_menu.add_option(7, "Insertion sort",
                              [&type, &picked_algorithm_int, &picked_algorithm_float, &algorithm_menu] {
                                  if (type == INT) {
                                      picked_algorithm_int = &insertion_instance_int;
                                  } else {
                                      picked_algorithm_float = &insertion_instance_float;
                                  }
                                  algorithm_menu.close();
                              });

    menu data_menu(7);
    data_menu.add_option(0, "Wyświetl aktualne dane", [&data_menu, &type, &int_data, &float_data] {
        if (type == INT) int_data.print();
        else float_data.print();
        std::cout << "\n";
        data_menu.close();
    });
    data_menu.add_option(1, "Wczytaj dane z pliku", [&data_menu, &type, &int_data, &float_data] {
        std::string file_name;
        std::cout << "# Podaj nazwe pliku: ";
        std::cin >> file_name;

        std::ifstream input_file(file_name);
        index_t data_size;
        input_file >> data_size;
        std::cout << "# Wczytywanie " << data_size << " wartości z pliku...\n";

        if (type == INT) {
            int_data = data<int>(data_size);
            for (index_t idx = 0; idx < data_size; idx++) {
                int buffer;
                input_file >> buffer;
                int_data[idx] = buffer;
            }
        } else {
            float_data = data<float>(data_size);
            for (index_t idx = 0; idx < data_size; idx++) {
                float buffer;
                input_file >> buffer;
                float_data[idx] = buffer;
            }
        }

        std::cout << "# Wczytano pomyślnie!\n";

        input_file.close();
        data_menu.close();
    });
    data_menu.add_option(2, "Wygeneruj całkowicie losowe dane", [&data_menu, &type, &int_data, &float_data] {
        index_t size;
        std::cout << "# Podaj wielkosc tablicy: ";
        std::cin >> size;
        if (type == INT) {
            auto buffer = data<int>::generate_random_data(size);
            int_data = data<int>(size, buffer);
        } else {
            auto buffer = data<float>::generate_random_data(size);
            float_data = data<float>(size, buffer);
        }
        data_menu.close();
    });
    data_menu.add_option(3, "Wygeneruj tablice posortowaną rosnąco", [&data_menu, &type, &int_data, &float_data] {
        index_t size;
        std::cout << "# Podaj wielkosc tablicy: ";
        std::cin >> size;
        if (type == INT) {
            auto buffer = data<int>::generate_sorted_data(size, 1);
            int_data = data<int>(size, buffer);
        } else {
            auto buffer = data<float>::generate_sorted_data(size, 1);
            float_data = data<float>(size, buffer);
        }
        data_menu.close();
    });
    data_menu.add_option(4, "Wygeneruj tablice posortowaną malejąco", [&data_menu, &type, &int_data, &float_data] {
        index_t size;
        std::cout << "# Podaj wielkosc tablicy: ";
        std::cin >> size;
        if (type == INT) {
            auto buffer = data<int>::generate_sorted_reversed_data(size);
            int_data = data<int>(size, buffer);
        } else {
            auto buffer = data<float>::generate_sorted_reversed_data(size);
            float_data = data<float>(size, buffer);
        }
        data_menu.close();
    });
    data_menu.add_option(5, "Wygeneruj tablice posortowaną w 33%", [&data_menu, &type, &int_data, &float_data] {
        index_t size;
        std::cout << "# Podaj wielkosc tablicy: ";
        std::cin >> size;
        if (type == INT) {
            auto buffer = data<int>::generate_sorted_data(size, 1./3);
            int_data = data<int>(size, buffer);
        } else {
            auto buffer = data<float>::generate_sorted_data(size, 1./3);
            float_data = data<float>(size, buffer);
        }
        data_menu.close();
    });
    data_menu.add_option(6, "Wygeneruj tablice posortowaną w 66%", [&data_menu, &type, &int_data, &float_data] {
        index_t size;
        std::cout << "# Podaj wielkosc tablicy: ";
        std::cin >> size;
        if (type == INT) {
            auto buffer = data<int>::generate_sorted_data(size, 2./3);
            int_data = data<int>(size, buffer);
        } else {
            auto buffer = data<float>::generate_sorted_data(size, 2./3);
            float_data = data<float>(size, buffer);
        }
        data_menu.close();
    });

    menu main_menu(7);
    main_menu.add_option(0, "Wykonaj wszystkie pomiary", [&display_values] {
        const int array_sizes[] = {1000, 2000, 5000, 10000, 20000, 50000, 100000};
        const unsigned long repeats = 100;

        std::cout << "\n # DLA TYPU INT \n\n";

        for (int gen = 0; gen < 1; ++gen) {
            std::cout << "#### Typ sortowania: " << gen << "\n";
            for (auto algorithm: int_algorithms) {
                std::string file_name = std::to_string(algorithm->get_id()).append("_out_int.txt");
                std::ofstream output_file(file_name, std::ios::app);

                std::cout << "=== ALGORYTM " << algorithm->get_id() << " ===\n";
                for (auto size: array_sizes) {
                    std::cout << "# Pomiary dla wielkości " << size << " elementów\n";

                    unsigned long total = 0;
                    for (int i = 0; i < repeats; i++) {
                        std::cout << "  > Generacja losowych wartości nr " << i + 1 << "\n";
                        std::unique_ptr<int[]> arr;
                        switch (gen) {
                            case 0:
                                arr = data<int>::generate_random_data(size);
                                break;
                            case 1:
                                arr = data<int>::generate_sorted_data(size, 1);
                                break;
                            case 2:
                                arr = data<int>::generate_sorted_reversed_data(size);
                                break;
                            case 3:
                                arr = data<int>::generate_sorted_data(size, 1./3);
                                break;
                            case 4:
                                arr = data<int>::generate_sorted_data(size, 2./3);
                                break;
                        }

                        std::cout << "  > Przekopiowanie wartości\n";
                        auto int_data = data(size, arr);

                        if (display_values) {
                            int_data.print();
                            std::cout << "\n";
                        }

                        std::cout << "  > Sortowanie...\n";
                        const auto start_time = std::chrono::high_resolution_clock::now();
                        algorithm->sort(int_data);
                        const auto end_time = std::chrono::high_resolution_clock::now();

                        total += std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();

                        bool sorted = int_data.is_sorted();
                        if (display_values) {
                            int_data.print();
                            std::cout << "\n";
                        }
                        std::cout << "  > Posortowane: " << sorted << "\n";

                        if (!sorted) {
                            std::cout << "  > BŁĄD ALGORYTMU " << algorithm->get_id() << "!!!\n";
                            break;
                        }
                    }
                    output_file << size << "," << (total / repeats) << "\n";
                }

                output_file.close();
            }
        }

        std::cout << "\n # DLA TYPU FLOAT \n\n";

        for (int gen = 0; gen < 5; ++gen) {
            std::cout << "#### Typ sortowania: " << gen << "\n";
            for (auto algorithm: float_algorithms) {
                std::string file_name = std::to_string(algorithm->get_id()).append("_out_float.txt");
                std::ofstream output_file(file_name, std::ios::app);

                std::cout << "=== ALGORYTM " << algorithm->get_id() << " ===\n";
                for (auto size: array_sizes) {
                    std::cout << "# Pomiary dla wielkości " << size << " elementów\n";

                    unsigned long total = 0;
                    for (int i = 0; i < repeats; i++) {
                        std::cout << "  > Generacja losowych wartości nr " << i + 1 << "\n";
                        std::unique_ptr<float[]> arr;
                        switch (gen) {
                            case 0:
                                arr = data<float>::generate_random_data(size);
                                break;
                            case 1:
                                arr = data<float>::generate_sorted_data(size, 1);
                                break;
                            case 2:
                                arr = data<float>::generate_sorted_reversed_data(size);
                                break;
                            case 3:
                                arr = data<float>::generate_sorted_data(size, 1. / 3);
                                break;
                            case 4:
                                arr = data<float>::generate_sorted_data(size, 2. / 3);
                                break;
                        }

                        std::cout << "  > Przekopiowanie wartości\n";
                        auto float_data = data(size, arr);

                        if (display_values) {
                            float_data.print();
                            std::cout << "\n";
                        }

                        std::cout << "  > Sortowanie...\n";
                        const auto start_time = std::chrono::high_resolution_clock::now();
                        algorithm->sort(float_data);
                        const auto end_time = std::chrono::high_resolution_clock::now();

                        total += std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();

                        bool sorted = float_data.is_sorted();
                        if (display_values) {
                            float_data.print();
                            std::cout << "\n";
                        }
                        std::cout << "  > Posortowane: " << sorted << "\n";

                        if (!sorted) {
                            std::cout << "  > BŁĄD ALGORYTMU " << algorithm->get_id() << "!!!\n";
                            break;
                        }
                    }
                    output_file << size << "," << (total / repeats) << "\n";
                }

                output_file.close();
            }
        }
    });
    main_menu.add_option(1, "Ustaw wyświetlanie tablic", [&display_values] {
        display_values = !display_values;
        std::cout << "# Wyświetlanie tablic: " << (display_values ? "włączone" : "wyłączone") << "\n";
    });
    main_menu.add_option(2, "Wybierz typ danych", [&type, &data_type_menu] {
        std::cout << "# Obecnie wybrany typ: " << type << "\n";
        data_type_menu.open();
    });
    main_menu.add_option(3, "Wybierz algorytm sortowania", [&algorithm_menu, &picked_algorithm_float, &picked_algorithm_int] {
        if (picked_algorithm_int == nullptr) {
            std::cout << "# Wybrany algorytm int (ID): brak\n";
        } else {
            std::cout << "# Wybrany algorytm int (ID): " << picked_algorithm_int->get_id() << "\n";
        }

        if (picked_algorithm_float == nullptr) {
            std::cout << "# Wybrany algorytm float (ID): brak\n";
        } else {
            std::cout << "# Wybrany algorytm float (ID): " << picked_algorithm_float->get_id() << "\n";
        }
        algorithm_menu.open();
    });
    main_menu.add_option(4, "Dane", [&data_menu] {
        data_menu.open();
    });
    main_menu.add_option(5, "Posortuj", [&type, &int_data, &float_data, &picked_algorithm_int, &picked_algorithm_float] {
        if (type == INT) {
            data<int> copy = data<int>(int_data);
            const auto start_time = std::chrono::high_resolution_clock::now();
            picked_algorithm_int->sort(copy);
            const auto end_time = std::chrono::high_resolution_clock::now();
            copy.print();
            std::cout << "\n";
            auto total = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
            std::cout << "Posortowano w " << total << " nanosekund.\n";
        } else {
            data<float> copy = data<float>(float_data);
            const auto start_time = std::chrono::high_resolution_clock::now();
            picked_algorithm_float->sort(copy);
            const auto end_time = std::chrono::high_resolution_clock::now();
            copy.print();
            std::cout << "\n";
            auto total = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
            std::cout << "Posortowano w " << total << " nanosekund.\n";
        }
    });
    main_menu.add_option(6, "Wyjście", [&main_menu] {
        main_menu.close();
    });
    main_menu.open();

    return 0;
}
