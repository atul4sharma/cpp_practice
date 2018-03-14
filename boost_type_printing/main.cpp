#include <iostream>

#include <boost/type_index.hpp>

int main()
{
    int a         = 10;
    int const x   = a;
    int const & y = a;

    std::cout << "a: " << boost::typeindex::type_id_with_cvr<decltype(a)>().pretty_name() << "\n";
    std::cout << "x: " << boost::typeindex::type_id_with_cvr<decltype(x)>().pretty_name() << "\n";
    std::cout << "y: " << boost::typeindex::type_id_with_cvr<decltype(y)>().pretty_name() << "\n";
}
