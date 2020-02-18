#ifndef GAMER_H
#define GAMER_H
#include "Memento.h"
#include <iostream>
#include <random>

class Gamer
{
public:
    Gamer(int money);
    ~Gamer() ;

    int get_money() const;

    void bet();

    std::string get_fruit();

    std::string to_string();

    Memento create_memento();

    void restore(const Memento &memnto);

private:
    int _money;
    std::vector<std::string> _fruits;

    std::random_device _rd;
    std::mt19937 _gen{_rd()};
    std::uniform_int_distribution<int> _dis{0, 6};

    std::string _fruits_name[4] = {"apple", "grape", "orange", "banana"};
};

#endif /* GAMER_H */
