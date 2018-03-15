#include <elision/bar.hpp>
#include <boost/type_index.hpp>
#include <iostream>

int main()
{
    elision::DEBUG = false;    

    std::cout << "elision::bar bar_object{};\n";
    elision::bar bar_object{};
    std::cout << "Typeof bar_object : " << boost::typeindex::type_id_with_cvr< decltype(bar_object) >().pretty_name() << "\n\n";

    std::cout << "auto obj{bar_object};\n";
    auto obj{bar_object};
    std::cout << "Typeof obj : "        << boost::typeindex::type_id_with_cvr< decltype( obj ) >().pretty_name() << "\n\n";

    std::cout << "auto & obj2{bar_object};\n";
    auto & obj2{bar_object};
    std::cout << "Typeof obj2 : "       << boost::typeindex::type_id_with_cvr< decltype( obj2 ) >().pretty_name() << "\n\n";

    std::cout << "auto && obj3{std::move(bar_object)};\n";
    auto && obj3{std::move(bar_object)};
    std::cout << "Typeof obj3 : "       << boost::typeindex::type_id_with_cvr< decltype( obj3 ) >().pretty_name() << "\n\n";

    std::cout << "auto obj4{std::move(bar_object)};\n";
    auto obj4{std::move(bar_object)};
    std::cout << "Typeof obj4 : "       << boost::typeindex::type_id_with_cvr< decltype( obj4 ) >().pretty_name() << "\n\n";

    // This would not work as the initializer_list constructor has overpowered the other (int, double) constructor
    // auto obj5 = elision::bar{1, 2.3};
    std::cout << "auto obj5 = elision::bar{1, 2};\n";
    auto obj5 = elision::bar{1, 2};
    std::cout << "Typeof obj5 : "       << boost::typeindex::type_id_with_cvr< decltype( obj5 ) >().pretty_name() << "\n\n";
    
    std::cout << "auto obj6 = {\"a\", \"b\", \"c\"};\n";
    auto obj6 = {"a", "b", "c"};
    std::cout << "Typeof obj6 : "       << boost::typeindex::type_id_with_cvr< decltype( obj6 ) >().pretty_name() << "\n\n";

    std::cout << "auto obj7{\"this\"};\n";
    auto obj7{"this"};
    std::cout << "Typeof obj7 : "       << boost::typeindex::type_id_with_cvr< decltype( obj7 ) >().pretty_name() << "\n\n";

    std::cout << "auto obj8 = {1};\n";
    auto obj8 = {1};
    std::cout << "Typeof obj8 : "       << boost::typeindex::type_id_with_cvr< decltype( obj8 ) >().pretty_name() << "\n\n";
    
    std::cout << "auto obj9{elision::bar{}};\n";
    auto obj9{elision::bar{}};
    std::cout << "Typeof obj9 : "       << boost::typeindex::type_id_with_cvr< decltype( obj9 ) >().pretty_name() << "\n\n";

    return 0;

}
