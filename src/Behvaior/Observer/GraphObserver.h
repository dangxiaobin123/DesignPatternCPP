#ifndef GRAPHOBSERVER_H
#define GRAPHOBSERVER_H

#include "NumGenObserver.h"
#include "NumGen.h"
#include <thread>
#include <chrono>
#include <iostream>

class GraphObserver: public NumGenObserver
{
public:
    virtual void update(NumGen *gen) override
    {
        auto num = gen->get_number();
        std::cout << "GraphObserver: ";
        for (int i = 0; i < num; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
};

#endif /* GRAPHOBSERVER_H */
