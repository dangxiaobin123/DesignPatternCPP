#ifndef PROXY_PRINTABLE_H
#define PROXY_PRINTABLE_H

#include <string>

class Printable
{
public:
    virtual ~Printable( ) {}
    virtual void set_printer_name(const std::string &name) = 0;
    virtual const std::string &get_printer_name() const = 0;
    virtual void print() = 0;
};

#endif