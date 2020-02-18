#ifndef DECORATOR_BORDER_H
#define DECORATOR_BORDER_H

#include "IDisplay.h"

class Border: public IDisplay
{
public:
    Border(IDisplay *display) : _display(display) {}
    virtual ~Border() 
    {
        delete _display;
        _display = nullptr;
    }
protected:
    IDisplay *_display;
};

#endif