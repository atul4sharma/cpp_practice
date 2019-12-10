
#include <pretty_output/include/print.hpp>

#include <vector>
#include <iostream>

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

auto has_circular_dependency(std::vector<std::string>       & visiting
                            ,row                      const & item
                            ,std::vector<row>         const & universe)
{
    visiting.emplace_back(item.class_id);
    //println(std::cout << "Visiting -> ", visiting);
    for(auto const & dep : item.dependencies)
    {
        //println(std::cout << "Checking dependency -> ", dep);
        auto already_visited = std::find(visiting.begin(), visiting.end(), dep);
        if( already_visited !=  visiting.end() )
        {
            //println(std::cout << "Already visited ", *already_visited);
            return true;
        }
        auto iter = std::find_if(universe.begin(), universe.end(), [&dep](row const & x) { return x.class_id == dep;});
        if( iter != universe.end() )
        {
            //println(std::cout << "going down the tree ", *iter);
            auto has_dependency = has_circular_dependency(visiting, *iter, universe);
            if( has_dependency )
            {
                //println(std::cout << "has circular for ", *iter);
                return true;
            }
        }
    }
    visiting.pop_back();
    return false;
}

int main()
{
    auto const universe = std::vector<row>{ row{"A", std::vector<std::string>{"B", "C", "D"}}
                                           ,row{"C", std::vector<std::string>{"E"}}
                                           ,row{"E", std::vector<std::string>{"A"}}
                                           };

    println(std::cout, universe);

    auto visiting = std::vector<std::string>{};

    auto has = false;
    for( auto const & id : universe)
    {
        visiting.clear();
        has = has_circular_dependency(visiting, id, universe);
        if( has )
        {
            println(std::cout << "********** Has dep for -> ", id);
            println(std::cout << "********** Visited class_ids -> ", visiting);
        }
        else
            println(std::cout << "********** Does not have circular dependency -> ", id);
    }

    return 0;
}
