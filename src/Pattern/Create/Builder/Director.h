#ifndef BUILDER_DIRECTOR_H
#define BUILDER_DIRECTOR_H

#include "IBuilder.h"

class Director
{
public:
    Director(IBuilder *builder) : _builder(builder) {}

    void construct()
    {
        _builder->make_title("Greeting");
        _builder->make_string(u8"白天");
        _builder->make_items(std::vector<std::string>{u8"语文", u8"英语", u8"数学", u8"物理"});
        _builder->make_string(u8"晚上");
        _builder->make_items(std::vector<std::string>{u8"生物", u8"化学", u8"数学"});
        _builder->close();
    }
private:
    IBuilder *_builder;
};

#endif