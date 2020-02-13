#define CATCH_CONFIG_MAIN
#include "SafeFrame.h"
#include <catch.hpp>

TEST_CASE("state pattern")
{
    IContext *ctx = new SafeFrame;
    for (int i = 0; i < 24; ++i)
    {
        ctx->set_clock(i);
        ctx->action(IContext::ActionType::USE);
        ctx->action(IContext::ActionType::CALL);
        ctx->action(IContext::ActionType::ALARM);
    }
    delete ctx;
}

