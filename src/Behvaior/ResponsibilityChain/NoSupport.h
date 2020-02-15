#ifndef NOSUPPORT_H
#define NOSUPPORT_H

#include "Support.h"
class NoSupport: public Support
{
public:
    using Support::Support;
    virtual bool resolve(Trouble *trouble) override
    {
        return false;
    }
};

#endif /* NOSUPPORT_H */
