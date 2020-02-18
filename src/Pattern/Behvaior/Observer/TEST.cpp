#define CATCH_CONFIG_MAIN
#include "DigitalObserver.h"
#include "GraphObserver.h"
#include "RandomNumGen.h"
#include <memory>
#include <catch.hpp>
#include <nanolog.hpp>
using nanolog::LogLevel;
TEST_CASE("Observer pattern")
{
    auto gen = std::unique_ptr<RandomNumGen>(new RandomNumGen);
    auto ob1 = std::unique_ptr<DigitalObserver>(new DigitalObserver);
    auto ob2 = std::unique_ptr<GraphObserver>(new GraphObserver);

    gen->add_observer(ob1.get());
    gen->add_observer(ob2.get());
    gen->execute();
    gen->delete_observer(ob1.get());
}

