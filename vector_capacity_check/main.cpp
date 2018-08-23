
#include <vector>
#include <iostream>

int main()
{ 

    std::vector<int> v{1,2,3};

    v.reserve(100);

    std::cout << "v.size -> " << v.size() << " v.capacity -> " << v.capacity() << "\n";
    v.shrink_to_fit();
    std::cout << "v.size -> " << v.size() << " v.capacity -> " << v.capacity() << "\n";

    return 0;
}
