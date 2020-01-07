
#include <pretty_output/include/print.hpp>

#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

#include <algorithm>

struct row
{
    std::string              class_id;
    std::vector<std::string> dependencies;

    row() = default;

    row(std::string              class_id
       ,std::vector<std::string> dependencies)
        :class_id    {std::move(class_id)}
        ,dependencies{std::move(dependencies)}
    {}

    friend auto operator << (std::ostream       & out
                            ,row          const & item)
        -> std::ostream &;

    friend auto operator <  (row const & lt
                            ,row const & rt)
        -> bool;
};

auto operator << (std::ostream       & out
                 ,row          const & item)
    -> std::ostream &
{
    print(out << "class_id -> ", item.class_id);
    print(out << "|dependencies -> ", item.dependencies);
    return out;
}

auto operator < (row const & lt
                ,row const & rt)
    -> bool
{
    return lt.class_id < rt.class_id;
}

auto has_circular_dependency(std::unordered_set<std::string>                                 & visiting
                            ,std::vector<std::string>                                        & visited
                            ,std::pair<std::string, std::vector<std::string>>          const & item
                            ,std::unordered_map<std::string, std::vector<std::string>> const & universe)
{
    auto insertion = visiting.insert(item.first);
    if( ! insertion.second )
    {
        return true;
    }

    for(auto const & dep : item.second)
    {
        auto iter = universe.find(dep);
        if( iter != universe.end() )
        {
            auto has_dependency = has_circular_dependency(visiting, visited, *iter, universe);
            if( has_dependency )
            {
                visited.emplace_back(dep);
                return true;
            }
        }
    }

    visiting.erase(insertion.first);
    return false;
}

auto assert_no_circular_dependency(std::vector<row> const & rules)
    -> void
{
    auto const universe = [&rules] ()
    {
        auto universe_ = std::unordered_map<std::string, std::vector<std::string>>{};
        std::transform(rules.begin()
                      ,rules.end()
                      ,std::inserter(universe_, universe_.end())
                      ,[](auto const & item)
                      {
                           return std::make_pair(item.class_id, item.dependencies);
                      });
        return universe_;
    }();

    auto visiting   = std::unordered_set<std::string>{};
    auto bt_visited = std::vector<std::string>{};

    for( auto const & id : universe)
    {
        if( has_circular_dependency(visiting, bt_visited, id, universe) )
        {
            bt_visited.emplace_back(id.first);
            std::reverse(bt_visited.begin(), bt_visited.end());

            println(std::cout << "********** Has dep for -> ", id);
            println(std::cout << "********** Visited class_ids -> ", bt_visited);
            //throw std::runtime_error(std::string{"has cicular dependency."});
        }
        else
            println(std::cout << "********** Does not have circular dependency -> ", id);
        bt_visited.clear();
    }
}


int main()
{
    auto const universe = std::vector<row>{ row{"A", std::vector<std::string>{"B", "C", "D"}}
                                           ,row{"C", std::vector<std::string>{"E"}}
                                           ,row{"E", std::vector<std::string>{"A"}}
                                           ,row{"B", std::vector<std::string>{"G"}}
                                           ,row{"H", std::vector<std::string>{"I"}}
                                           ,row{"I", std::vector<std::string>{"H"}}
                                           };

    println(std::cout, universe);

    assert_no_circular_dependency(universe);

    return 0;
}
