#include <iostream>

void f(long x)
{
    std::cout << "int \n";
}

void f(bool x)
{
    std::cout << "bool\n";
}

void f(void*)
{
    std::cout << "void*\n";
}


int main()
{
    f(0L);
    f(true);
   // f(NULL);

}
