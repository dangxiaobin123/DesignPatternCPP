#include "DayState.h"
#include "NightState.h"

void DayState::clock(IContext *ctx, int hour)
{
    if(hour<9||hour>=17) {
        ctx->state_change(&NightState::Get_Instance());
    }
}

void DayState::use(IContext *ctx)
{
    ctx->record_log("Day use");
}

void DayState::alarm(IContext *ctx)
{
    ctx->call_security_center("Day alarm");
}

void DayState::call(IContext *ctx)
{
    ctx->call_security_center("Day call");
}