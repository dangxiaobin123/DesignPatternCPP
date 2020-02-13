#ifndef STATE_NIGHTSTATE_H
#define STATE_NIGHTSTATE_H

#include "IState.h"
#include "IContext.h"

class NightState: public IState
{
public:
    static NightState &Get_Instance()
    {
        static NightState ins;
        return ins;
    }

    virtual void clock(IContext *ctx, int hour) override ;

    virtual void use(IContext *ctx) override;

    virtual void alarm(IContext *ctx) override;

    virtual void call(IContext *ctx) override;

    virtual ~NightState() {};

    NightState(const NightState & ) = delete;

    NightState(NightState &&) = delete;

    NightState& operator=(const NightState &) = delete;

    NightState& operator=(NightState &&) = delete;
protected:
    NightState() {}
};

#endif
