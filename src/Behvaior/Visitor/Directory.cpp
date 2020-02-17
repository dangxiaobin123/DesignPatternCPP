#include "Directory.h"
#include "Visitor.h"
Directory::Directory(const std::string &name): _file_name(name)
{
    //TODO
}

Directory::~Directory()
{
    for (auto entr : _dirs) {
        delete entr;
    }
    _dirs.clear();
}

std::string Directory::get_name() const
{
    return _file_name;
}

int Directory::get_size() const
{
    int size = 0;
    for (auto entr : _dirs) {
        size += entr->get_size();
    }
    return size;
}

void Directory::add_entry(Entry *entry)
{
    _dirs.push_back(entry);
}

void Directory::accept(Visitor *visitor)
{
    visitor->visit(this);
}

const std::vector<Entry *> &Directory::get_entry_list()
{
    return _dirs;
}

void Directory::print_list(const std::string &str)
{
    std::cout << str << "/" << to_string() << std::endl;
    for (auto it : _dirs) {
        it->print_list(str + "/" + _file_name);
    }
}

