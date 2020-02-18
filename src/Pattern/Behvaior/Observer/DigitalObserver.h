#ifndef DIGITALOBSERVER_H
#define DIGITALOBSERVER_H

#include "NumGen.h"
#include "NumGenObserver.h"
#include <chrono>
#include <iostream>
#include <thread>

class DigitalObserver: public NumGenObserver
{
public:
    virtual void update(NumGen *gen) override
    {
        std::cout << gen->get_number() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
};

#endif /* DIGITALOBSERVER_H */
