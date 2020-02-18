#define CATCH_CONFIG_MAIN
#include "NoSupport.h"
#include "LimitSupport.h"
#include "OddSupport.h"
#include "SpecialSupport.h"
#include <memory>
#include <catch.hpp>

TEST_CASE("ResponsibilityChain pattern")
{
    auto s1 = std::unique_ptr<Support>(new NoSupport("Alance"));
    auto s2 = std::unique_ptr<Support>(new LimitSupport("Bob", 30));
    auto s3 = std::unique_ptr<Support>(new OddSupport("Charlie"));
    auto s4 = std::unique_ptr<Support>(new SpecialSupport("David", 55));

    s1->set_next(s2.get())->set_next(s3.get())->set_next(s4.get());
    for(int i = 0; i<100; i++) {
        Trouble t(i);
        s1->support(&t);
    }
}

