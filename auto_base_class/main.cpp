#include <iostream>

class base
{
    public:
        virtual void print()
        {
            std::cout << "base print\n";
        }
};

class derived : public base
{
    public:
        void print() override
        {
            std::cout << "derived print\n";
        }
};        

int main()
{
    auto x = new base();
    x->print();
    auto y = new derived();
    y->print();
    return 0;
}
