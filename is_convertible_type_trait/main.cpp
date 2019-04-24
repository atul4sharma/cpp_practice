#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <type_traits>


template <typename TargetType, typename Intermediate, bool n>
struct test_is_same_or_convertible : std::false_type{};

template <typename TargetType, typename Intermediate>
struct test_is_same_or_convertible<TargetType, Intermediate, true> : std::true_type{};

template <typename TargetType, typename Intermediate
         ,bool n = std::is_same<TargetType, Intermediate>::value
                   or
                   std::is_convertible<Intermediate, TargetType>::value
         >
struct is_same_or_convertible : test_is_same_or_convertible<TargetType, Intermediate, n>{};


template <typename StringType
         ,typename Callable
         ,typename CallableReturnType = typename std::result_of<Callable()>::type
         ,typename _ = typename std::enable_if<is_same_or_convertible<StringType, CallableReturnType>::value >::type
         >
auto foo()
    -> void
{
    std::cout << "well done\n";
}


int main()
{
    auto const return_string = [](){return std::string{};};
    auto const return_int    = [](){return int{};};
    
    foo<float, decltype(return_int)>();

}
