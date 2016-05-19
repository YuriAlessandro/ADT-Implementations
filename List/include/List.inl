template<class Object>
List<Object>::List(){
    mpHead = new SLLNode();
    mpTail = new SLLNode();

    mpHead->mpNext = mpTail;
    mpTail->mpBefore = mpHead;

    miSize = 0;
}

template<class Object>
List<Object>::~List(){
    clear();
    delete mpHead;
    delete mpTail;
}

template<class Object>
size_type List<Object>::size() const{
    return miSize;
}

template<class Object>
void List<Object>::clear(){
    SLLNode * work;
    while ( mpHead->mpNext != mpTail ){
        mpHead->mpNext->miData.~Object();

        work = mpHead->mpNext->mpNext;
        delete mpHead->mpNext;
        mpHead->mpNext = work;
    }
    miSize = 0;
}

template<class Object>
bool List<Object>::empty() const{
    return ( mpHead->mpNext == mpTail );
}

//TALVEZ ESTEJA ERRADA EM 'mpTail->mpBefore = tmp;'
template<class Object>
void List<Object>::push_back( const Object & x ){
    SLLNode * tmp;
    try{
        tmp = new SLLNode(x, mpTail, mpTail->mpBefore);
    }catch (const std::bad_alloc & e){
        throw e;
    }

    mpTail->mpBefore->mpNext = tmp;
    mpTail->mpBefore = tmp;
    miSize++;
}

// MUITO LOUCO, JESUS!!!
template<class Object>
void List<Object>::pop_back(){
    if ( empty() )
        throw std::out_of_range("Nem sei se é esse erro");
    else{
        SLLNode * work = mpTail->mpBefore;
        mpTail->mpBefore = mpTail->mpBefore->mpBefore;  // CERTO
        work->mpBefore->mpNext = mpTail;                // CERTO

        work->miData.~Object();
        delete work;
    }
    miSize--;
}

template<class Object>
const Object & List<Object>::back() const{
    if ( empty() )
        throw std::out_of_range("Nem sei se é esse erro");
    else
        return mpTail->mpBefore->miData;
}

template<class Object>
const Object & List<Object>::front() const{
    if( empty() )
        throw std::out_of_range("Nem sei se é esse erro");
    else
        return mpHead->mpNext->miData;
}

/**
 * \brief Todos os elementos da lista passam a ter o valor de _x
 * \param Valor que será atribuído a todos os objetos.
*/
template<class Object>
void List<Object>::assign( const Object & _x ){
    SLLNode * work = mpHead->mpNext;
    while( work != mpTail ){
        work->miData.~Object();
        work->miData = _x;
        work = work->mpNext;
    }
}

template<class Object>
void List<Object>::push_front( const Object & x ) {
    SLLNode * tmp;
    try{
        tmp = new SLLNode(x, mpHead->mpNext, mpHead);
    }catch (const std::bad_alloc & e){
        throw e;
    }
    mpHead->mpNext = tmp;
    tmp->mpNext->mpBefore = tmp;

    miSize++;
}

template<class Object>
void List<Object>::pop_front() {
    SLLNode * work = mpHead->mpNext;
    mpHead->mpNext = work->mpNext;
    work->mpNext->mpBefore = mpHead;

    work->miData.~Object();
    delete work;

    miSize--;
}

template<class Object>
typename List<Object>::iterator List<Object>::before_begin(){
    return iterator( mpHead );
}

template<class Object>
typename List<Object>::const_iterator List<Object>::cbefore_begin() const{
    return const_iterator( mpHead );
}

template<class Object>
typename List<Object>::iterator List<Object>::begin(){
    return iterator( mpHead->mpNext );
}

template<class Object>
typename List<Object>::const_iterator List<Object>::cbegin() const{
    return const_iterator( mpHead->mpNext );
}

template<class Object>
typename List<Object>::iterator List<Object>::end(){
    return iterator( mpTail );
}

template<class Object>
typename List<Object>::const_iterator List<Object>::cend() const{
    return const_iterator( mpTail );
}

/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////


