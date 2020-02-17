#include "File.h"
#include "Visitor.h"
File::File(const std::string &name, int size)
    : _file_name(name),
      _file_size(size)
{
    //TODO
}

std::string File::get_name() const
{
    return _file_name;
}

int File::get_size() const
{
    return _file_size;
}

void File::print_list(const std::string &str)
{
    std::cout << str << "/" << to_string() << std::endl;
}

void File::accept(Visitor *visitor)
{
    visitor->visit(this);
}

