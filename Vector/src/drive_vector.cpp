/*!
 *  @mainpage Vector
 *  @author Gustavo Araújo and Yuri Alessandro Martins
 *  @date May, 2016
 *
 *  @file drive_vector.cpp
 *  @brief Driver File
 *
 *  File with the Vector tests
 */

#include <iostream>
#include <cassert>
#include "Vector.h"

int main(){
    
    std::cout << "Declaring a vector of tests, with objects of type \"int\"...\n";
    Vector<int> vtest;
    
    std::cout << "Testing if the vector is empty even...\n";
    assert( vtest.empty() );
    std::cout << ".. Everything seemed to go well...\n";
    
    std::cout << "Testing capacity [" << vtest.capacity() << "...\n";
    assert( vtest.capacity() == 10 );
    
    std::cout << "Starting tests in push_back method...\n";

    for( auto i = 0; i < 6; i++){
        std::cout << "push_back [" << i <<"]\n";
        vtest.push_back(i);
    }
    
    std::cout << "\nThe vector after insertions: [ ";
    for ( auto var : vtest )
        std::cout << var << " ";
    std::cout << "]\n";
    
    assert( vtest.size() == 6 );
    
    std::cout << "=========================================\n";
    
    /*
    std::cout << "Testing the method data...\n";
    int *ptr = vtest.data();
    for (auto i = 0; i < 10; i++)
        assert(*(ptr+i) == i);
        
    std::cout << "=========================================\n";
    */
    
    std::cout << "Testing methods front and back...\n";
    assert( vtest.front() == 0 );
    assert( vtest.back() == 5 );
    
    std::cout << "=========================================\n";
    
    std::cout << "Testing method pop_back...\n";
    vtest.pop_back();
    
    std::cout << "\nThe vector after removal: [ ";
    for ( auto var : vtest )
        std::cout << var << " ";
    std::cout << "]\n";
    
    assert( vtest.size() == 5 );
    
    std::cout << "=========================================\n";
    
    std::cout << "Testing operator[] and operator=...\n";
    std::cout << "vector[4] = 100 testing...\n";
    vtest[4] = 100;
    
    std::cout << "\nThe vector after insertion: [ ";
    for ( auto var : vtest )
        std::cout << var << " ";
    std::cout << "]\n";
    
    std::cout << "Testing at operator...\n";
    assert( vtest.at(4) == 100 );
    
    std::cout << "=========================================\n";
    
    std::cout << "Testing method assign... \n";
    
    vtest.assign(500);
    
    std::cout << "\nThe vector after asign: [ ";
    for ( auto var : vtest )
        std::cout << var << " ";
    std::cout << "]\n";
    
    assert( vtest.front() == 500 );
    assert( vtest.back() == 500 );
    
    std::cout << "=========================================\n";
    
    std::cout << "Testing clear method...\n";
    
    vtest.clear();
    
    std::cout << "\nThe vector after clear: [ ";
    for ( auto var : vtest )
        std::cout << var << " ";
    std::cout << "]\n";
    
    std::cout << "=========================================\n";
    
    for( auto i = 0; i < 10; i++)
        vtest.push_back(i);
    
    std::cout << "\nJust filling again: [ ";
    for ( auto var : vtest )
        std::cout << var << " ";
    std::cout << "]\n";
    
    std::cout << "=========================================\n";
    
    size_type newCpct = 20;
    vtest.reserve( newCpct );
    
    for( auto i = 10; i < 20; i++)
        vtest.push_back(i);
    
    std::cout << "\nVector after reserve memory: [ ";
    for ( auto var : vtest )
        std::cout << var << " ";
    std::cout << "]\n";
    std::cout << "=========================================\n";
    
    std::cout << "Testing \"copy assign\" and \"copy move\"...\n";
    
    std::cout << "Creating a vector of int [v2]...\n";
    Vector<int> v2 ( vtest );
    std::cout << "Creating a vector of int [v3] and type v3 = v2... \n";
    Vector<int> v3 = v2;
    
    std::cout << "Cheking...\n";
    for (auto i = 0; i < 9; i++) {
        assert(v2[i] == i);
        assert(v3[i] == i);
    }
    
    std::cout << "Creating v4 and moving v2's elements to it... \n";
    Vector<int> v4 ( std::move( v2 ) );
    std::cout << "Creating v5 and moving v3's elements to it... \n";
    Vector<int> v5 = std::move( v3 );
    
    std::cout << "Checking...\n";
    for (auto i = 0; i < 9; i++) {
        assert(v4[i] == i);
        assert(v5[i] == i);
    }
    
    std::cout << "Benchmark v2 and v3 is null...\n";
    
    assert( v2.data() == nullptr );
    assert( v3.data() == nullptr );
    
    std::cout << "It seems that everything worked out here... \n";
    
    std::cout << "=========================================\n";
    
    std::cout << "Testing iterators... \n";
    std::cout << "Creatin a vector [vtest2].\n";
    Vector<int> vtest2;
    
    for( auto i = 0; i < 10; i++)
        vtest2.push_back(i);
    
    std::cout << "\nJust filling: [ ";
    for ( auto var : vtest )
        std::cout << var << " ";
    std::cout << "]\n";
    
    auto i = 0;
    for ( auto it = vtest2.begin(); it != vtest2.end(); it++, i++)
        assert(*it == i);

    assert( vtest2.cbegin() != vtest2.cend() );
    
    std::cout << "=========================================\n";
    std::cout << "Everything seemed to run fine, leaving the program ...\n";

    return EXIT_SUCCESS;
}