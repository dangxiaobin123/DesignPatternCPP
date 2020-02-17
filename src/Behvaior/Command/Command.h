#ifndef COMMAND_H
#define COMMAND_H

#include <functional>
#include <type_traits>

template <typename Ret = void>
class Command
{
private:
    std::function<Ret()> _f;

public:
    Ret execute()
    {
        return _f();
    }
    //接受可调用对象的函数包装器
    template < class F, class... Args, class = typename std::enable_if < !std::is_member_function_pointer<F>::value >::type >
    void wrap(F && f, Args && ... args)
    {
        _f = [&] {return f(args...);};
    }

    //接受常量成员函数的函数包装器
	template<class R, class C, class... DArgs, class P, class... Args>
	void wrap(R(C::*f)(DArgs...) const, P && p, Args && ... args)
	{
		_f = [&, f]{return (*p.*f)(args...); };
	}

    //接受非常量成员函数的函数包装器 
	template<class R, class C, class... DArgs, class P, class... Args>
	void wrap(R(C::*f)(DArgs...), P && p, Args && ... args)
	{
		_f = [&, f]{return (*p.*f)(args...); };
	}
};


#endif /* COMMAND_H */
