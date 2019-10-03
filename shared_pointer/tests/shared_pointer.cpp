

#include <include/shared_pointer.hpp>

#include <pretty_output/include/print.hpp>

#include <catch/catch.hpp>

#include <memory>
#include <iostream>

TEST_CASE("constructing via raw pointer", "[construction]")
{
    utils::shared_pointer<int> raw_pointer_object{new int{10}};
    CHECK_NOTHROW( println(std::cout << "raw_pointer_object:\t", raw_pointer_object) );
    CHECK( raw_pointer_object.ref_count() == 1 );

    {
        utils::shared_pointer<int> copy_constructed{raw_pointer_object};
        CHECK_NOTHROW( println(std::cout << "copy_constructed:\t", copy_constructed) );
        CHECK( copy_constructed.ref_count() == 2 );
        CHECK( raw_pointer_object.ref_count() == 2 );
    }
    CHECK( raw_pointer_object.ref_count() == 1 );

}
