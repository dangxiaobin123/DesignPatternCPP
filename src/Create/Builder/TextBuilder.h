#ifndef BUILDER_TEXT_BUILDER_H
#define BUILDER_TEXT_BUILDER_H

#include "IBuilder.h"

class TextBuilder: public IBuilder
{
public:
    void make_title(const std::string &title) override
    {
        _str.append("============================\n");
        _str.append("[" + title + "]\n");
        _str.append("\n");
    }

    void make_string(const std::string &str) override
    {
        _str.append(" * " + str + "\n");
        _str.append("\n");
    }

    void make_items(const std::vector<std::string> &items) override
    {
        for(auto item: items) {
            _str.append(" .  " + item + "\n");
        }
        _str.append("\n");
    }

    void close() override
    {
        _str.append("============================\n");
    }

    std::string get_result() const 
    {
        return _str;
    }
private:
    std::string _str;
};

#endif