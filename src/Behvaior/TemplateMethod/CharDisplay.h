#ifndef CHARDISPLAY_H
#define CHARDISPLAY_H

#include "IDisplay.h"
#include <iostream>

class CharDisplay: public IDisplay
{
public:
    CharDisplay(const char *str) : _str(str) {}
    ~CharDisplay() {}

    void open() override
    {
        std::cout << "++++++++++++++" << std::endl;
    }

    void close() override
    {
        std::cout << "++++++++++++++" << std::endl;
    }

    void print() override
    {
        std::cout << _str << std::endl;
    }

private:
    const char *_str;
};

#endif /* CHARDISPLAY_H */
