#ifndef _VECTOR_H_
#define _VECTOR_H_

/**
 *  \file Vector.h
 *  \brief Vector headers
 */

#include <iostream>
#include <memory>

using size_type = int;

template <class Object>
class Vector {

public:
    // CONSTRUTOR
    Vector( size_type _newSize = 10 ) : miCapacity (_newSize), miSize( 0 ) {
        mpArray = std::unique_ptr< Object[] >( new Object[ _newSize ] );
    }

    ////////////////
    // ITERADORES //
    ////////////////
    class const_iterator{
    friend class Vector;
    public:
        const_iterator( Object * _new = nullptr ) : m_ptr( _new )
        {}

        const_iterator & operator++();
        const_iterator operator++(int);
        const_iterator & operator--();
        const_iterator operator--(int);
        bool operator==( const const_iterator & RHS ) const;
        bool operator!=( const const_iterator & RHS ) const;
        const Object & operator*() const{;

    protected:
        Object * m_ptr;

    };

    class iterator : public const_iterator{
    public:
        iterator( Object * _new = nullptr ) : const_iterator( _new )
        {}

        Object & operator*();
    };

    //////////////
    // METÓDOS: //
    //////////////

    const_iterator cbegin() const;
    const_iterator cend() const;
    iterator begin() const;
    iterator end() const;

    size_type size() const;
    void clear();
    bool empty();
    void push_back( const Object & x );
    void pop_back();
    const Object & back() const;
    const Object & front() const;
    void assign( const Object & x );


    // Exclusive to dynamic arrays
    Object & operator[]( size_type idx);
    Object & at ( size_type idx );
    size_type capacity() const;
    void reserve( size_type new_capacity );

    Object * data() const;
    void superDebuggator() const;


private:
    std::unique_ptr< Object[] > mpArray;
    size_type miCapacity;
    size_type miSize;
};

#include "Vector.inl"

#endif