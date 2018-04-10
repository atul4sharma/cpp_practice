#include <iostream>
#include <set>

int main()
{
    std::set<int> s;
    s.insert(1);

    s.insert(3);
    s.insert(4);

    s.insert(2);
    s.insert(6);
    for( auto const & item : s)
        std::cout << item << "\n";
    return 0;
}
