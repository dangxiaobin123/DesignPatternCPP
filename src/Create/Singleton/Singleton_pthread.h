#ifndef CREATE_SINGLETON_PTHREAD_H
#define CREATE_SINGLETON_PTHREAD_H

//使用方法：
//通过以下语句：Singleton<类名>::instance()，获取指向某类实例的指针。
//

#include <stdlib.h>
#include <pthread.h>

template<typename T>
class SingletonP
{
public:
    inline static T &get_instance()
    {
        if (!_s_instance_ptr) {
            pthread_mutex_lock(&_mutex);
            if (!_s_instance_ptr) {
                T *ptmp = new T();
                _s_instance_ptr = ptmp;
                atexit(destroy_instance);
            }
            pthread_mutex_unlock(&_mutex);
        }
        return *_s_instance_ptr;
    }

    inline static void destroy_instance()
    {
        if (_s_instance_ptr != nullptr) {
            delete _s_instance_ptr;
        }
        _s_instance_ptr = nullptr;
    }
protected:
    SingletonP() {}
    SingletonP(const SingletonP &) = delete;
    SingletonP &operator=(const SingletonP &) = delete;
    virtual ~SingletonP() {}
private:
    static T *_s_instance_ptr;
    static pthread_mutex_t _mutex;
};

template<typename T> pthread_mutex_t SingletonP<T>::_mutex = PTHREAD_MUTEX_INITIALIZER;
template<typename T> T *SingletonP<T>::_s_instance_ptr = nullptr;

#endif