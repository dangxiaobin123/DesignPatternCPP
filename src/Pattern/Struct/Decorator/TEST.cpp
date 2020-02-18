#define CATCH_CONFIG_MAIN

#include "FullBorder.h"
#include "SideBorder.h"
#include "StringDisplay.h"
#include <string>
#include <catch.hpp>
using namespace std;

TEST_CASE("Decorator")
{
    IDisplay *d1 = new StringDisplay("Hello");
    IDisplay *d2 = new SideBorder(d1, '#');
    IDisplay *d3 = new FullBorder(d2);

    d1->show();
    d2->show();
    d3->show();
//    IDisplay *d4 = new SideBorder(new FullBorder(new FullBorder(new SideBorder(new FullBorder(new StringDisplay("Hello,World")), '*'))), '/');
//    d4->show();
    
}
