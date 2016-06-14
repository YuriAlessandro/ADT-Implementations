/*!
 *  @mainpage Vector
 *  @author Gustavo Araújo e Yuri Alessandro Martins
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *  @version 1.0
 *
 *  @file List.inl
 *  @brief Implementations File
 *
 *  File with the List implementations
 */


template<class Object>
List<Object>::List(){
    try{
        mpHead = new DLLNode;
        mpTail = new DLLNode;
    }catch ( std::bad_alloc e ){
        throw e;
    }
    
    mpHead->mpNext = mpTail;
    mpTail->mpBefore = mpHead;

    miSize = 0;
}

template<class Object>
List<Object>::List( const List & _vec ){
    miSize = _vec.miSize;
    
    try{
        mpHead = new DLLNode;
        mpTail = new DLLNode;
    }catch ( std::bad_alloc e ){
        throw e;
    }
    
    mpHead->mpNext = mpTail;
    mpTail->mpBefore = mpHead;
    
    DLLNode * work = mpHead;
    
    auto it = _vec.cbegin();
    it++;
    
    
    for( auto it = _vec.cbegin(); it != _vec.cend(); it++ ){
        try{
            work->mpNext = new DLLNode( *it, nullptr, work );
            work = work->mpNext;
        }catch( std::bad_alloc e ){
            throw e;
        }
    }
    
    work->mpNext = mpTail;
    mpTail->mpBefore = work;
}

template<class Object>
List<Object>::List( List && _vec ){
    miSize = _vec.miSize;
    _vec.miSize = 0;
    
    try{
        mpHead = new DLLNode( Object(), _vec.mpHead->mpNext, nullptr );
        mpTail = new DLLNode( Object(), nullptr, _vec.mpTail->mpBefore );
    }catch ( std::bad_alloc e ){
        throw e;
    }
    
    _vec.mpTail->mpBefore->mpNext = mpTail;
    
    _vec.mpHead->mpNext = _vec.mpTail;
    _vec.mpTail->mpBefore = _vec.mpHead;
}

template<class Object>
List<Object> & List<Object>::operator= ( const List & _vec ){
    
    miSize = _vec.miSize;
    
    this->clear();
    
    DLLNode * work = mpHead;
    
    for( auto it = _vec.cbegin(); it != _vec.cend(); it++ ){
        try{
            work->mpNext = new DLLNode( *it, nullptr, work );
            work = work->mpNext;
        }catch( std::bad_alloc e ){
            throw e;
        }
    }
    
    work->mpNext = mpTail;
    mpTail->mpBefore = work;
    
    return *this;
    
}

template<class Object>
List<Object> & List<Object>::operator= ( List && _vec ){
    this->clear();
    
    miSize = _vec.miSize;
    _vec.miSize = 0;
    
    mpHead->mpNext = _vec.mpHead->mpNext;
    mpTail->mpBefore = _vec.mpTail->mpBefore;
    _vec.mpTail->mpBefore->mpNext = mpTail;
    
    _vec.mpHead->mpNext = _vec.mpTail;
    _vec.mpTail->mpBefore = _vec.mpHead;

    return *this;
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
    DLLNode * work;
    while ( mpHead->mpNext != mpTail ){
        mpHead->mpNext->miData.~Object();

        work = mpHead->mpNext->mpNext;
        delete mpHead->mpNext;
        mpHead->mpNext = work;
    }
    
    mpTail->mpBefore = mpHead;
    miSize = 0;
}

template<class Object>
bool List<Object>::empty() const{
    return ( mpHead->mpNext == mpTail );
}

template<class Object>
void List<Object>::push_back( const Object & x ){
    DLLNode * tmp;
    try{
        tmp = new DLLNode(x, mpTail, mpTail->mpBefore);
    }catch (const std::bad_alloc & e){
        throw e;
    }

    mpTail->mpBefore->mpNext = tmp;
    mpTail->mpBefore = tmp;
    miSize++;
}

