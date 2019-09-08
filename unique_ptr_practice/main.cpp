
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
    std::cout << "\nTrying unique_ptr copy\n";
    {
        auto ptr = return_custom_deleter_pointer(50);
        //Ways to transfer ownership
        //
        auto ptr_copy{std::move(ptr)};
        //
        //auto ptr_copy = decltype(ptr){nullptr, int_deleter};
        //ptr_copy.reset(ptr.release());

        //Using operator* on ptr causes segfault, since the ownership has been
        //transferred to ptr_copy
        //std::cout << boost::typeindex::type_id<decltype(ptr)>().pretty_name() << " ptr      => " << *ptr << "\n";
        std::cout << boost::typeindex::type_id<decltype(ptr)>().pretty_name() << " ptr_copy => " << *ptr_copy << "\n";
    }

    std::cout << "\nTrying capturing via shared_ptr\n";
    {
        std::shared_ptr<int> ptr = return_pointer(100);
        std::cout << boost::typeindex::type_id<decltype(ptr)>().pretty_name() << " ptr => " << *ptr << "\n";
    }

    return 0;
}
