#include <iostream>
#include <memory>
#include "Vector.h"

int main(int argc, char* argv[])
{

    Vector<int> integers;

    integers.push_back(3);
    integers.push_back(4);
    integers.push_back(5);
    integers.push_back(6);
    integers.pop_back();

    Vector<int>::iterator it1 = integers.begin();
    Vector<int>::const_iterator cit1 = integers.cbegin();

    if ( it1 == cit1 ) std::cout << "Noice\n";

    *it1 = 123123;
    std::cout << *it1 << "\n";

    ++it1;
    if ( it1 != cit1 ) std::cout << "Very noice\n";

    std::cout << "[ ";
    for ( auto it = integers.begin(); it != integers.end(); ++it )
        std::cout << *it << " ";
    std::cout << "]" << "\n";

    integers.reserve(20);
    integers.assign(7);

    std::cout << "[ ";
    for ( auto it = integers.begin(); it != integers.end(); ++it )
        std::cout << *it << " ";
    std::cout << "]" << "\n";

    integers.clear();
    if ( integers.empty() )
        std::cout << "It's empty.\n";

    return 0;
}
