

#include <catch/catch.hpp>
#include <include/print.hpp>

#include <memory>
#include <iostream>

TEST_CASE("std::vector with 0 element", "[print_vector]")
{
    auto const v = std::vector<int>{};
    REQUIRE_NOTHROW( println(std::cout, v) );
}

TEST_CASE("std::vector with 1 element", "[print_vector]")
{
    auto const v = std::vector<int>{1};
    REQUIRE_NOTHROW( println(std::cout, v) );
}

TEST_CASE("std::vector with multiple element", "[print_vector]")
{
    auto const v = std::vector<int>{1, 2, 3, 4, 5};
    REQUIRE_NOTHROW( println(std::cout, v) );
}

TEST_CASE("std::vector of std::string element", "[print_vector]")
{
    auto const v = std::vector<std::string>{"this", "is", "just", "a", "string", "vector"};
    REQUIRE_NOTHROW( println(std::cout, v) );
}

TEST_CASE("std::pair", "[print_pair]")
{
    auto const p = std::make_pair(10, 20);
    REQUIRE_NOTHROW( println(std::cout, p) );
}

TEST_CASE("std::tuple with multiple elements", "[print_tuple]")
{
    auto const p = std::make_tuple(10, 20, 30);
    REQUIRE_NOTHROW( println(std::cout, p) );
}

TEST_CASE("std::tuple<std::vector<std::string>>>", "[print_tuple]")
{
    auto const p = std::make_tuple(std::vector<std::string>{"This", "string", "is" , "in", "vector", "which", "is", "inside", "tuple"});
    REQUIRE_NOTHROW( println(std::cout, p) );
}

#if __cplusplus >= 201402
TEST_CASE("std::unique_ptr<int>", "[unique_ptr]")
{
    auto const & ptr = std::make_unique<int>(40);
    REQUIRE_NOTHROW( println(std::cout, ptr) );
}

#endif
