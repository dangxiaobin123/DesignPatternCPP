#include "IDCardFactory.h"

void IDCardFactory::register_product(IProduct *pro)
{
    _product_list.push_back(pro);
}

IProduct *IDCardFactory::create_product(const std::string &owner)
{
    return new IDCard(owner);
}

