#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <utility>
#include <string>
#include <type_traits>
#include <typeinfo>


#if 0
template<typename Type>
auto print(Type object)
    -> decltype(typename Type::value_type, void())
{
    std::cout << "for containers ";
}
#endif

template<typename Type>
auto print(Type object)
    -> decltype(std::cout << object, void())
{
    std::cout << object << ", ";
}

template<>
auto print<std::string>(std::string object)
    -> void
{
    std::cout << object;
}

#if 1
template<typename Type>
auto print(Type object)
    -> decltype(object.begin(), void())
{
    std::cout << "{ ";
    for(auto const & item : object)
    {
        print(item);
    }
    std::cout << "} , ";

}
#endif

template<typename Key, typename Value>
void print(std::pair<Key, Value> object)
{
    std::cout << "{ " << object.first << ", " << object.second << "} ";
}

template<typename Type>
void println(Type object)
{
    print(object);
    std::cout << "\n";
}

int main()
{
    println(1);  
    println(1.4);
    println('c');

    println("const char *"); 
//    println(std::string{"string"}); 

    std::vector<int> vec{1, 2, 3, 4, 5};
    println(vec);
    
    std::vector<std::vector<int>> two_d{vec, vec, vec, vec, vec};
    println(two_d);

    std::set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    println(s);
   /* 
    std::set <std::string> s;
    s.insert("hello");
    s.insert("yeah");
    s.insert("rugs");

    println(s);
    std::vector <std::set<std::string> > vs {s, s};
    println(vs);


    auto p = std::make_pair(5, "world");
    println(p);

    std::map<std::string, std::vector<int> > m;
    m.insert(std::make_pair("Abhinav", std::vector<int>{97, 76, 87}));
    m.insert(std::make_pair("Hitesh", std::vector<int>{98, 77, 88}));

    println(m);
    */
    return 0;
}
