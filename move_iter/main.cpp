#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include <boost/type_index.hpp>

#if 1
auto print_vector(std::vector<int> const & v)
    -> std::string
{
    std::stringstream s;
    s << "{ ";
    for(auto const & item : v)
        s << item << ", ";
    s << "}\n";
    
    return s.str();
}
#endif

int main()
{
    std::vector<int> vector_1{1,2,3,4,5,6,7,8,9,10};
    std::vector<int> vector_2{};
    
    #if 1
        std::cout << "using non-movable iterators\n";
        auto const start = vector_1.begin();
        auto const end   = vector_1.end();
    #else
        std::cout << "using movable iterators\n";
        auto const start = std::make_move_iterator(vector_1.begin());
        auto const end   = std::make_move_iterator(vector_1.end()  );
    #endif
    
    std::cout << "before :: vector_1" << print_vector(vector_1);
    std::cout << "before :: vector_2" << print_vector(vector_2);

    std::cout << "types -> " << boost::typeindex::type_id<decltype(start)>().pretty_name() << "\n";
    std::cout << "typeof stored value " << boost::typeindex::type_id<decltype(*start)>().pretty_name() << "\n";

    vector_2.insert(vector_2.end(), start, end);
    
    std::cout << "after :: vector_1" << print_vector(vector_1);
    std::cout << "after :: vector_2" << print_vector(vector_2);
        
    return 0;
}

