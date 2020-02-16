#ifndef ICOLLEAGUE_H
#define ICOLLEAGUE_H

#include <string>
#include "IMediator.h"
class IMediator;
class IColleague
{
public:
    IColleague() {}
    IColleague(int id, IMediator *mediator)
    {
        mediator->register_colleague(id, this);
    }
    virtual ~IColleague() {}
    virtual void receive_msg(const std::string &msg) = 0;
    virtual void send_msg(int id, const std::string &msg) = 0;
    void set_mediator(IMediator *mediator)
    {
        _mediator = mediator;
    }

    IMediator *get_mediator()
    {
        return _mediator;
    }
private:
    IMediator *_mediator;
};

#endif /* ICOLLEAGUE_H */
