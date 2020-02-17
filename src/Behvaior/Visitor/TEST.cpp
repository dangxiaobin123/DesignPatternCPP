#define CATCH_CONFIG_MAIN
#include "Directory.h"
#include "File.h"
#include "ListVisitor.h"
#include <memory>
#include <catch.hpp>

template<class T>
struct EntityGuard
{
    bool is_valid() { return shared_entity != nullptr; }
    T* operator()() { return shared_entity.get(); }
    EntityGuard(std::weak_ptr<T> weak_entity) : shared_entity(weak_entity.lock()) {}
    std::shared_ptr<T> shared_entity;
};

TEST_CASE("Visitor pattern")
{
    auto root = new Directory("root");
    auto bin = new Directory("bin");
    auto tmp = new Directory("tmp");
    auto usr = new Directory("usr");

    root->add_entry(bin);
    root->add_entry(tmp);
    root->add_entry(usr);
    bin->add_entry(new File("vi", 3000));
    bin->add_entry(new File("latex", 2000));

    auto list1 = std::make_shared<ListVisitor>();
    root->accept(list1.get());
}

