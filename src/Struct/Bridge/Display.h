#ifndef BRIDGE_DISPLAY_H
#define BRIDGE_DISPLAY_H
#include "IDisplayImpl.h"
class Display
{
public:
    Display(IDisplayImpl *impl) : _impl(impl) {}
    virtual ~Display() {}

    virtual void open() {
        _impl->raw_open();
    }

    virtual void close() {
        _impl->raw_close();
    }

    virtual void print() {
        _impl->raw_print();
    }

    void display() {
        open();
        print();
        close();
    }
    
private:
    IDisplayImpl *_impl;
};

#endif
