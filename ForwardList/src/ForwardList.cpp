/*!
 *  @mainpage ForwardList
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

    list1.push_front( 2 );
    assert( list1.front() == 2 );

    list1.push_front( 1 );
    assert( list1.front() == 1 );

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

    //size method test_2:
    std::cout << "Current size: " << list1.size() << std::endl;

    //pop_front method test;
    list1.pop_front();
    assert( list1.front() == 1 );

    //pop_back method test;
    list1.pop_back();
    assert( list1.back() == 6 );

    //size method test_3:
    std::cout << "Current size: " << list1.size() << std::endl;

    //assign method test
    list1.assign( 10 );
    assert( list1.back() == 10 );
    assert( list1.front() == 10 );

    //basic iterator test
    std::cout << "[ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";

    //clear method test
    list1.clear();
    assert( list1.empty() );
    
    list1.push_front( 4 );
    assert( list1.front() == 4 );

    list1.push_front( 3 );
    assert( list1.front() == 3 );

    list1.push_front( 1 );
    assert( list1.front() == 1 );

    list1.push_front( 0 );
    assert( list1.front() == 0 );
    
    ForwardList<int>::iterator position = list1.begin();
    position++;
    
    list1.insert_after( position, 2 );
    
    std::cout << "[ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    position++;
    assert( *position == 2 );
    
    list1.erase_after(position);
    position++;
    assert( *position == 4);
    
    std::cout << "[ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    list1.clear();
    
    list1.push_back( 0 );
    assert( list1.back() == 0 );
    list1.push_back( 10 );
    assert( list1.back() == 10 );
    list1.push_back( 20 );
    assert( list1.back() == 20 );
    list1.push_back( 30 );
    assert( list1.back() == 30 );
    list1.push_back( 40 );
    assert( list1.back() == 40 );
    list1.push_back( 50 );
    assert( list1.back() == 50 );
    
    std::cout << "[ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    ForwardList<int>::iterator pos = list1.begin();
    pos++;
    list1.erase_after( pos, list1.end() );
    
    std::cout << "[ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    list1.insert_after( list1.begin(), {1, 2, 3, 4, 5, 6, 7, 8, 9} );
    
    std::cout << "[ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    ForwardList<int>::const_iterator fnd = list1.find(5);
    assert( *fnd == 4 );
    
    list1.insert_after( fnd, 100 );
    
    std::cout << "[ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    return 0;
}