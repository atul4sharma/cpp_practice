#include <iostream>
#include <typeinfo>
#include <typestring.hpp>
#include <type_traits>

template<typename T>
auto ded_type()
    -> std::string
{
    std::string result;
//    if( std::is_lvalue_reference<T>::value )
//    if( std::is_lvalue_reference< decltype(std::forward<T>(x)) >::value )
    if( std::is_lvalue_reference<T>::value )
        result += "lvalue reference , ";
//    else if( std::is_rvalue_reference<T>::value )
//    else if( std::is_rvalue_reference< decltype(std::forward<T>(x)) >::value )
    else if( std::is_rvalue_reference<T>::value )
        result += "rvalue reference , ";
    else
        result += "neither lvalue reference nor rvalue reference , ";

// we need to remove_reference, to check the constantness of the object the T is referring to 
// and not the reference or pointer itself is constant
//    if( std::is_const< decltype(std::forward<T>(x)) >::value )
    if( std::is_const< typename std::remove_reference<T>::type >::value )
        result += "const .";
    else
        result += "not const .";
    return result;
}

int main()
{
    int x = 20;
    int const y = x;
    int const & z = 25;
    int const * const a = &y;

    std::cout << "x : " << type_name<decltype(x)>() << "\n";
    std::cout << "y : " << type_name<decltype(y)>() << "\n";
    std::cout << "z : " << type_name<decltype(z)>() << "\n";
    std::cout << "20: " << type_name<decltype(20)>() << "\n";
    std::cout << "std::move(30): " << type_name<decltype(std::move(30))>() << "\n";

    std::cout << "x : "           << ded_type<decltype(x)>() << "\n";
    std::cout << "y : "           << ded_type<decltype(y)>() << "\n";
    std::cout << "z : "           << ded_type<decltype(z)>() << "\n";
    std::cout << "20: "           << ded_type<decltype(20)>()<< "\n";
    //std::cout << "std::move(30):" << ded_type(std::move(30)) << "\n";

    std::cout << "a : "           << ded_type<decltype(a)>() << "\n";
    return 0;
}
