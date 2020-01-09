

#include <include/dictionary_operations.hpp>

#include <pretty_output/include/print.hpp>

#include <catch/catch.hpp>

#include <map>
#include <iostream>


TEST_CASE("Getting keys in std::map", "[keys]")
{
    auto const m = std::map<int, std::string>{
                                               {1, "A"}
                                              ,{2, "B"}
                                              ,{3, "C"}
                                             };
    CHECK_NOTHROW( println(std::cout << "Map : " , m) );
    CHECK_NOTHROW( println(std::cout << "Keys : ", keys(m)) );
}

TEST_CASE("Getting values in std::map", "[values]")
{
    auto const m = std::map<int, std::string>{
                                               {1, "A"}
                                              ,{2, "B"}
                                              ,{3, "C"}
                                             };
    CHECK_NOTHROW( println(std::cout << "Map : " , m) );
    CHECK_NOTHROW( println(std::cout << "Values : ", values(m)) );
}

TEST_CASE("Getting keys in std::map empty", "[keys]")
{
    auto const m = std::map<int, std::string>{};
    CHECK_NOTHROW( println(std::cout << "Map : " , m) );
    CHECK_NOTHROW( println(std::cout << "Values : ", keys(m)) );
}
