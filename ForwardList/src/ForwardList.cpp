/*!
 *  @mainpage Vector
 *  @author Gustavo Araújo e Yuri Alessandro Martins
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *  @version 1.0
 *
 *  @file ForwardList.cpp
 *  @brief Driver File
 *
 *  File with the Forward List tests
 */

#include <iostream>
#include <cassert>
#include "ForwardList.h"


int main(int argc, char* argv[])
{
    ForwardList<int> list1;
    
    //push_front method test:
    std::cout << "Current size: " << list1.size() << std::endl;
    
    list1.push_front( 3 );
    assert( list1.front() == 3 );
    
    std::cout << "Current size: " << list1.size() << std::endl;

    list1.push_front( 2 );
    assert( list1.front() == 2 );

    std::cout << "Current size: " << list1.size() << std::endl;

    list1.push_front( 1 );
    assert( list1.front() == 1 );

    std::cout << "Current size: " << list1.size() << std::endl;

    list1.push_front( 0 );
    assert( list1.front() == 0 );
    
    //size method test_1:
    std::cout << "Current size: " << list1.size() << std::endl;
    
    //push_back method test:
    list1.push_back( 4 );
    assert( list1.back() == 4 );
    list1.push_back( 5 );
    assert( list1.back() == 5 );
    list1.push_back( 6 );
    assert( list1.back() == 6 );
    list1.push_back( 7 );
    assert( list1.back() == 7 );
    
    //size method test_1:
    std::cout << "Current size: " << list1.size() << std::endl;

    //pop_front method test;
    list1.pop_front();
    assert( list1.front() == 1 );

    //pop_back method test;
    list1.pop_back();
    assert( list1.back() == 6 );
    
    //assign method test
    list1.assign( 10 );
    assert( list1.back() == 10 );
    assert( list1.front() == 10 );
    
    //clear method test
    list1.clear();
    assert( list1.empty() );


    return 0;
}
