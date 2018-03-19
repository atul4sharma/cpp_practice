#include <iostream>
#include <vector>
#include <boost/type_index.hpp>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6};

    auto it = std::find(std::begin(v), std::end(v), 2);

    std::cout << "Type of it is : " 
              << boost::typeindex::type_id_with_cvr<decltype(it)>().pretty_name() << "\n";

// Works with c++14 only
#if 0
    auto cit = std::find(cbegin(v), cend(v), 2);

    std::cout << "Type of cit is : " 
              << boost::typeindex::type_id_with_cvr<decltype(cit)>().pretty_name() << "\n";
#endif
    using cIter = std::vector<int>::const_iterator;

    auto casted_it = std::find( static_cast<cIter>(v.begin()), static_cast<cIter>(v.end()), 2);

    std::cout << "Type of casted_it is : " 
              << boost::typeindex::type_id_with_cvr<decltype(casted_it)>().pretty_name() << "\n";
    return 0;
}
