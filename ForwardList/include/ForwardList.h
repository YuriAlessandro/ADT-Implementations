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

#include "ForwardList.inl"

using size_type = int;

template <class Object>
class ForwardList {
private:
    struct SLLNode {
        Object miData;
        SLLNode * mpNext;
    };
    
    SLLNode * mpHead;

public:
    ForwardList();
    ~ForwardList();
    
    size_type size() const;
    void clear();
    bool empty();
    void push_back( const T & x );
    void pop_back();
    const T & back() const;
    void assign( const T & x );
    
    // Funções exclusivas à implementação de listas encadeadas
    void push_front( const T & x );
    void pop_front();
}