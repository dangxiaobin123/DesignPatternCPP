#define CATCH_CONFIG_MAIN
#include "MessageFactory.h"
#include "Message1.h"
#include <catch.hpp>
using namespace std;

TEST_CASE("Factory")
{
    auto p = Factory::produce("Message1");
    p->foo();
    delete p;
    auto up = Factory::produce_unique("Message1");
    up->foo();
    auto sp = Factory::produce_shared("Message1");
    up->foo();
}
