#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

template <typename Iterator
         ,typename Number
         ,typename Predicate>
auto find_if_nth(Iterator  first
                ,Number    count
                ,Number    nth
                ,Predicate pred)
    -> std::pair<Number, Iterator>
{
    if(not nth)
    {
        return {0, first};
    }
    
    while(count && nth)
    {
        if(pred(*first))
        {
            --nth;
            if(not nth)
            {
                return {count, first};
            }
        }
        ++first;
        --count;
        
    }
    return {count, first};        
}

int main()
{
    auto const numbers     = std::vector<int>{1,2,3,4,5,6,7,8};
    auto const range_count = int{8};
    auto const nth         = int{5};
    auto const is_even     = [] (int x) { return x % 2 == 0;};
    std::cout << "searching " << nth <<"th occurrence for is_even\n";
    //auto const is_greater_than_twenty = [] (int x) { return x > 20; };
    auto const result  = find_if_nth(numbers.begin(), range_count, nth, is_even);
    if(result.first)
    {
        std::cout << "Occurrence found => " << *(result.second) << "\n";
    }
    else
    {
        std::cout << "Occurrence not found\n";
    }
    
    return 0;
}
