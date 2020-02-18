#ifndef BRIDGE_IDISPLAYIMPL_H
#define BRIDGE_IDISPLAYIMPL_H

class IDisplayImpl
{
public:
    virtual ~IDisplayImpl() {}
    virtual void raw_open() = 0;
    virtual void raw_close() = 0;
    virtual void raw_print() = 0;
};

#endif