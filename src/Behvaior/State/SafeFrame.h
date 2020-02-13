#ifndef STATE_SAFEFRAME_H
#define STATE_SAFEFRAME_H

#include "IContext.h"
#include "IState.h"

class SafeFrame: public IContext
{
public:
    SafeFrame();

    virtual void action(ActionType actionType) override;

    virtual void set_clock(int hour) override;

    virtual void state_change(IState* state) override;

    virtual void call_security_center(const std::string& msg) override;

    virtual void record_log(const std::string& msg) override;
private:
    IState* _state;
};

#endif