#ifndef LIMITSUPPORT_H
#define LIMITSUPPORT_H

#include "Support.h"

class LimitSupport: public Support
{
public:
    LimitSupport(const std::string &name, int limit)
        : Support(name),
          _limit(limit)
    {

    }

    bool resolve(Trouble *trouble) override
    {
        return trouble->get_number() <= _limit;
    }
private:
    int _limit;
};

#endif /* LIMITSUPPORT_H */
