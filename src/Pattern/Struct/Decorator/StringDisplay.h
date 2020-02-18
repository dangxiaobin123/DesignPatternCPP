#ifndef DECORATOR_STRING_DISPLAY_H
#define DECORATOR_STRING_DISPLAY_H

#include "IDisplay.h"

class StringDisplay: public IDisplay
{
public:
    StringDisplay(const std::string &str) : _str(str) {}

    virtual int get_rows() const override
    {
        return 1;
    }
    virtual int get_columns() const override
    {
        return _str.length();
    }
    virtual std::string get_row(int index) const override
    {
        return !index ? _str : std::string{};
    }
private:
    std::string _str;
};


#endif