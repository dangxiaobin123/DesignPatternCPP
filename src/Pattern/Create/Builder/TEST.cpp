#define CATCH_CONFIG_MAIN
#include "TextBuilder.h"
#include "Director.h"
#include <iostream>
#include <string>
#include <catch.hpp>
using namespace std;

TEST_CASE("Builder Pattern")
{
    TextBuilder *builder = new TextBuilder();
    Director director(builder);
    director.construct();
    std::cout<<builder->get_result()<<std::endl;
    delete builder;
    builder = nullptr;
}
