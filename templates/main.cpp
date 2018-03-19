#include <iostream>
#include <boost/type_index.hpp>
/*
template<typename T, typename U, typename V>
void func(T t, U u, V v)
{
    std::cout << "T : " << boost::typeindex::type_id_with_cvr<T>().pretty_name() << "\n";
    std::cout << "U : " << boost::typeindex::type_id_with_cvr<U>().pretty_name() << "\n";
    std::cout << "V : " << boost::typeindex::type_id_with_cvr<V>().pretty_name() << "\n";
}

template <> 
void func(char , int , double)
{
    std::cout << "This is overloaded function \n"; 
}
*/

template<typename T>
void func(T x)
{
    std::cout << "function 1 \n";
}

template<typename T, typename U>
void func(T t, U u)
{
    std::cout << "function 2 \n";
}

template<>
void func(int, double)
{
    std::cout << "function 3\n";
}

int main()
{
    func(1);
    func(1,213.33);
    return 0;
}
