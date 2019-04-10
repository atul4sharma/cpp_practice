#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>


template <typename Iterator
         ,typename Number
         ,typename Predicate>
auto find_if_nth(Iterator  first
                        ,Iterator  last
                        ,Number    nth
                        ,Predicate pred)
    -> std::pair<Iterator, Number>
    // returns current found position and the counts that have been exhausted
{
    if(not nth)
    {        
        return {last, nth};
    }
    
    while(first != last and nth)
    {
        first = std::find_if(first, last, pred);
        if(first != last)
        {
            --nth;
            if(not nth)
            {
                return {first, nth};
            }
            ++first;
        }        
    }
    
    return {first, nth};
}
          
int main()
{
    auto const numbers = std::vector<int>{1,2,3,4,5,6,7,8};
    auto const nth     = int{1};
    auto const is_even = [] (int x) { return x % 2 == 0;};
    //auto const is_greater_than_twenty = [] (int x) { return x > 20; };
    std::cout << "searching " << nth <<"th occurrence for is_even\n";
    auto const result = find_if_nth(numbers.begin(), numbers.end(), nth, is_even);
    //auto const result = find_if_nth(numbers.begin(), numbers.end(), fifth, is_greater_than_twenty);
    if(result.first != numbers.end() and not result.second )
    {
        std::cout << "Occurrence found => " << *(result.first) << "\n";        
    }
    else
    {
        std::cout << nth << "th occurrence not found. Found " << nth - result.second << " occurrences\n";
    }
    
    return 0;
}
