
template <class Object>
size_type Vector< Object >::size() const{
    return miSize;
}
template <class Object>
void Vector< Object >::clear(){
    for ( auto i = 0; i < miSize; i++ )
        // Por que -> e não . ?
        mpArray[i].~Object();

    miSize = 0;
}

template <class Object>
bool Vector< Object >::empty(){
    return ( miSize == 0 );
}

template <class Object>
void Vector< Object >::push_back( const Object & _x ){
    if ( miCapacity == miSize )
        reserve( 2 * miCapacity );

    mpArray[ miSize++ ] = _x;
}

template <class Object>
void Vector< Object >::pop_back(){
    if ( !empty() )
        // Por que -> e não . ?
        mpArray[--miSize].~Object();
}

template <class Object>
const Object & Vector< Object >::front() const{
    return mpArray[0];
}

template <class Object>
const Object & Vector< Object >::back() const{
    return mpArray[miSize - 1];
}

template <class Object>
void Vector< Object >::assign( const Object & _x ){
    // miSize ou miCapacity?
    for ( auto i = 0; i < miCapacity; i++ )
        mpArray[i] = _x;

    miSize = miCapacity;
}


// Exclusive to dynamic arrays
template <class Object>
Object & Vector< Object >::operator[]( size_type idx ){
    return mpArray[idx];
}

/*
template <class Object>
Object & Vector< Object >::at ( size_type idx )(){
    if( idx >= miSize )
        throw std::out_of_range("yaddayadda");

    return mpArray[idx];
}
*/

template <class Object>
size_type Vector< Object >::capacity() const{
    return miCapacity;
}

template <class Object>
void Vector< Object >::reserve( size_type new_capacity ){

	std::unique_ptr< Object[] > newArray( new Object[new_capacity] );

	for ( auto i = 0; i < miSize; i++ )
		newArray[i] = mpArray[i];

	mpArray = std::move( newArray );
    miCapacity = new_capacity;
}

// Função somente para debug
template < class Object >
Object * Vector< Object >::data() const{
    return mpArray.get();
}
