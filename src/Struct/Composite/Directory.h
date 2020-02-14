#ifndef COMPOSITE_DIRECTORY_H
#define COMPOSITE_DIRECTORY_H

#include "Entry.h"
#include <vector>
#include <string>
#include <iostream>
#include <numeric>

class Directory: public Entry
{
public:
    Directory(const std::string &name) : _name(name) {}

    ~Directory()
    {
        for (auto entr : _dirs) {
            delete entr;
            entr = nullptr;
        }
        _dirs.clear();
    }

    virtual std::string get_name() const override
    {
        return _name;
    }

    virtual int get_size() const override
    {
        int size = 0;
        for (auto entr : _dirs) {
            size += entr->get_size();
        }
        return size;
    }

    virtual void add_entry(Entry *entry) override
    {
        _dirs.push_back(entry);
    }

    virtual void print_list(const std::string &str) override
    {
        std::cout << str << "/" << to_string() << std::endl;
        for (auto entr : _dirs) {
            entr->print_list(str + "/" + _name);
        }
    }


private:
    std::string _name;
    std::vector<Entry *> _dirs;
};


#endif