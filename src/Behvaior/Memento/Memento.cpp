#include "Memento.h"

Memento::Memento(int money) : _money(money)
{
    //TODO
}
/**
 * Memento 
 * 
 * @return {int}  : 
 */
int Memento::get_money() const
{
    return _money;
}
/**
 * Memento 
 * 
 * @param  {std::string} fruit : 
 */
void Memento::add_fruit(const std::string &fruit)
{
    _fruits.push_back(fruit);
}
/**
 * Memento 
 * 
 * @return {std::vector<std::string>}  : 
 */
const std::vector<std::string> &Memento::get_fruits() const
{
    return _fruits;
}

