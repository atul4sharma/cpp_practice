
#pragma once

#include "weight_count_pair.hpp"

#include <vector>
#include <algorithm>

struct p_queue
{
    public:

        explicit p_queue(std::vector<int> const & w_list)
        {
            for(auto const & item : w_list)
            {
                this->push(item);
            }
        }

        void push(weight_count_pair const & val)
        {
            auto elem = std::find_if(_students_weight.begin()
                                    ,_students_weight.end()
                                    ,[&val](weight_count_pair const & a)
                                       {
                                           return a == val;
                                       }
                                    );
                                        
            if(elem != _students_weight.end())
            {
                (*elem).increment_count();
                std::make_heap(_students_weight.begin()
                              ,elem + 1);
            }
            else
            {
                _students_weight.emplace_back(val);
                std::push_heap(_students_weight.begin()
                              ,_students_weight.end());
            }
        }

        auto average_weight() const
            -> weight
        {
            return (*_students_weight.begin()).w_val();
        }

        friend auto operator<<(std::ostream & out, p_queue const & p)
            -> std::ostream &;

    private:
        std::vector<weight_count_pair> _students_weight;
};


auto operator<<(std::ostream & out, p_queue const & p)
    -> std::ostream &
{
    for(auto const & item : p._students_weight)
    {
        out << item << ", ";
    }   
    return out;
}
