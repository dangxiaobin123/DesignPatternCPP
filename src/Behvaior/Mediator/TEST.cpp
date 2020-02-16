#define CATCH_CONFIG_MAIN
#include "CColleague1.h"
#include "CColleague2.h"
#include "CMediator.h"
#include <memory>
#include <catch.hpp>

TEST_CASE("Mediator pattern")
{
    auto m = std::unique_ptr<IMediator>(new CMediator);
    auto c1 = std::unique_ptr<IColleague>(new CColleague1);
    auto c2 = std::unique_ptr<IColleague>(new CColleague2);
    m->register_colleague(1, c1.get());
    m->register_colleague(2, c2.get());

    c1->send_msg(2, "hello, I'm c1");
    c2->send_msg(1, "hello, I'm c2");

    auto c3 = std::unique_ptr<IColleague>(new CColleague1(3, m.get()));
    auto c4 = std::unique_ptr<IColleague>(new CColleague2(4, m.get()));
    c3->send_msg(2, "hello, I'm c3");
    c4->send_msg(1, "hello, I'm c4");
}