template<class Object>
void List<Object>::pop_back(){
    if ( empty() )
        throw std::out_of_range("[pop_back]: The list is empty, there is nothing to be removed.");
    else{
        DLLNode * work = mpTail->mpBefore;
        mpTail->mpBefore = mpTail->mpBefore->mpBefore;  
        work->mpBefore->mpNext = mpTail;                

        work->miData.~Object();
        delete work;
    }
    miSize--;
}

template<class Object>
const Object & List<Object>::back() const{
    if ( empty() )
        throw std::out_of_range("[back]: The list is empty, there are no elements in the \"back\"");
    else
        return mpTail->mpBefore->miData;
}

template<class Object>
const Object & List<Object>::front() const{
    if( empty() )
        throw std::out_of_range("[front]: The list is empty, there are no elements in the \"front\"");
    else
        return mpHead->mpNext->miData;
}

template<class Object>
void List<Object>::assign( const Object & _x ){
    DLLNode * work = mpHead->mpNext;
    while( work != mpTail ){
        work->miData.~Object();
        work->miData = _x;
        work = work->mpNext;
    }
}

template<class Object>
void List<Object>::push_front( const Object & x ) {
    DLLNode * tmp;
    try{
        tmp = new DLLNode(x, mpHead->mpNext, mpHead);
    }catch (const std::bad_alloc & e){
        throw e;
    }
    mpHead->mpNext = tmp;
    tmp->mpNext->mpBefore = tmp;

    miSize++;
}

template<class Object>
void List<Object>::pop_front() {
    if( empty() )
        throw std::out_of_range("[pop_front]: The list is empty, there are no elements in the \"front\"");
    
    DLLNode * work = mpHead->mpNext;
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

/** Métodos com iteradores: */


template<class Object>
typename List<Object>::iterator List<Object>::insert(
    typename List<Object>::iterator pos, const Object & _x ){
    
    DLLNode * work;
    
    try{
        work = new DLLNode( _x, pos.current, pos.current->mpBefore );
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

*/

template <class Object>
typename List<Object>::iterator List<Object>::insert(
    typename List<Object>::const_iterator pos, std::initializer_list<Object> ilist ){
    
    DLLNode * work;

    for ( auto element : ilist ){
        
        try{
            work = new DLLNode( element, pos.current, pos.current->mpBefore );
        }catch( const std::bad_alloc & e ){
            throw e;
        }
        
        work->mpNext->mpBefore = work;
        work->mpBefore->mpNext = work;
        
        miSize++;
        
    }
    
    return iterator( work );

}



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

template <class Object>
typename List<Object>::iterator List<Object>::erase(
    typename List<Object>::iterator first, typename List<Object>::iterator last ){
    
    DLLNode * work;
    
    while( first != last ){
        work = first.current;
        first++;
        
        work->mpNext->mpBefore = work->mpBefore;
        work->mpBefore->mpNext = work->mpNext;

        work->miData.~Object();
        delete work;
        
        miSize--;
    }
    
    return first;
}

/*

template <class Object>
template <typename InItr>
void List<Object>::assign( InItr first, InItr last ){

}

template <class Object>
void List<Object>::assign( std::initializer_list<T> ilist ){

}

*/


/** Operadores dos iteradores: */

template<class Object>
const Object & List<Object>::const_iterator::operator*() const{
    return current->miData;
}

template<class Object>
typename List<Object>::const_iterator & List<Object>::const_iterator::operator++(){
    current = current->mpNext;
    
    return *this;
}

template<class Object>
typename List<Object>::const_iterator List<Object>::const_iterator::operator++( int ){
    const_iterator ret( current );
    current = current->mpNext;
    
    return ret;
}

template<class Object>
typename List<Object>::const_iterator & List<Object>::const_iterator::operator--(){
    current = current->mpBefore;
    
    return *this;
}

template<class Object>
typename List<Object>::const_iterator List<Object>::const_iterator::operator--( int ){
    const_iterator ret( current );
    current = current->mpBefore;
    
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
