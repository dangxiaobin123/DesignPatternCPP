#define CATCH_CONFIG_MAIN
#include "IDCardFactory.h"
#include <memory>
#include <catch.hpp>
using namespace std;

TEST_CASE("Prototype")
{
    auto fac = std::unique_ptr<IFactory>(new IDCardFactory);
    auto t1 = std::unique_ptr<IProduct>(fac->create("tao"));
    auto t2 = std::unique_ptr<IProduct>(fac->create("wang"));
    t1->use();
    t2->use();
}
