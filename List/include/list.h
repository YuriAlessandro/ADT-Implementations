#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>

using size_type = int;

template <class Object>
class List{
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
    
public:

    // Constructors:
    List();

    // Destructors:
    ~List();

    // Iterators:
    class const_iterator{
    public:
        const_iterator();
        const Object & operator*() const;
        const_iterator & operator++();
        const_iterator operator++( int );
        const_iterator & operator--();
        const_iterator operator --( int );
        bool operator==( const const_iterator & rhs ) const;
        bool operator!=( const const_iterator & rhs ) const;
    protected:
        SLLNode *current;
        const_iterator( SLLNode * p ) : current( p );
        friend class List<Object>;
    };

    class iterator{
    public:
        iterator( ) : const_iterator( ) {/* EMPTY */ }
        const Object & operator* () const;
        Object & operator* ();

        iterator & operator++();
        iterator operator++( int );
        iterator & operator--();
        iterator operator--( int );
    protected:
        iterator( SLLNode *p ) : const_iterator( p );
        friend class List<Object>;
    };

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

    // Iteradores

    // Funções que precisam de Iteradores
    iterator insert( iterator pos, const T & x );
    template <typename InItr>
    iterator insert( iterator pos, InItr first, InItr last );
    iterator insert( const_iterator pos, std::initializer_list<T> ilist );
    iterator erase( iterator pos );
    iterator erase( iterator first, iterator last );
    template <typename InItr>
    void assign( InItr first, InItr last );
    void assign( std::initializer_list<T> ilist );

};

#include "list.inl"

#endif
