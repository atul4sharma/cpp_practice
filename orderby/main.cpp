
#include <string>
#include <tuple>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>


struct person
{
    friend auto operator < (person const & lt, person const & rt)
        -> bool;

    friend auto operator << (std::ostream & out, person const & p)
        -> std::ostream &
    {
        std::cout << "name[" << p._name << "] age[" << p._age << "] rank[" << p._rank << "]";
        return out;
    }
    
    explicit person(std::string name
                   ,int         age
                   ,int         rank)
        :_name(std::move(name))
        ,_age(age)
        ,_rank(rank)
    {}

    private:
        std::string _name{};
        int         _age{0};
        int         _rank{0};
};

auto operator < (person const & lt, person const & rt)
    -> bool
{
    return std::tuple<int, std::string, int>{lt._rank, lt._name, lt._age}
           <
           std::tuple<int, std::string, int>{rt._rank, rt._name, rt._age};
}

int main()
{
    auto v = std::vector<person>{person{"atulsharma", 22, 1}
                                ,person{"balram"    , 10, 3}
                                ,person{"akash"     , 29, 9}
                                ,person{"ajay"      , 39, 5}
                                ,person{"zeeshan"   , 21, 4}
                                ,person{"nitul"     , 38, 5}
                                ,person{"abhinav"   , 20, 5}};
    std::sort(v.begin(), v.end());

    std::copy(v.begin(), v.end(), std::ostream_iterator<person>(std::cout, "\n"));
    return 0;
}
