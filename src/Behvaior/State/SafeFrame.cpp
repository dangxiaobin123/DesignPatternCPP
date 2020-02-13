#include "SafeFrame.h"
#include "DayState.h"
#include <iostream>

SafeFrame::SafeFrame(): _state(&DayState::Get_Instance()) {}

void SafeFrame::action(ActionType actionType)
{
    switch (actionType) {
    case ActionType::ALARM:
        _state->alarm(this);
        break;
    case ActionType::CALL:
        _state->call(this);
        break;
    case ActionType::USE:
    default:
        _state->use(this);
        break;
    }
}

void SafeFrame::set_clock(int hour)
{
    std::cout << "now time is " << hour << std::endl;
    _state->clock(this, hour);
}

void SafeFrame::state_change(IState *state)
{
    std::cout << __FUNCTION__ << std::endl;
    _state = state;
}

void SafeFrame::call_security_center(const std::string &msg)
{
    std::cout << __FUNCTION__ << " " << msg << std::endl;
}

void SafeFrame::record_log(const std::string &msg)
{
    std::cout << __FUNCTION__ << " " << msg << std::endl;
}
