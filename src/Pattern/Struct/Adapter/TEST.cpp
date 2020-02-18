#define CATCH_CONFIG_MAIN
#include "PainterBanner.h"
#include "BannerPainter.h"
#include <memory>
#include <string>
#include <catch.hpp>
using namespace std;

//多继承方式实现适配器
TEST_CASE("Adapter01")
{
    Painter* painter = new PainterBanner(std::string("hello world"));
    painter->print_strong();
    painter->print_weak();
    delete painter;
}

//组合持有方式实现适配器
TEST_CASE("Adapter02")
{
    Painter* painter = new BannerPainter(std::string("hello world"));
    painter->print_strong();
    painter->print_weak();
    delete painter;
}
