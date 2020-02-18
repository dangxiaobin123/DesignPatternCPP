#ifndef PROXY_PRINTER_H
#define PROXY_PRINTER_H

#include "Printable.h"
#include <thread>
#include <chrono>
#include <iostream>

class Printer: public Printable
{
public:
    Printer(const std::string &name): _name(name)
    {
        heavy_job();
    }

    virtual void set_printer_name(const std::string &name) override
    {
        _name = name;
    }

    virtual const std::string &get_printer_name() const override
    {
        return _name;
    }

    virtual void print() override
    {
        std::cout << __FUNCTION__ << get_printer_name() << std::endl;
    }
private:
    void heavy_job()
    {
        std::cout << __FUNCTION__ << "start" << std::endl;
        for (int i = 0; i < 5; i++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
        std::cout << __FUNCTION__ << "end" << std::endl;
    }
private:
    std::string _name;
};


#endif