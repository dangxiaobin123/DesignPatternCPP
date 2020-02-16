#ifndef IMEDIATOR_H
#define IMEDIATOR_H

#include <string>

class IColleague;

class IMediator
{
public:
    virtual ~IMediator() {}
    virtual void oper(int id, const std::string &msg) = 0;
    virtual void register_colleague(int id, IColleague *) = 0;
};

#endif /* IMEDIATOR_H */
