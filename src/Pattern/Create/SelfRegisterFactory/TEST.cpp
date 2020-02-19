#define CATCH_CONFIG_MAIN
#include "MessageFactory.h"
#include "Message1.h"
#include <catch.hpp>
using namespace std;

TEST_CASE("Factory")
{
    auto p = Factory::produce("Message1");
    p->foo();
    auto up = Factory::produce_unique("Message1");
    up->foo();
    auto sp = Factory::produce_shared("Message1");
    sp->foo();
    REQUIRE(p!=up.get());
    REQUIRE(p!=sp.get());
    REQUIRE_THROWS(Factory::produce("Message2"));
    delete p;
}
