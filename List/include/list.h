#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>

using size_type = int;

template <class Object>
class List{
public:
    
    // Constructors:
    List();
    
    // Destructors:
    ~List();

    // Methods:
    size_type size() const;
    void clear();
    bool empty() const;
    void push_back( const Object & x );
    void pop_back();
    const Object & back() const;
    const Object & front() const;
    void assign( const Object & x );
    
    
    // Exclusive to linked lists:
    void push_front( const Object & x );
    void pop_front();
    
private:
    struct SLLNode {
	    Object miData;
	    SLLNode *mpNext;
	    SLLNode *mpBefore;
	    
	    SLLNode( const Object & d = Object(), SLLNode * n = nullptr, SLLNode * b = nullptr )
        : miData( d ), mpNext( n ), mpBefore( b )
        { /* Empty */ }
	};
	
	SLLNode *mpHead;
	SLLNode *mpTail;
	size_type miSize;
};

#include "list.inl"

#endif