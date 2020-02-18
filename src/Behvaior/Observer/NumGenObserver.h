#ifndef NUMGENOBSERVER_H
#define NUMGENOBSERVER_H

#include <iostream>
class NumGen;
class NumGenObserver
{
public:
    virtual ~NumGenObserver() {}
    virtual void update(NumGen *) = 0;
};

#endif /* NUMGENOBSERVER_H */
