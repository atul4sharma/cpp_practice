#include <elision/bar.hpp>
#include <override_usage/foo.hpp>
#include <boost/type_index.hpp>

#if 1
void printSomething(override_usage::foo & obj)
{
    std::cout << "Called printSomething(<lvalue reference>) : " 
              << boost::typeindex::type_id_with_cvr<decltype(obj)>().pretty_name() << "\n";
}

void printSomething(override_usage::foo && obj)
{
    std::cout << "Called printSomething(<rvalue reference>) : "
              << boost::typeindex::type_id_with_cvr<decltype(obj)>().pretty_name() << "\n";
}
#else
template<typename T>
void printSomething(T && obj)
{
    std::cout << "Called printSomething(<universal reference>) : "
              << boost::typeindex::type_id_with_cvr<decltype(obj)>().pretty_name() << "\n";
}
#endif

int main()
{
    elision::DEBUG = false;

    elision::bar bar_object{};
    override_usage::foo foo_object{};

    bar_object.doSomething();
    foo_object.doSomething();

    foo_object.printFunction();
    std::move(foo_object).printFunction();

    printSomething(foo_object);
    printSomething(std::move(foo_object));

    return 0;
}
