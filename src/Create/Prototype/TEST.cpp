#define CATCH_CONFIG_MAIN
#include "ProductManager.h"
#include "MessageBox.h"
#include <iostream>
#include <string>
#include <catch.hpp>
using namespace std;

TEST_CASE("Prototype")
{
    ProductManager mgr;
    IProduct* pro = new MessageBox("hello");
    mgr.registers("mb", pro);
    pro->use("world");
    auto p = mgr.create("mb");
    p->use("world");
    auto pp = mgr.create("no");
    REQUIRE(pp==nullptr);
    delete pro;
    delete p;
    delete pp;
}
