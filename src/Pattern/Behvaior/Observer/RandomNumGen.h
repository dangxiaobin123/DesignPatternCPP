#ifndef RANDOMNUMGEN_H
#define RANDOMNUMGEN_H

#include "NumGen.h"
#include <random>

class RandomNumGen: public NumGen
{
public:
    virtual int get_number() override
    {
        return _num;
    }

    virtual void execute() override
    {
        for(int i = 0;i < 20;i++)
        {
            _num = _dis(_gen);
            notify_all();
        }
    }
private:
    std::random_device _rd;
    std::mt19937 _gen{_rd()};
    std::uniform_int_distribution<int> _dis{0, 100};
    int _num = 0;
};

#endif /* RANDOMNUMGEN_H */