template<class Object>
typename List<Object>::iterator List<Object>::insert(
    typename List<Object>::iterator pos, const Object & _x ){
    
    SLLNode * work;
    
    try{
        work = new SLLNode( _x, pos.current, pos.current->mpBefore );
    }catch( const std::bad_alloc & e ){
        throw e;
    }
    
    work->mpBefore->mpNext = work;
    pos.current->mpBefore = work;
    
    return iterator( work );
    
    miSize++;

}

/*
template <class Object>
template <typename InItr>
typename List<Object>::iterator List<Object>::insert(
    typename List<Object>::iterator pos, InItr first, InItr last ){

}



template <class Object>
typename List<Object>::iterator List<Object>::insert(
    typename List<Object>::const_iterator pos, std::initializer_list<Object> ilist ){
    
    SLLNode * work;

    for ( auto element : ilist ){
        
        try{
            work = new SLLNode( element, pos.current, pos.current->mpBefore );
        }catch( const std::bad_alloc & e ){
            throw e;
        }
        
        work->mpBefore->mpNext = work;
        pos.current->mpBefore = work;
        
        miSize++;
        
    }
    
    return iterator( work );

}
*/


template <class Object>
typename List<Object>::iterator List<Object>::erase(
    typename List<Object>::iterator pos ){

    iterator ret( pos.current->mpNext );
    
    pos.current->mpNext->mpBefore = pos.current->mpBefore;
    pos.current->mpBefore->mpNext = pos.current->mpNext;
    
    (*pos).~Object();
    delete pos.current;
    
    miSize--;
    
    return ret;
}

/*
template <class Object>
typename List<Object>::iterator List<Object>::erase(
    typename List<Object>::iterator first, typename List<Object>::iterator last ){
    
}


template <class Object>
template <typename InItr>
void List<Object>::assign( InItr first, InItr last ){

}

template <class Object>
void List<Object>::assign( std::initializer_list<T> ilist ){

}

*/


////////////////
// ITERADORES //
////////////////

template<class Object>
const Object & List<Object>::const_iterator::operator*() const{
    return current->miData;
}

// Tratamento de erro necessário?
template<class Object>
typename List<Object>::const_iterator & List<Object>::const_iterator::operator++(){
    if ( current != mpTail ) current = current->mpNext;
    else current = mpHead->mpNext;
    
    return *this;
}

template<class Object>
typename List<Object>::const_iterator List<Object>::const_iterator::operator++( int ){
    const_iterator ret( current );
    
    if ( current != mpTail ) current = current->mpNext;
    else current = mpHead->mpNext;
    
    return ret;
}

template<class Object>
typename List<Object>::const_iterator & List<Object>::const_iterator::operator--(){
    if ( current != mpHead->mpNext ) current = current->mpBefore;
    else current = mpTail;
    
    return *this;
}

template<class Object>
typename List<Object>::const_iterator List<Object>::const_iterator::operator--( int ){
    const_iterator ret( current );
    
    if ( current != mpHead->mpNext ) current = current->mpBefore;
    else current = mpTail;
    
    return ret;
}

template<class Object>
bool List<Object>::const_iterator::operator==( const typename List<Object>::const_iterator & rhs ) const{
    return ( current == rhs.current );
}

template<class Object>
bool List<Object>::const_iterator::operator!=( const typename List<Object>::const_iterator & rhs ) const{
    return ( current != rhs.current );
}

template<class Object>
const Object & List<Object>::iterator::operator*() const{
    return const_iterator::current->miData;
}

template<class Object>
Object & List<Object>::iterator::operator*(){
    return const_iterator::current->miData;
}

template<class Object>
typename List<Object>::iterator & List<Object>::iterator::operator++(){
    const_iterator::current = const_iterator::current->mpNext;
    return *this;
}

template<class Object>
typename List<Object>::iterator List<Object>::iterator::operator++( int ){
    iterator ret( const_iterator::current );
    
    const_iterator::current = const_iterator::current->mpNext;

    return ret;
}

template<class Object>
typename List<Object>::iterator & List<Object>::iterator::operator--(){
    const_iterator::current = const_iterator::current->mpBefore;
    
    return *this;
}

template<class Object>
typename List<Object>::iterator List<Object>::iterator::operator--( int ){
    iterator ret( const_iterator::current );
    
    const_iterator::current = const_iterator::current->mpBefore;

    return ret;
}
