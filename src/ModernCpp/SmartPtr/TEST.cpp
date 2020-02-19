#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "SharedPtrUtil.h"
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

TEST_CASE("Range")
{
    SECTION("make_shared_array") {
        auto sp = SharedPtrUtil::make_shared_array<int>(10);
        for (int i = 0; i < 10; i++) {
            sp.get()[i] = (i + 1) * (i + 1);
        }
        for (int i = 0; i < 10; i++) {
            std::cout << sp.get()[i] << std::endl;
        }
    }

    SECTION("make_unique") {
        auto up = SharedPtrUtil::make_unique<int>(4);
        REQUIRE(*up==4);
        auto upArr = SharedPtrUtil::make_unique<int[]>(5);
        upArr[3] = 10;
        REQUIRE(upArr[3]==10);
    }
}
