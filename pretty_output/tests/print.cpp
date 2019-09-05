

#include <catch/catch.hpp>
#include <include/print.hpp>

#include <iostream>

TEST_CASE("std::vector with 0 element", "[print_vector]")
{
    auto const v = std::vector<int>{};
    println(std::cout, v);
    REQUIRE(true);
}

TEST_CASE("std::vector with 1 element", "[print_vector]")
{
    auto const v = std::vector<int>{1};
    println(std::cout, v);
    REQUIRE(true);
}

TEST_CASE("std::vector with multiple element", "[print_vector]")
{
    auto const v = std::vector<int>{1, 2, 3, 4, 5};
    println(std::cout, v);
    REQUIRE(true);
}

TEST_CASE("std::vector of std::string element", "[print_vector]")
{
    auto const v = std::vector<std::string>{"this", "is", "just", "a", "string"};
    println(std::cout, v);
    REQUIRE(true);
}

TEST_CASE("std::pair", "[print_pair]")
{
    auto const p = std::make_pair(10, 20);
    println(std::cout, p);
    REQUIRE(true);
}

TEST_CASE("std::tuple with multiple elements", "[print_tuple]")
{
    auto const p = std::make_tuple(10, 20, 30);
    println(std::cout, p);
    REQUIRE(true);
}
