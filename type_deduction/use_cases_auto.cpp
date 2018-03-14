

#include <iostream>

struct foo
{
    foo()
    {
        std::cout << "Object foo{tgt[" << this << "]} created via default constructor\n";
        std::cout << "Resource acquired\n";
    }
    
    foo(foo const & rhs)
    {
        std::cout << "Object foo{tgt[" << this << "] | src[" << &rhs << "]} created via copy constructor\n";
        std::cout << "Resource acquired\n";
    }
    
    foo & operator = (foo const & rhs)
    {
        std::cout << "Object foo{tgt[" << this << "] | src[" << &rhs << "]} created via copy assignment\n";
        std::cout << "Resource acquired\n";
        return *this;
    }
    
    ~foo()
    {
        std::cout << "Object foo [" << this << "] destroyed\n";
        std::cout << "Resource released\n";
    }
        
    foo(foo && rhs)
    {
        std::cout << "Object foo{tgt[" << this << "] | src[" << &rhs << "]} created via move constructor\n";
    }
    
    foo & operator = (foo && rhs)
    {
        std::cout << "Object foo{tgt[" << this << "] | src[" << &rhs << "]} created via move assignment\n";
        return *this;
    }
};

foo func()
{
    return foo{};
}

int main()
{
    std::cout << "Using auto &\n"; 
    auto x = func();

    std::cout << "\n\n\n";

#if 1 
    std::cout << "Using auto &&\n";
    auto && y = func();

    std::cout << "\n\n\n";
#endif

    std::cout << "Main completed\n";
}
