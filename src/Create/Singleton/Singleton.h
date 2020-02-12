#ifndef CREATE_SINGLETON_H
#define CREATE_SINGLETON_H

template<class T>
class Singleton
{
public:
    static T &Get_Instance()
    {
        static T ins;
        return ins;
    }

    Singleton(const Singleton &) = delete;
    Singleton& operator=(const Singleton &) = delete;
    virtual ~Singleton() {}
protected:
    Singleton() {}
};

#endif