#ifndef STATE_DAYSTATE_H
#define STATE_DAYSTATE_H

#include "IState.h"
#include "IContext.h"

class DayState: public IState
{
public:
    static DayState &Get_Instance()
    {
        static DayState ins;
        return ins;
    }

    virtual void clock(IContext *ctx, int hour) override ;

    virtual void use(IContext *ctx) override;

    virtual void alarm(IContext *ctx) override;

    virtual void call(IContext *ctx) override;

    virtual ~DayState() {};

    DayState(const DayState & ) = delete;

    DayState(DayState &&) = delete;

    DayState& operator=(const DayState &) = delete;

    DayState& operator=(DayState &&) = delete;
protected:
    DayState() {}
};

#endif
