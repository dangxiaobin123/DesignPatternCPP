#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "Range.h"
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

TEST_CASE("Range")
{
    SECTION("Range(begin, end)") {
        std::cout << "loop start" << std::endl;
        for (auto x : Range(5, 20)) {
            std::cout << x << std::endl;
        }
        std::cout << "loop end" << std::endl;
    }

    SECTION("Range(end)") {
        std::cout << "loop start" << std::endl;
        for (auto x : Range(20)) {
            std::cout << x << std::endl;
        }
        std::cout << "loop end" << std::endl;
    }

    SECTION("Range(start, end, step)") {
        std::cout << "loop start" << std::endl;
        for (auto x : Range(0, 20, 2)) {
            std::cout << x << std::endl;
        }
        std::cout << "loop end" << std::endl;
    }

    SECTION("Range(start, end, step)") {
        std::cout << "loop start" << std::endl;
        std::vector<int> test_vector(10);
        std::iota(test_vector.begin(), test_vector.end(), 0);
        for (auto x : test_vector) {
            std::cout << x << std::endl;
        }
        std::cout << "loop end" << std::endl;
    }
}
