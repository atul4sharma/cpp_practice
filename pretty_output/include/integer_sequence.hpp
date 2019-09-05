
#pragma once

#include <cstddef>

namespace meta
{
    template<typename Integer, Integer ... Ints>
    struct integer_sequence
    {
        using type = integer_sequence<Integer, Ints...>;

        static constexpr std::size_t size() { return sizeof ... (Ints); }
    };

    template<typename Integer, std::size_t Begin, std::size_t End, Integer ... Xs>
    struct make_integer_range_impl : make_integer_range_impl<Integer, Begin, End - 1, Integer(End - 1), Xs...> {};

    template<typename Integer, std::size_t Begin, Integer ... Xs>
    struct make_integer_range_impl<Integer, Begin, Begin, Xs...> : integer_sequence<Integer, Xs...> {};

    template<typename Integer, Integer Begin, Integer End>
    using make_integer_range = typename make_integer_range_impl<Integer, Begin, End>::type;

    template<typename Integer, Integer N>
    using make_integer_sequence = make_integer_range<Integer, 0, N>;



    template<std::size_t N>
    using make_index_sequence = make_integer_range<std::size_t, 0, N>;

    template<std::size_t Begin, std::size_t End>
    using make_index_range = make_integer_range<std::size_t, Begin, End>;

    template<std::size_t ... Indices>
    using index_sequence = integer_sequence<std::size_t, Indices...>;

    template<typename ... Ts>
    using index_sequence_for = make_index_sequence<sizeof...(Ts)>;

}
