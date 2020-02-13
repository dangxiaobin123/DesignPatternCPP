#ifndef CREATE_PROTOTYPE_IPRODUCT_H
#define CREATE_PROTOTYPE_IPRODUCT_H

#include <string>

class IProduct
{
public:
    virtual ~IProduct() {}
    virtual IProduct *clone() = 0;
    virtual void use(const std::string &str) = 0;
};

#endif