#ifndef CREATE_PROTOTYPE_MESSAGEBOX_H
#define CREATE_PROTOTYPE_MESSAGEBOX_H

#include "IProduct.h"
#include <string>
#include <iostream>

class MessageBox: public IProduct
{
public:
    MessageBox(const std::string &name): _name(name) {}

    IProduct *clone() override
    {
        return new MessageBox(_name);
    }

    void use(const std::string &str) override
    {
        std::cout << "MessageBox" << _name << " " << str << std::endl;
    }
private:
    std::string _name;
};

#endif