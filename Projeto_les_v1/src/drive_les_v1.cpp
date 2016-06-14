// Para compilar: g++ -Wall -pedantic drive_les_v1.cpp les_v1.cpp -o drive_les_v1

#include "les_v1.h"
#include <iostream>
using std::cout;


int main ( void ) {
    SNPtr pHead = NULL;// nullptr;
    int tempRes;
    SNPtr tempPtr;

    cout << "\nIs empty?: " << empty( pHead ) << "\n";

    /////////////// PUSHING ///////////////
    pushFront( pHead, 3 );
    pushFront( pHead, 2 );
    pushFront( pHead, 1 );
    pushBack( pHead, 4 );
    pushBack( pHead, 5 );

    print( pHead );

    /////////////// FIND, REMOVE AND INSERT ///////////////
    tempPtr = find( pHead, 1 );
    cout << "\nPointer to the first element, should be null: " << tempPtr << "\n";
    std::cout << "Inserting \"100\" before the \"1\"." << std::endl;
    insert( pHead, tempPtr, 100 );
    print( pHead );

    std::cout << "Removing the \"100\"" << std::endl;
    remove( pHead, tempPtr, tempRes );
    print( pHead );

    tempPtr = find( pHead, 3 );
    cout << "\nmiData of the pointer to the third element, should be 2: " << tempPtr->miData << "\n";
    std::cout << "Inserting \"300\" before the \"3\"." << std::endl;
    insert( pHead, tempPtr, 300 );
    print( pHead );

    tempPtr = find( pHead, 1000 );
    cout << "\nmpNext of the last element (in case of not found), should be null: " << tempPtr->mpNext << "\n";
    std::cout << "Inserting \"500\" as the last element." << std::endl;
    insert( pHead, tempPtr, 500 );
    print( pHead );

    /////////////// FRONT AND BACK ///////////////
    front( pHead, tempRes );
    cout << "\nFront: " << tempRes << "\n";

    back( pHead, tempRes );
    cout << "Back: " << tempRes << "\n";

    /////////////// POP FRONT AND POP BACK ///////////////
    popFront( pHead, tempRes );
    cout << "\nPopped Front: " << tempRes << "\n";

    popBack( pHead, tempRes );
    cout << "Popped Back: " << tempRes << "\n";

    /////////////// EMPTY AND LENGTH ///////////////
    cout << "\nIs empty?: " << empty( pHead ) << "\n";
    cout << "List size: " << length( pHead ) << "\n";

    /////////////// REVERSE, CLEAR AND PRINT ///////////////
    print( pHead );
    cout << "\nReversing...\n";
    reverse( pHead );
    print( pHead );

    cout << "\n Clearing...\n";
    clear( pHead );
    print( pHead );


    cout << "\n\n>>> Normal exiting...\n";
    return EXIT_SUCCESS;
}
