#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include "Element.h"

class Entry: public Element
{
public:
    virtual ~Entry() {}
    virtual std::string get_name() const = 0;
    virtual int get_size() const = 0;
    virtual void add_entry(Entry*) {}
    virtual void print_list(const std::string &str) = 0;

    void print_list()
    {
        print_list("");
    }

    std::string to_string() const
    {
        return get_name() + "( " + std::to_string(get_size()) + " )";
    }
};

#endif /* ENTRY_H */
