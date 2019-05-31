#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <numeric>

struct foo
{
    explicit foo(int roll, int age)
        :_roll(roll)
        ,_age(age)
    {}

    
    int _roll;
    int _age;
};

auto operator == (foo const & lhs
                 ,foo const & rhs)
	-> bool
{
    return lhs._age == rhs._age;
}

auto operator < (foo const & lhs
                ,foo const & rhs)
    -> bool
{
    return lhs._age < rhs._age;
}

auto operator << (std::ostream       & out
                 ,foo          const & data)
    -> std::ostream &
{
    out << "Age:[" << data._age << "]\tRoll No:[" << data._roll << "]";
    return out;
}

template <typename ForwardIterator, typename OutputIterator>
auto unique_copy_duplicates(ForwardIterator first
                           ,ForwardIterator last
                           ,OutputIterator  duplicates)
    -> ForwardIterator
{
    auto unique = first;
    auto next   = std::next(first);
    while( first != last )
    {
        *unique = std::move(*first);
        // Traverse duplicates
        while( next != last and *unique == *next )
        {
            //std::cout << "bad_record -> " << *next << "\n";
            *duplicates = *next;
            std::advance(next, 1);
            ++duplicates;
        }
        first = next;
        std::advance(next, 1);
        std::advance(unique, 1);
    }
    return unique;
}

int main()
{
    auto v = std::vector<foo>{foo{1,20}
                             ,foo{2,20}
                             ,foo{3,21}
                             ,foo{4,25}
                             ,foo{5,25}
                             ,foo{6,26}
                             };
    auto duplicates = std::vector<foo>{};
    std::cout << "Original:\n";
    std::copy(v.begin(), v.end(), std::ostream_iterator<foo>(std::cout, "\n"));

    std::stable_sort(v.begin(), v.end());
    v.erase(unique_copy_duplicates(v.begin(), v.end(), std::back_inserter(duplicates))
           ,v.end());
           
    std::cout << "\nUnique:\n";
    std::copy(v.begin(), v.end(), std::ostream_iterator<foo>(std::cout, "\n"));
    std::cout << "\nDuplicates:\n";
    std::copy(duplicates.begin(), duplicates.end(), std::ostream_iterator<foo>(std::cout, "\n"));
    
}

