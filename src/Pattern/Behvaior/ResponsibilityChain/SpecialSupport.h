#ifndef SPECIALSUPPORT_H
#define SPECIALSUPPORT_H

#include "Support.h"

class SpecialSupport: public Support
{
public:
    SpecialSupport(const std::string &name, int num)
        : Support(name),
          _num(num)
    {

    }

    bool resolve(Trouble *trouble) override
    {
        return trouble->get_number() == _num;
    }
private:
    int _num;
};

#endif /* SPECIALSUPPORT_H */
