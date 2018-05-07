#include <iostream>
#include <boost/type_index.hpp>

// if calling recursively, don't forget terminating condition
void variadics()
{
	std::cout << "\n";
}

template<typename HEAD, typename... TAIL>
void variadics(HEAD head, TAIL... tail)
{
    std::cout << head << ", ";
    variadics(tail...);
}


int main()
{
    variadics(1,2,"string", 4.543);
    return 0;
}

