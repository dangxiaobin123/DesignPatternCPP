#ifndef STATE_ICONTEXT_H
#define STATE_ICONTEXT_H
#include <string>
class IState;
class IContext
{
public:
    enum class ActionType {
        USE,
        ALARM,
        CALL
    };

    virtual ~IContext() {};
#pragma region interface

    virtual void action(ActionType actionType) = 0;

    virtual void set_clock(int hour) = 0;

    virtual void state_change(IState* state) = 0;

    virtual void call_security_center(const std::string& msg) = 0;

    virtual void record_log(const std::string& msg) = 0;

#pragma endregion
};

#endif