#ifndef IFACTORY_H
#define IFACTORY_H

#include <string>

class IProduct;

class IFactory
{
public:
    virtual ~IFactory() {}
    virtual void register_product(IProduct *) = 0;
    virtual IProduct *create_product(const std::string &owner) = 0;
    virtual IProduct *create(const std::string &owner)
    {
        auto pro = create_product(owner);
        register_product(pro);
        return pro;
    }
};

#endif /* IFACTORY_H */
