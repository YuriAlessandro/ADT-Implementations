/*!
 *  @mainpage List
 *  @author Gustavo Araújo e Yuri Alessandro Martins
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *  @version 1.0
 *
 *  @file drive_list.cpp
 *  @brief Driver File
 *
 *  File with the List tests
 */

#include <iostream>
#include <cassert>
#include "List.h"

int main(){
    
    std::cout << "Declaring a list of tests, with objects of type \"int\"...\n";
    List<int> list1;
    
    std::cout << "\n--> Starting tests in push_front method...\n";
    std::cout << "=========================================\n";
    
    std::cout << "Current size: " << list1.size() << std::endl;
    
    std::cout << "\npush_front [3]\n";
    list1.push_front( 3 );
    assert( list1.front() == 3 );
    
    std::cout << "push_front [2]\n";
    list1.push_front( 2 );
    assert( list1.front() == 2 );
    
    std::cout << "push_front [1]\n";
    list1.push_front( 1 );
    assert( list1.front() == 1 );
    
    std::cout << "push_front [0]\n";
    list1.push_front( 0 );
    assert( list1.front() == 0 );
    
    std::cout << "\nThe list after insertions: [ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    std::cout << "\nCurrent size: " << list1.size() << std::endl;
    
    std::cout << "\nApparently, everything went well in the tests in push_front method\n";
    
    std::cout << "\n--> Starting tests in push_back method...\n";
    std::cout << "=========================================\n";
    
    std::cout << "push_back [4]\n";
    list1.push_back( 4 );
    assert( list1.back() == 4 );
    
    std::cout << "push_back [5]\n";
    list1.push_back( 5 );
    assert( list1.back() == 5 );
    
    std::cout << "push_back [6]\n";
    list1.push_back( 6 );
    assert( list1.back() == 6 );
    
    std::cout << "push_back [7]\n";
    list1.push_back( 7 );
    assert( list1.back() == 7 );

    std::cout << "\nThe list after insertions: [ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    //size method test_2:
    std::cout << "\nCurrent size: " << list1.size() << std::endl;
    
    std::cout << "\nApparently, everything went well in the tests in push_back method\n";
    
    std::cout << "\n--> Starting tests in pop_front and pob_back methods...\n";
    std::cout << "=========================================\n";
    
    std::cout << "pop_front... [0]\n";
    list1.pop_front();
    assert( list1.front() == 1 );
    
    std::cout << "Current size: " << list1.size() << std::endl;
    
    std::cout << "pop_back... [7]\n";
    list1.pop_back();
    assert( list1.back() == 6 );
    
     std::cout << "Current size: " << list1.size() << std::endl;
    
    std::cout << "\nThe list after removal: [ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    std::cout << "\nApparently, everything went well in the tests in pop_front and pop_back methods\n";
    
    std::cout << "\n--> Starting tests in assign method...\n";
    std::cout << "=========================================\n";
    
    std::cout << "assign [10]\n";
    list1.assign( 10 );
    assert( list1.back() == 10 );
    assert( list1.front() == 10 );

    std::cout << "The list after assign: [ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    std::cout << "\nApparently, everything went well in the tests in pop_front and pop_back methods\n";
    
    std::cout << "\n--> Starting tests in clear method...\n";
    std::cout << "=========================================\n";
    
    auto it = list1.end();
    it--;
    std::cout << "Inverted List print: [";
    for( /* empty */ ; it != list1.before_begin(); it--)
        std::cout << *it << " ";
    std::cout << "]\n";
    
    
    // Construtores
    List<int> list2 ( list1 );
    List<int> list3 = list2;
    
    std::cout << "Printing list made by copy constructor:\n";
    std::cout << "[ ";
    for ( auto var : list2 )
        std::cout << var << " ";
    
    std::cout << "]\n";
    
    std::cout << "Printing list made by \"=\" copy constructor:\n";
    std::cout << "[ ";
    for ( auto var : list3 )
        std::cout << var << " ";
    
    std::cout << "]\n";
    
    List<int> list4 ( std::move( list2 ) );
    List<int> list5 = std::move( list3 );

    std::cout << "Printing list made by move constructor:\n";
    std::cout << "[ ";
    for ( auto var : list4 )
        std::cout << var << " ";
    
    std::cout << "]\n";
    
    std::cout << "Printing list made by \"=\" move constructor:\n";
    std::cout << "[ ";
    for ( auto var : list5 )
        std::cout << var << " ";
    
    std::cout << "]\n";
    
    std::cout << "Asserting if the old lists are empty...\n";
    assert( list2.empty() );
    assert( list3.empty() );
    
    std::cout << "\nApparently, everything went well in constructor tests.\n";
    
    std::cout << std::endl;
    
    std::cout << "=========================================\n";
    std::cout << "Cleaning up...\n";
    list1.clear();
    assert( list1.empty() );
    
    std::cout << "The list after clear: [ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    std::cout << "\nApparently, everything went well in the tests in clear method\n";
    
    std::cout << "=========================================\n";
    
    std::cout << "\nInserting {1,2,3}\n";
    list1.insert( list1.cbegin(), {1, 2, 3} );
    
    std::cout << "The list after stuff: [ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    std::cout << "=========================================\n";
    
    auto ers = list1.begin();
    ers++;
    
    std::cout << "Deleting from " << *ers << " until the end of the list." << std::endl;
    list1.erase( ers, list1.end() );
    
    std::cout << "The list after erase: [ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    std::cout << "=========================================\n";
    
    std::cout << "Everything seemed to run fine, leaving the program ...\n";
    return EXIT_SUCCESS;
}