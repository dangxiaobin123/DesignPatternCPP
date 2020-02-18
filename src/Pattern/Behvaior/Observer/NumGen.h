#ifndef NUMGEN_H
#define NUMGEN_H

#include "NumGenObserver.h"
#include <vector>
#include <algorithm>

class NumGen
{
public:
    virtual ~NumGen() {}

    void add_observer(NumGenObserver *observer)
    {
        _observer_list.push_back(observer);
    }

    void delete_observer(NumGenObserver *observer)
    {
        _observer_list.erase(std::remove(_observer_list.begin(), _observer_list.end(), observer), _observer_list.end());
    }

    void notify_all()
    {
        std::for_each(_observer_list.begin(), _observer_list.end(), [this](NumGenObserver * ob) {
            ob->update(this);
        });
    }

    virtual int get_number() = 0;

    virtual void execute() = 0;

private:
    std::vector<NumGenObserver *> _observer_list;
};


#endif /* NUMGEN_H */
