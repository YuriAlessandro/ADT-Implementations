/*!
 *  @mainpage Vector
 *  @author Gustavo Araújo e Yuri Alessandro Martins
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *  @version 1.0
 *
 *  @file ForwardList.h
 *  @brief Header file
 *
 *  File with the Forward List header
 */

#ifndef _FORWARDLIST_H_
#define _FORWARDLIST_H_

#include <iostream>
#include <stdexcept>

using size_type = int;

template <class Object>
class ForwardList {

public:
    struct SLLNode {
        Object miData;
        SLLNode * mpNext;

        SLLNode( const Object & d = Object(), SLLNode * n = nullptr )
        : miData( d ), mpNext( n )
        { /* Empty */ }
    };


    ForwardList();
    ~ForwardList();

    size_type size() const;
    void clear();
    bool empty() const;
    void push_back( const Object & x );
    void pop_back();
    const Object & front() const;
    const Object & back() const;
    void assign( const Object & x );

    // Funções exclusivas à implementação de listas encadeadas
    void push_front( const Object & x );
    void pop_front();

private:
    SLLNode * mpHead;
    SLLNode * mpTail;
    size_type miSize;
};

#include "ForwardList.inl"

#endif
