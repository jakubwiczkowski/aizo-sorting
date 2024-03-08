#ifndef MENU_H
#define MENU_H
#include <functional>
#include <memory>

#include "../data/data.h"


class menu {
    index_t menu_size;
    bool is_open = false;
    std::unique_ptr<const char*[]> titles;
    std::unique_ptr<std::function<void()>[]> functions;

    void print_menu();

public:
    explicit menu(index_t menu_size);

    void add_option(index_t index, const char title[], std::function<void()> to_execute) const;

    void open();
    void close();
};



#endif //MENU_H
