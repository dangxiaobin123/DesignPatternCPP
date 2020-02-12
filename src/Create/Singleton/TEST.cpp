#define CATCH_CONFIG_MAIN
#include "Singleton.h"
#include <iostream>
#include <string>
#include <catch.hpp>
using namespace std;

class Apple : public Singleton<Apple>
{
    friend Singleton<Apple>;

public:
    void show()
    {
        cout << __FUNCTION__ << endl;
    }
    ~Apple()
    {
        cout << __FUNCTION__ << endl;
    }

protected:
    Apple() {}
};

class Orange : public Singleton<Orange>
{
    friend Singleton<Orange>;

public:
    ~Orange()
    {
        cout << __FUNCTION__ << endl;
    }
    void show()
    {
        cout << __FUNCTION__ << endl;
    }

protected:
    Orange()
    {

    }
};

TEST_CASE("Singleton")
{
    Apple::Get_Instance().show();
    cout << &Apple::Get_Instance() << endl;
    Apple::Get_Instance().show();
    cout << &Apple::Get_Instance() << endl;

    Orange::Get_Instance().show();
    Orange::Get_Instance().show();
    Orange::Get_Instance().show();
}
