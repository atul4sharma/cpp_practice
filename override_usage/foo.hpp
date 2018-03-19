#include <elision/bar.hpp>
#include <iostream>

namespace override_usage
{
    class foo : public elision::bar
    {
        public:
            // void doSomething() override 
            // would not compile as the signature of base class declares the function as const function
            //
            // void doSomething() 
            // would compile but may not produce the desired result
            void doSomething() const override
            {
                std::cout << "This function of foo do something\n";
            }

            // prints lvalue if this object is lvalue 
            void printFunction() &
            {
                std::cout << "lvalue\n";
            }

            // prints rvalue if this object is rvalue 
            void printFunction() &&
            {
                std::cout << "rvalue\n";
            }
    };
}
