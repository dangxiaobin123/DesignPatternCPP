#ifndef STRINGDISPLAY_H
#define STRINGDISPLAY_H

#include "IDisplay.h"
#include <iostream>
#include <string>

class StringDisplay: public IDisplay
{
public:
    StringDisplay(const std::string &str): _str(str) {}
    ~StringDisplay() {}

    void open() override
    {
        std::cout << "++++++++++++" << std::endl;
    }

    void close() override
    {
        std::cout << "++++++++++++" << std::endl;
    }

    void print() override
    {
        std::cout << _str << std::endl;
    }
private:
    std::string _str;
};

#endif /* STRINGDISPLAY_H */
