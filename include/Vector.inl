size_type size() const{
    return miSize;
}

void clear(){
    for ( auto i = miSize-1; i >= 0; i--)
        Object[i].~Object();
    
    miSize = 0;
}

bool empty(){
    return miSize == 0;
}

void push_back( const Object & _x ){
    if ( miCapacity == miSize ){
        resize();
    }
    
    m_array[ miSize++ ] = _x;
}

void pop_back(){
    if ( ! empty() )
        Object[--miSize]->~Object();
}

const Object & back() const{
    
}

const Object & front() const{
    
}

void assign( const Object & x ){
    
}


// Exclusive to dynamic arrays
T & operator[]( size_type idx){
    
}
Object & at ( size_type idx )(){
    
}
size_type capacity() const{
    
}
void reserve( size_type new_capacity ){
    
}