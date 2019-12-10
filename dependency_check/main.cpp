
#include <pretty_output/include/print.hpp>

#include <deque>
#include <vector>
#include <iostream>
#include <unordered_set>

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
};

auto operator << (std::ostream       & out
                 ,row          const & item)
    -> std::ostream &
{
    print(out << "class_id -> ", item.class_id);
    print(out << "|dependencies -> ", item.dependencies);
    return out;
}

auto has_circular_dependency(std::unordered_set<std::string>       & visiting
                            ,std::deque<std::string>               & visited
                            ,row                             const & item
                            ,std::vector<row>                const & universe)
{
    // visiting.emplace_back(item.class_id);
    auto insertion = visiting.insert(item.class_id);
    if( ! insertion.second )
    {
        return true;
    }

    //println(std::cout << "Visiting -> ", visiting);
    for(auto const & dep : item.dependencies)
    {
        //println(std::cout << "Checking dependency -> ", dep);
        auto already_visited = visiting.find(dep);
        if( already_visited !=  visiting.end() )
        {
            //println(std::cout << "Already visited ", *already_visited);
            return true;
        }
        auto iter = std::find_if(universe.begin(), universe.end(), [&dep](row const & x) { return x.class_id == dep;});
        if( iter != universe.end() )
        {
            //println(std::cout << "going down the tree ", *iter);
            auto has_dependency = has_circular_dependency(visiting, visited, *iter, universe);
            if( has_dependency )
            {
                visited.push_front(dep);
                //println(std::cout, dep);
                return true;
            }
        }
    }
    // visiting.pop_back();
    visiting.erase(insertion.first);
    return false;
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

    auto visiting = std::unordered_set<std::string>{};
    auto bt_visited  = std::deque<std::string>{};

    auto has = false;
    for( auto const & id : universe)
    {
        has = has_circular_dependency(visiting, bt_visited, id, universe);
        if( has )
        {
            bt_visited.push_front(id.class_id);
            println(std::cout << "********** Has dep for -> ", id);
            println(std::cout << "********** Visited class_ids -> ", bt_visited);
        }
        else
            println(std::cout << "********** Does not have circular dependency -> ", id);
        bt_visited.clear();
    }

    return 0;
}
