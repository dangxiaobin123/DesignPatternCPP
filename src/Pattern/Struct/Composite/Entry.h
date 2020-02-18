#ifndef COMPOSITE_ENTRY_H
#define COMPOSITE_ENTRY_H

#include <string>
class Entry
{
public:
    virtual ~Entry() {}
    virtual std::string get_name() const = 0;
    virtual int get_size() const = 0;
    virtual void add_entry(Entry *entry) {};
    virtual void print_list(const std::string &str) = 0;

    void print_list1()
    {
        print_list("");
    }

    std::string to_string() const
    {
        return get_name() + " (" + std::to_string(get_size()) + ")";
    }
};

#endif