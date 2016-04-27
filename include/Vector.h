/**
 *  \file Vector.h
 *  \brief 
 */

#include <iostream>

template <class Object>
class Vector {
    
using size_type = int;
    
public:
    // CONSTRUTOR
    Vector( size_type _newSize = 10 ) : miCapacity (_newSize), miSize( 0 ) {
        mpArray = new Object[ _newSize ];
    }
    
   // DESTRUTOR
    ~Vector(){
        delete mpArray;
    }
    
    ////////////////
    // ITERADORES //
    ////////////////
    class const_iterator{
    friend class Vector;
    public:
        const_iterator( Object * _new ) : m_ptr(_new)
        {}
        
        void operator++(){}
        void operator--();
        bool operator==() const;
        bool operator!=() const;
        const Object & operator*() const;
    
    
    protected:
        Object * m_ptr;
        
    };
    
    class iterator : public const_interator{
    public:
        iterator( Object * _new ){
            const_interator( _new );
        }
        
        void operator++();
        void operator--();
        bool operator==() const;
        bool operator!=() const;
        Object & operator*();
        
    private:
    
    };
    
    //////////////
    // METÓDOS: //
    //////////////
    
    const_iterator begin() const{
        return m_array[0]; // return * ou &?
    }
        
    const_iterator end() const{
        return m_array[ miSize - 1 ];
    }
    
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
    Object & at ( size_type idx )();
    size_type capacity() const;
    void reserve( size_type new_capacity );

private:
    std::unique_ptr< Object > mpArray;
    size_type miCapacity;
    size_type miSize;
};
