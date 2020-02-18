#ifndef BRIDGE_STRING_DISPLAY_IMPL_H
#define BRIDGE_STRING_DISPLAY_IMPL_H

#include "IDisplayImpl.h"
#include <string>
#include <iostream>

class StringDisplayImpl: public IDisplayImpl
{
public:
    StringDisplayImpl(const std::string &str): _str(str) {}

    virtual void raw_open() override
    {
        print_line();
    }

    virtual void raw_close() override
    {
        print_line();
    }

    virtual void raw_print() override
    {
        std::cout << "|" << _str << "|" << std::endl;
    }
private:
    void print_line()
    {
        std::cout << "+";
        for (int i = 0; i < _str.length(); i++) std::cout << "-";
        std::cout << "+" << std::endl;
    }
private:
    std::string _str;
};


#endif
