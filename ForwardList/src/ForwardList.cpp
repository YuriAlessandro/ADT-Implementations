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
#include "ForwardList.h"

int main(int argc, char* argv[])
{
    ForwardList<int> lista;
    lista.push_back(3);
    lista.push_back(4);
    lista.push_front(1);
    lista.push_front(2);

    std::cout << "Tamanho: " << lista.size() << "\n";
    lista.clear();
    std::cout << "Tamanho: " << lista.size() << "\n";


    return 0;
}
