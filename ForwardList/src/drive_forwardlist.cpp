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
    std::cout << "Declaring a list of tests, with objects of type \"int\"...\n";
    ForwardList<int> list1;
    
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

    std::cout << "Cleaning up...\n";
    list1.clear();
    assert( list1.empty() );
    
    std::cout << "The list after clear: [ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    std::cout << "\nApparently, everything went well in the tests in clear method\n";
    
    std::cout << "\n--> Starting tests in insert_after method...\n";
    std::cout << "=========================================\n";
    
    std::cout << "Just filling the list again...\n";
    list1.push_front( 4 );
    assert( list1.front() == 4 );

    list1.push_front( 3 );
    assert( list1.front() == 3 );

    list1.push_front( 1 );
    assert( list1.front() == 1 );

    list1.push_front( 0 );
    assert( list1.front() == 0 );
    
    std::cout << "The list after filling: [ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    ForwardList<int>::iterator position = list1.begin();
    position++;
    
    std::cout << "\nEntering [2] after position " << *position << "\n";
    list1.insert_after( position, 2 );
    
    std::cout << "The list after insertion: [ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    position++;
    assert( *position == 2 );
    
    std::cout << "\nApparently, everything went well in the tests in insert_after method\n";
    
    std::cout << "\n--> Starting tests in erase_after method...\n";
    std::cout << "=========================================\n";
    
    std::cout << "\nRemoving after position " << *position <<"\n";
    list1.erase_after(position);
    position++;
    assert( *position == 4);
    
    std::cout << "The list after removal: [ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    std::cout << "\nApparently, everything went well in the tests in erase_after method\n";
    
    std::cout << "\n--> Starting tests in erase_after method...\n";
    std::cout << "=========================================\n";
    
    std::cout << "Clearing the list for new tests...\n";
    list1.clear();
    
    std::cout << "Just filling the list again...\n";
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
    
    std::cout << "The list after insertions: [ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";

    
    ForwardList<int>::iterator pos = list1.begin();
    pos++;
    std::cout << "Erase after " << *pos << " until the end...\n";
    list1.erase_after( pos, list1.end() );
    
    std::cout << "The list after removals: [ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    std::cout << "\nApparently, everything went well in the tests in erase_after method\n";
    
    std::cout << "\n--> Starting tests in insert_after method...\n";
    std::cout << "=========================================\n";
    
    std::cout << "Inserting {1, 2, 3, 4, 5, 6, 7, 8, 9} at begin...\n";
    list1.insert_after( list1.begin(), {1, 2, 3, 4, 5, 6, 7, 8, 9} );
    
    std::cout << "The list after insertions: [ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    std::cout << "\nApparently, everything went well in the tests in insertion_after method\n";
    
    std::cout << "\n--> Starting tests in find method...\n";
    std::cout << "=========================================\n";
    
    std::cout << "Trying to find 5...\n";
    ForwardList<int>::const_iterator fnd = list1.find(5);
    assert( *fnd == 4 );
    std::cout << "5 was found after " << *fnd << std::endl;
    
    std::cout << "To take advantage, we will add 100 after " << *fnd << std::endl;
    list1.insert_after( fnd, 100 );
    
    
    std::cout << "The list after insertion: [ ";
    for ( auto var : list1 )
        std::cout << var << " ";
    std::cout << "]\n";
    
    std::cout << "\nApparently, everything went well in the tests in find method\n";
    
    std::cout << "=========================================\n";
    
    std::cout << "Everything seems to run well up to this point, leaving the program ...\n";
    
    // Construtores
    ForwardList<int> list2 ( list1 );
    ForwardList<int> list3 = list2;
    
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
    
    ForwardList<int> list4 ( std::move( list2 ) );
    ForwardList<int> list5 = std::move( list3 );

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

    std::cout << "=========================================\n";
    std::cout << "Everything seemed to run fine, leaving the program ...\n";
    
    return EXIT_SUCCESS;
}