#ifndef DECORATOR_FULL_BORDER_H
#define DECORATOR_FULL_BORDER_H

#include "Border.h"

class FullBorder: public Border
{
public:
    FullBorder(IDisplay *display) : Border(display) {}

    virtual int get_rows() const override
    {
        return 2 + _display->get_rows();
    }
    virtual int get_columns() const override
    {
        return 2 + _display->get_columns();
    }
    virtual std::string get_row(int index) const override
    {
        if (index == 0 || index == _display->get_rows() + 1)
            return "+" + make_line('-', _display->get_columns()) + "+";
        return "|" + _display->get_row(index - 1) + "|";
    }
private:
    std::string make_line(char ch, int count) const
    {
        std::string str(ch, count);
        return str;
    }
};

#endif