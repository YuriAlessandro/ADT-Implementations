// TUDO COLADO

/*!
 *  @mainpage Vector
 *  @author Elton de Souza Vieira
 *  @date May, 2016
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *  @version 1.0
 *
 *  @file drive_vector.cpp
 *  @brief Driver File
 *
 *  File with the Vector tests
 */

#include <iostream>
#include <cassert>
#include "Vector.h"

int main(int argc, char const *argv[]) {
    
    Vector<std::string> v1;
    v1.push_back("a");
    v1.push_back("ab");
    v1.push_back("abc");
    v1.push_back("abcd");
    v1.push_back("abcde");
    
    for ( auto it = v1.cbegin(); it != v1.cend(); it++ )
        std::cout << *it << " ";
    
    std::cout << ">>> Exiting with sucess...\n";
    
    /*
    int i;
    Vector<int> v1;

    // Unity Test #1: capacity()
    assert(v1.capacity() == 10);

    // Unity Test #2: size()
    assert(v1.size() == 0);

    // Pop Back 10 times (testing the dynamic array allocation)
    for (i = 0; i < 10; i++) 
        v1.push_back(i);

    // Unity test #3: data()
    int *ptr = v1.data();
    for (i = 0; i < 10; i++)
        assert(*(ptr+i) == i);

    // Unity test #4: const_iterator (operators ++ and *), cbegin(), cend()
    i = 0;
    for (auto it = v1.cbegin(); it != v1.cend(); it++, i++)
        assert(*it == i);

    assert( v1.cbegin() != v1.cend() );

    assert( i == 10 );

    // Unity test #4: back()
    assert(v1.back() == 9);

    // Unity test #5: front()
    assert(v1.front() == 0);

    // Unity test #6: size() after inserctions
    assert(v1.size() == 10);

    v1.pop_back();

    // Unity test #7: size() after remotion
    assert(v1.size() == 9);

    v1.assign(10);

    // Unity test #8: assign(), at() and the [] operator
    for (i = 0; i < 9; i++) {
        assert(v1.at(i) == 10);
        assert(v1[i] == 10);
    }

    v1.superDebuggator();

    // Clear Vector content
    v1.clear();

    // Unity test #9: size() after clear
    assert(v1.size() == 0);

    // Exit message
    std::cout << ">>> Exiting with sucess...\n";
    */
    return EXIT_SUCCESS;
}