#ifndef IPRODUCT_H
#define IPRODUCT_H

class IProduct
{
public:
    virtual ~IProduct() {}
    virtual void use() = 0;
};

#endif /* IPRODUCT_H */
