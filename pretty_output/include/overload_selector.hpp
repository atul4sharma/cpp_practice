
#pragma once

namespace meta
{
    template <int N>
    struct preference : preference<N+1> {};
    
    template <>
    struct preference<5> {};

    using _1st_preference = preference<1>;
    using _2nd_preference = preference<2>;
    using _3rd_preference = preference<3>;
    using _4th_preference = preference<4>;
    using _5th_preference = preference<5>;
    
    using overload_selector = _1st_preference;
}
