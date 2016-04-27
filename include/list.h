#include <iostream>

template <class Object>
class List{
public:
    // Constructors:
    virtual List() = 0;
    
    
    // Destructors:
    virtual ~List() = 0;

    // Methods:
    virtual size_type size() const = 0;
    virtual void clear() = 0;
    virtual bool empty() = 0;
    virtual void push_back( const T & x ) = 0;
    virtual void pop_back() = 0;
    virtual const T & back() const = 0;
    virtual const T & front() const = 0;
    virtual void assign( const T & x ) = 0;
    
    
    // Exclusive to linked lists:
    virtual void push_front( const T & x ) = 0;
    virtual void pop_front() = 0;
    
private:
    /* Empty */

};