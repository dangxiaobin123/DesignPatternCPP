#ifndef PROXY_PRINTER_PROXY_H
#define PROXY_PRINTER_PROXY_H

#include "Printer.h"

class PrinterProxy: public Printable
{
public:
    PrinterProxy(const std::string &name): _name(name) {}
    virtual ~PrinterProxy()
    {
        delete _printer;
        _printer = nullptr;
    }

    virtual void set_printer_name(const std::string &name) override
    {
        if (_printer != nullptr) {
            _printer->set_printer_name(name);
        }
        _name = name;
    }

    virtual const std::string &get_printer_name() const override
    {
        return _name;
    }

    virtual void print() override
    {
        if (_printer == nullptr) {
            _printer = new Printer(_name);
        }
        _printer->print();
    }
private:
    Printer *_printer = nullptr;
    std::string _name;
};

#endif