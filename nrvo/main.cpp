#include <iostream>
#include <vector>

class base{
    public:
        base()
        {
            std::cout << "base : " << this << " created\n";
        }
        
    public:
        int x = 30;
};

auto func()
    -> base
{
    auto obj = base{};
    std::cout << "func : " << &obj << "\n";
    return obj;
}

int main(int argc, char *argv[])
{
    auto obj = func();
    std::cout << "main : " << &obj << "\n";
    
}

