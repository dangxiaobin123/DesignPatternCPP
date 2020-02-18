#include "Gamer.h"

Gamer::Gamer(int money): _money(money)
{
    //TODO
}

Gamer::~Gamer()
{
    //TODO
}

int Gamer::get_money() const
{
    return _money;
}

void Gamer::bet()
{
    int dice = _dis(_gen) + 1;
    if (dice == 1) {
        _money += 100;
        std::cout << "money add" << std::endl;
    } else if (dice == 2) {
        _money /= 2;
        std::cout << "money dec" << std::endl;
    } else if (dice == 6) {
        auto f = get_fruit();
        _fruits.push_back(f);
        std::cout << "get fruit " << f << std::endl;
    }
}

std::string Gamer::get_fruit()
{
    return _fruits_name[_dis(_gen) % 4];
}

std::string Gamer::to_string()
{
    std::string str;
    str = "[money = " + std::to_string(_money) + ", fruits = ";
    for (auto f : _fruits) {
        str += f + " ";
    }
    str += " ]";
    return str;
}

Memento Gamer::create_memento()
{
    Memento m(_money);
    for (auto f : _fruits) m.add_fruit(f);
    return m;
}

void Gamer::restore(const Memento &memnto)
{
    _money = memnto.get_money();
    _fruits = memnto.get_fruits();
}

