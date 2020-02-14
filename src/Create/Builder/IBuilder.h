#ifndef BUILDER_IBUILDER_H
#define BUILDER_IBUILDER_H

#include <string>
#include <vector>

class IBuilder
{
public:
    virtual ~IBuilder() {}
    virtual void make_title(const std::string &title) = 0;
    virtual void make_string(const std::string &str) = 0;
    virtual void make_items(const std::vector<std::string> &items) = 0;
    virtual void close() = 0;
};

#endif