#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "SharedPtrUtil.h"
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <Logger.h>

TEST_CASE("SmartPtr")
{
    SECTION("make_shared_array") {
        auto sp = SharedPtrUtil::make_shared_array<int>(10);
        for (int i = 0; i < 10; i++) {
            sp.get()[i] = (i + 1) * (i + 1);
        }
        for (int i = 0; i < 10; i++) {
            // LOG_INFO("make_shared_array", std::to_string(sp.get()[i]));
            // LOG_INFO << sp.get()[i];
            LOG_INFO("sp[%d] is %d", i, sp.get()[i]);
        }
    }

    SECTION("make_unique") {
        auto up = SharedPtrUtil::make_unique<int>(4);
        REQUIRE(*up == 4);
        auto upArr = SharedPtrUtil::make_unique<int[]>(5);
        upArr[3] = 10;
        REQUIRE(upArr[3] == 10);
    }
}
