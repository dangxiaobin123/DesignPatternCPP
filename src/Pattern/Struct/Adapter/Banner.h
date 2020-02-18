#ifndef ADAPTER_BANNER_H
#define ADAPTER_BANNER_H

#include <string>
#include <iostream>

class Banner
{
public:
    Banner(const std::string &str): _str(str) {}

    void show_with_paren()
    {
        std::cout << "(" << _str << ")" << std::endl;
    }

    void show_with_aster()
    {
        std::cout << "*" << _str << "*" << std::endl;
    }
private:
    std::string _str;
};

#endif