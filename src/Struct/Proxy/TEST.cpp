#define CATCH_CONFIG_MAIN
#include "PrinterProxy.h"
#include <string>
#include <catch.hpp>
using namespace std;

//多继承方式实现适配器
TEST_CASE("Proxy")
{
    Printable *p = new PrinterProxy("123");
    std::cout << p->get_printer_name() << std::endl;
    p->set_printer_name("456");
    std::cout << p->get_printer_name() << std::endl;
    p->print();
    p->set_printer_name("789");
    p->print();
    delete p;
}
