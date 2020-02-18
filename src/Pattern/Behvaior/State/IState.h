#ifndef STATE_ISTATE_H
#define STATE_ISTATE_H

class IContext;
class IState
{
public:
    virtual ~IState() {}
    virtual void clock(IContext *ctx, int hour) = 0;
    virtual void use(IContext *ctx) = 0;
    virtual void alarm(IContext *ctx) = 0;
    virtual void call(IContext *ctx) = 0;
};

#endif