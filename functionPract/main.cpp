#include <iostream>
#include <elision/bar.hpp>


static long x = 0;
void setVal(long const y)
{
    x = y;
}

template<typename Type, typename Function>
void fun(Function && func)
{
    func(1203);
}

template<typename Type, typename Function>
void fun(Function && func, Type val)
{
    func(38234);
    std::cout << "val " << val << "\n";
}

template<typename Functor>
void xyz(Functor && func)
{
    func();
}


int main()
{
    fun<long>(setVal);
    std::cout << x << "\n";
    fun(setVal, 12312);
    std::cout << "\n";
    elision::bar obj;
    xyz(elision::bar::doSomething); 
    return 0;
}
