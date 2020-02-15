#ifndef ODDSUPPORT_H
#define ODDSUPPORT_H

#include "Support.h"

class OddSupport: public Support
{
public:
    using Support::Support;

    virtual bool resolve(Trouble *trouble) override
    {
        return !(trouble->get_number() % 2);
    }
};

#endif /* ODDSUPPORT_H */
