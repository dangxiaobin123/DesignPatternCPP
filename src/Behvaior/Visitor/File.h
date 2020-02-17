#ifndef FILE_H
#define FILE_H

#include "Entry.h"
#include <iostream>

class File: public Entry
{
public:
    File(const std::string &name, int size);

    virtual std::string get_name() const override;

    virtual int get_size() const override;

    virtual void print_list(const std::string &str) override;

    virtual void accept(Visitor *visitor) override;

private:
    std::string _file_name;
    int _file_size;
};

#endif /* FILE_H */
