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

namespace 
{
    template <typename ForwardIterator>
    auto unique(ForwardIterator first
               ,ForwardIterator last
               ,int)
        -> ForwardIterator
    {
        if (first == last)
            return last;
     
        auto result = first;
        while (first != last) 
        {
            *result = *first;        
            auto next = first + 1;
            
            while( next != last and *first == *next )
            {
                //std::cout << "bad_record -> " << *next << "\n";
                ++first; ++next;
            }
            ++result;
            first = next;
        }
        return result;
    }
}

int main()
{
    auto v = std::vector<foo>{foo{1,20}
                             ,foo{2,20}
                             ,foo{3,21}
                             ,foo{4,25}
                             ,foo{5,25}
                             };
    std::stable_sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end(), int{})
           ,v.end());
           
    std::copy(v.begin(), v.end(), std::ostream_iterator<foo>(std::cout, "\n"));
    
}

