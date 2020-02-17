#ifndef ELEMENT_H
#define ELEMENT_H

class Visitor;
class Element
{
public:
    virtual ~Element() {}
    virtual void accept(Visitor *visitor) = 0;
};
#endif /* ELEMENT_H */
