#ifndef IDCARD_H
#define IDCARD_H

#include "IProduct.h"
#include <string>
#include <iostream>

class IDCard: public IProduct
{
public:
    IDCard(const std::string &owner);
    virtual ~IDCard() {}

    virtual void use() override;
private:
    std::string _owner;
};

#endif /* IDCARD_H */
