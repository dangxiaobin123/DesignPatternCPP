#ifndef CMEDIATOR_H
#define CMEDIATOR_H

#include "IMediator.h"
#include "IColleague.h"
#include <unordered_map>

class CMediator: public IMediator
{
public:
    CMediator(/* args */) {}
    ~CMediator() {}

    virtual void oper(int id, const std::string &msg) override
    {
        if (_map.count(id)) _map[id]->receive_msg(msg);
    }

    virtual void register_colleague(int id, IColleague *col) override
    {
        if (!_map.count(id)) {
            _map.emplace(id, col);
            col->set_mediator(this);
        }
    }
private:
    std::unordered_map<int, IColleague *> _map;
};

#endif /* CMEDIATOR_H */
