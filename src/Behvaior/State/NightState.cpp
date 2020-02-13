#include "NightState.h"
#include "DayState.h"

void NightState::clock(IContext *ctx, int hour)
{
    if (9 <= hour && hour < 17) {
        ctx->state_change(&DayState::Get_Instance());
    }
}

void NightState::use(IContext *ctx)
{
    ctx->record_log("Night use");
}

void NightState::alarm(IContext *ctx)
{
    ctx->call_security_center("Night alarm");
}

void NightState::call(IContext *ctx)
{
    ctx->call_security_center("Night call");
}
