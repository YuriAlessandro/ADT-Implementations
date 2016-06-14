/*
 * Test aaplication for the Dictionary with Array Lits or DAL.
 *
 * Try to test as many DAL's methods in varying situations
 * as possible.
 *
 * */

#include <iostream>
#include <sstream>
#include <cmath>
#include <functional>

#include "dal.h"
#include "dsal.h"

// Para teste com chaves inteiras
class MyKeyComparator{
public:
    int operator () (int lhs, int rhs) const {
        if ( lhs < rhs ) return -1;
        else if ( lhs == rhs ) return 0;
        else return 1;
    }
};


int main ( )
{
    //DAL< int, std::string, MyKeyComparator  >  myList( 50 ); // Lista de no máximo 50 elementos.
    DSAL< int, std::string, MyKeyComparator  >  myList( 50 ); // Lista de no máximo 50 elementos.
    std::string res1;
    std::string res2;
    int res3;

////////// Inserindo ////////////
    myList.insert( 15, "dado 1" );
    myList.insert( 2 , "dado 2" );
    myList.insert( 8 , "dado 3" );
    myList.insert( 20, "dado 4" );

    std::cout << "\n>>> myList: " << myList << std::endl;

////////// Removendo ////////////
    myList.remove( 2, res1 );
    myList.remove( 3, res2 );

    std::cout << "\n>>> myList: " << myList << std::endl;
    std::cout << "String removida 1: " << res1 << "\n";
    std::cout << "String removida 2: " << res2 << "\n";

////////// Procurando ///////////
    myList.search( 15, res1 );
    myList.search( 3 , res2 );

    std::cout << "String encontrada 1: " << res1 << "\n";
    std::cout << "String encontrada 2: " << res2 << "\n";

////////// Min, Max, Suc e Pre //////////

    std::cout << "Min: " << myList.min() << std::endl;
    std::cout << "Max: " << myList.max() << std::endl;

    myList.sucessor( 8, res3 );
    std::cout << "Suc: " << res3 << std::endl;
    res3 = -1;

    myList.predecessor( 15, res3 );
    std::cout << "Pre: " << res3 << std::endl;

    std::cout << "\n>>> Normal ending...\n\n";

    return EXIT_SUCCESS;
}
