#ifndef CCOLLEAGUE2_H
#define CCOLLEAGUE2_H

#include "IColleague.h"
#include "IMediator.h"
#include <iostream>

class CColleague2: public IColleague
{
public:
    using IColleague::IColleague;
    virtual ~CColleague2() {}

    virtual void send_msg(int id, const std::string &msg) override
    {
        std::cout << __FUNCTION__ << id << " " << msg << std::endl;
        if (get_mediator()) get_mediator()->oper(id, msg);
    }

    virtual void receive_msg(const std::string &msg) override
    {
        std::cout << __FUNCTION__ << " " << msg << std::endl;
    }
};

#endif /* CCOLLEAGUE2_H */
