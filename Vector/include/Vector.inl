/**
 *  \file Vector.inl
 *  \brief Vector implementations
 */

template <class Object>
size_type Vector<Object>::size() const{
    return miSize;
}

template <class Object>
void Vector<Object>::clear(){
    for ( auto i = 0; i < miSize; i++ )
        mpArray[i].~Object();

    miSize = 0;
}

template <class Object>
bool Vector<Object>::empty(){
    return ( miSize == 0 );
}

template <class Object>
void Vector<Object>::push_back( const Object & _x ){
    if ( miCapacity == miSize )
        reserve( 2 * miCapacity );

    mpArray[ miSize++ ] = _x;
}

template <class Object>
void Vector<Object>::pop_back(){
    if ( !empty() )
        // Por que -> e não . ?
        mpArray[--miSize].~Object();
}

template <class Object>
const Object & Vector<Object>::front() const{
    return mpArray[0];
}

template <class Object>
const Object & Vector<Object>::back() const{
    return mpArray[miSize - 1];
}

template <class Object>
void Vector<Object>::assign( const Object & _x ){
    // miSize ou miCapacity?
    for ( auto i = 0; i < miCapacity; i++ )
        mpArray[i] = _x;

    miSize = miCapacity;
}


// Exclusive to dynamic arrays
template <class Object>
Object & Vector<Object>::operator[]( size_type idx ){
    return mpArray[idx];
}


template <class Object>
Object & Vector<Object>::at( size_type idx ){
    if( idx >= miSize )
        throw std::out_of_range("yaddayadda");

    return mpArray[idx];
}

template <class Object>
size_type Vector<Object>::capacity() const{
    return miCapacity;
}

template <class Object>
void Vector<Object>::reserve( size_type new_capacity ){

	std::unique_ptr< Object[] > newArray( new Object[new_capacity] );

	for ( auto i = 0; i < miSize; i++ )
		newArray[i] = mpArray[i];

	mpArray = std::move( newArray );
    miCapacity = new_capacity;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////     ITERATORS      ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template <class Object>
typename Vector<Object>::const_iterator Vector<Object>::cbegin() const{
    //Object * pointer = m_array[0];

    //Object * pointer;
    //pointer = &m_array[0];
    return const_iterator( mpArray.get() ); // return * ou &?
    //return const_iterator( & mpArray[0] );
}

template <class Object>
typename Vector<Object>::const_iterator Vector<Object>::cend() const{
    // Deveria ser só miSize
    return const_iterator( mpArray.get() + miSize );
    //return const_iterator( & mpArray[miSize] );
}

template <class Object>
typename Vector<Object>::iterator Vector<Object>::begin() const{
    return iterator( mpArray.get() ); // return * ou &?
    //return iterator( & mpArray[0] ); // return * ou &?
}

template <class Object>
typename Vector<Object>::iterator Vector<Object>::end() const{
    return iterator( mpArray.get() + miSize );
    //return iterator( & mpArray[miSize] );

}

template <class Object>
typename Vector<Object>::const_iterator & Vector<Object>::const_iterator::operator++(){
    ++m_ptr;
    return *this;
}

template <class Object>
typename Vector<Object>::const_iterator Vector<Object>::const_iterator::operator++(int){
    const_iterator old( m_ptr++ );
    return old;
}

template <class Object>
typename Vector<Object>::const_iterator & Vector<Object>::const_iterator::operator--(){
    --m_ptr;
    return *this;
}

template <class Object>
typename Vector<Object>::const_iterator Vector<Object>::const_iterator::operator--(int){
    const_iterator old( m_ptr-- );
    return old;
}

template <class Object>
bool Vector<Object>::const_iterator::operator==( const typename Vector<Object>::const_iterator & RHS ) const{
    return ( m_ptr == RHS.m_ptr );
}

template <class Object>
bool Vector<Object>::const_iterator::operator!=( const typename Vector<Object>::const_iterator & RHS ) const{
    return ( m_ptr != RHS.m_ptr );
}

template <class Object>
const Object & Vector<Object>::const_iterator::operator*() const{
    return * m_ptr;
}

template <class Object>
Object & Vector<Object>::iterator::operator*(){
    return * const_iterator::m_ptr;
}


// Funções somente para debug
template < class Object >
Object * Vector<Object>::data() const{
    return mpArray.get();
}

template < class Object >
void Vector<Object>::superDebuggator() const{
    std::cout << "Ponteiro hear de elto: " << mpArray.get() << std::endl;
    std::cout << "Ponteiro end de elto: " << mpArray.get() + miSize << std::endl;
    std::cout << "Ponteiro hear de eu: " << & mpArray[0] << std::endl;
    std::cout << "Ponteiro end de eu: " << & mpArray[miSize] << std::endl;
}
