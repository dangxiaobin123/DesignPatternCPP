#ifndef DECORATOR_SIDE_BORDER_H
#define DECORATOR_SIDE_BORDER_H

#include "Border.h"

class SideBorder: public Border
{
public:
    SideBorder(IDisplay *display, const char &border_char)
        : Border(display),
          _border_char(border_char)
    {

    }

    virtual int get_rows() const override
    {
        return _display->get_rows();
    }
    virtual int get_columns() const override
    {
        return 2 + _display->get_columns();
    }
    virtual std::string get_row(int index) const override
    {
        return _border_char + _display->get_row(index) + _border_char;
    }
private:
    char _border_char;
};

#endif