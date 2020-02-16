#ifndef MEMENTO_H
#define MEMENTO_H

#include <string>
#include <vector>

class Memento
{
public:
    Memento(int money);
    int get_money() const;
    void add_fruit(const std::string &fruit);
    const std::vector<std::string> &get_fruits() const;
private:
    int _money;
    std::vector<std::string> _fruits;
};

#endif /* MEMENTO_H */
