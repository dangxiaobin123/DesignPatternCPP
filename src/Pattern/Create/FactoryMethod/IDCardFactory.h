#ifndef IDCARDFACTORY_H
#define IDCARDFACTORY_H

#include "IDCard.h"
#include "IFactory.h"
#include <string>
#include <vector>

class IDCardFactory : public IFactory
{
public:
    virtual void register_product(IProduct *pro) override;

    virtual IProduct *create_product(const std::string &owner) override;
private:
    std::vector<IProduct *> _product_list;
};

#endif /* IDCARDFACTORY_H */
