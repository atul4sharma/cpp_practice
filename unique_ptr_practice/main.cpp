
#include <memory>
#include <iostream>

#include <boost/type_index.hpp>

namespace {
    auto const int_deleter = [](int * item)
    {
        std::cout << "deleting item\n";
        delete item;
    };
}

auto return_pointer(int && item)
    -> std::unique_ptr<int>
{
    return std::unique_ptr<int>(new int{std::forward<int>(item)});
}

auto return_custom_deleter_pointer(int && item)
    -> std::unique_ptr<int, decltype(int_deleter)>
{
    return std::unique_ptr<int, decltype(int_deleter)>(new int{std::forward<int>(item)}
                                                      ,int_deleter);
}

int main()
{
    {
        auto ptr = return_custom_deleter_pointer(30);
        std::cout << boost::typeindex::type_id<decltype(ptr)>().pretty_name() << " => " << *ptr << "\n";
    }
    {
        auto ptr = return_pointer(10);
        std::cout << boost::typeindex::type_id<decltype(ptr)>().pretty_name() << " => " << *ptr << "\n";
    }
    return 0;
}
