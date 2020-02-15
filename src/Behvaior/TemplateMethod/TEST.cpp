#define CATCH_CONFIG_MAIN
#include "CharDisplay.h"
#include "StringDisplay.h"
#include <memory>
#include <catch.hpp>

TEST_CASE("TemplateMethod pattern")
{
    auto d1 = std::unique_ptr<IDisplay>(new CharDisplay("hello"));
    d1->display();

    auto d2 = std::unique_ptr<IDisplay>(new StringDisplay("world"));
    d2->display();
}

