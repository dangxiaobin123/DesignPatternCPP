#define CATCH_CONFIG_MAIN
#include "CountDisplay.h"
#include "StringDisplayImpl.h"
#include "IDisplayImpl.h"
#include <memory>
#include <string>
#include <catch.hpp>
using namespace std;

TEST_CASE("Bridge")
{
    std::shared_ptr<IDisplayImpl> impl1(new StringDisplayImpl("hello, China"));
    std::shared_ptr<Display> d1(new Display(impl1.get()));

    std::shared_ptr<IDisplayImpl> impl2(new StringDisplayImpl("Hello, Tao"));
    std::shared_ptr<Display> d2(new CountDisplay(impl2.get()));

    std::shared_ptr<IDisplayImpl> impl3(new StringDisplayImpl("Hello,Universe"));
    std::shared_ptr<CountDisplay> d3(new CountDisplay(impl3.get()));

    d1->display();
    d2->display();
    d3->display();
    d3->multi_display(4);
}
