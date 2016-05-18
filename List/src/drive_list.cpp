#include <iostream>
#include <cassert>
#include "list.h"

int main(){
    
    List<int> list1;
    
    //push_front method test:
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
    
    //size method test_3:
    std::cout << "Current size: " << list1.size() << std::endl;
    
    //pop_back method test;
    list1.pop_back();
    assert( list1.back() == 6 );
    
    //size method test_4:
    std::cout << "Current size: " << list1.size() << std::endl;
    
    //assign method test
    list1.assign( 10 );
    assert( list1.back() == 10 );
    assert( list1. front() == 10 );
    
    //size method test_5:
    std::cout << "Current size: " << list1.size() << std::endl;
    
    //clear method test
    list1.clear();
    assert( list1.empty() );
    
    //size method test_6:
    std::cout << "Current size: " << list1.size() << std::endl;
    
    // TESTE NO VALGRIND DEPOIS
    return EXIT_SUCCESS;
}