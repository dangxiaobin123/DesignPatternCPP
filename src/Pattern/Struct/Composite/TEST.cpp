#define CATCH_CONFIG_MAIN
#include "Directory.h"
#include "File.h"
#include <string>
#include <catch.hpp>
using namespace std;

//多继承方式实现适配器
TEST_CASE("Composite Pattern")
{
    Directory *root = new Directory("root");
    Directory *bin = new Directory("bin");
    Directory *tmp = new Directory("tmp");
    Directory *usr = new Directory("usr");

    root->add_entry(bin);
    root->add_entry(tmp);
    root->add_entry(usr);
    bin->add_entry(new File("vi", 3000));
    bin->add_entry(new File("latex", 2000));
    // static_cast<Entry *>(root)->print_list();
    root->print_list1();

    Directory *yuki = new Directory("yuki");
    Directory *hanako = new Directory("hanako");
    Directory *tomura = new Directory("tomura");

    usr->add_entry(yuki);
    usr->add_entry(hanako);
    usr->add_entry(tomura);
    yuki->add_entry(new File("diary.html", 100));
    hanako->add_entry(new File("memo.tex", 1024));
    tomura->add_entry(new File("junk.mail", 30));
    // static_cast<Entry *>(root)->print_list();
    root->print_list1();
    // root->print_list();

    SECTION("1"){
        File *f = new File("123.txt", 1);
        f->add_entry(root);
        f->print_list1();
        delete f;
    }
    SECTION("2") {
        yuki->print_list("");
    }
    SECTION("3") {
        File *f = new File("123.txt", 1);
        Entry *e = new Directory("test");
        e->add_entry(f);
        e->print_list("");
        e->to_string();
        delete e;
    }
    delete root;
}
