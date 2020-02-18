#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "Entry.h"
#include <iostream>
#include <string>
#include <vector>

class Directory: public Entry
{
public:
    Directory(const std::string &name);
    virtual ~Directory();

    virtual std::string get_name() const override;

    virtual int get_size() const override;

    virtual void add_entry(Entry *entry) override;

    virtual void accept(Visitor *visitor) override;

    const std::vector<Entry*> &get_entry_list() ;

    virtual void print_list(const std::string &str) override;
private:
    std::string _file_name;
    std::vector<Entry*> _dirs;
};

#endif /* DIRECTORY_H */
