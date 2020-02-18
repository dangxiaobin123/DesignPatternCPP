#ifndef COMPOSITE_FILE_H
#define COMPOSITE_FILE_H

#include "Entry.h"
#include <iostream>

class File: public Entry
{
public:
    File(const std::string &name, int size): _name(name), _size(size) {}

    virtual std::string get_name() const override
    {
        return _name;
    }

    virtual int get_size() const override
    {
        return _size;
    }

    virtual void print_list(const std::string &str) override
    {
        std::cout << str << "/" << to_string() << std::endl;
    }
private:
    std::string _name;
    int _size;
};

#endif