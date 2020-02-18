#define CATCH_CONFIG_MAIN
#include "Gamer.h"
#include "Memento.h"
#include <memory>
#include <catch.hpp>

TEST_CASE("Memento pattern")
{
    Gamer g(100);
    Memento mo = g.create_memento();
    for (int i = 0; i < 100; i++) {
        std::cout << "===== " + i << std::endl;
        std::cout << g.to_string() << std::endl;
        g.bet();
        if (g.get_money() > mo.get_money()) {
            mo = g.create_memento();
            std::cout << "add money, save " << std::endl;
        } else if (g.get_money() < mo.get_money() / 2) {
            g.restore(mo);
            std::cout << "dec money, restore" << std::endl;
        }
    }
}

