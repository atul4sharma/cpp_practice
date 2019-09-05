
#include <iostream>
#include <tuple>
#include <utility>

#if __cplusplus < 201402
#include "integer_sequence.hpp"
#else
using std::integer_sequence;
using std::make_index_sequence;
#endif


template <typename T, typename Int, Int ... i>
auto print(T const & range, integer_sequence<Int, i...>)
    -> void
{
    (int[]){0, (std::cout << std::get<i>(range) << ", " , 0)...};
    std::cout << "\n";
}

int main()
{
    auto const t = std::make_tuple(1,2.3, "string");
    print(t, make_index_sequence<std::tuple_size<decltype(t)>::value>{});
    auto const p = std::make_pair(1, 4.5);
    print(p, make_index_sequence<std::tuple_size<decltype(p)>::value>{});

    return 0;
}
