/*!
 *  @mainpage Vector
 *  @author Gustavo Araújo e Yuri Alessandro Martins
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *  @version 1.0
 *
 *  @file ForwardList.inl
 *  @brief Implementations File
 *
 *  File with the Forward List implementations
 */

template<class Object>
ForwardList<Object>::ForwardList(){
    mpTail = new SLLNode( Object(), nullptr );
    mpHead = new SLLNode( Object(), mpTail );
    miSize = 0;
}

template<class Object>
ForwardList<Object>::~ForwardList(){
    clear();
    delete mpHead;
    delete mpTail;
}

template<class Object>
size_type ForwardList<Object>::size() const{
    return miSize;
}

template<class Object>
void ForwardList<Object>::clear(){
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
bool ForwardList<Object>::empty() const{
    return ( mpHead->mpNext == mpTail );
}

template<class Object>
void ForwardList<Object>::push_back( const Object & _x ){
    SLLNode * tmp;

    try{
        tmp = new SLLNode( _x, mpTail );
    }catch(const std::bad_alloc & e){
        throw e;
    }

    SLLNode * _tail = mpHead;

    while( _tail->mpNext != mpTail )
        _tail = _tail->mpNext;

    _tail->mpNext = tmp;

    miSize++;
}

// Tem que dar ~Object()
template<class Object>
void ForwardList<Object>::pop_back(){
    if( empty() )
        throw std::out_of_range("Não tem nada pra popbackar aqui.");
    else{
        SLLNode * work = mpHead;
        SLLNode * _tail = mpHead->mpNext;

        while( _tail->mpNext != mpTail ){
            work = work->mpNext;
            _tail = _tail->mpNext;
        }

        _tail->miData.~Object();
        delete _tail;
        work->mpNext = mpTail;
    }

    miSize--;
}

template<class Object>
const Object & ForwardList<Object>::front() const{
    if ( empty() ){
        throw std::out_of_range("[front]: Nem sei se é esse erro");
    }
    return mpHead->mpNext->miData;
}

template<class Object>
const Object & ForwardList<Object>::back() const{
    if ( empty() )
        throw std::out_of_range("Nem sei se é esse erro");

    SLLNode * _tail = mpHead->mpNext;

    while( _tail->mpNext != mpTail )
        _tail = _tail->mpNext;

    return _tail->miData;
}

template<class Object>
void ForwardList<Object>::assign( const Object & _x ){
    SLLNode * work = mpHead->mpNext;
    while( work != mpTail ){
        work->miData.~Object();
        work->miData = _x;
        work = work->mpNext;
    }
}

template<class Object>
void ForwardList<Object>::push_front( const Object & _x ){
    SLLNode * work = nullptr;

    try{
        work = new SLLNode( _x, mpHead->mpNext );
    }catch (const std::bad_alloc & e){
        throw e;
    }

    mpHead->mpNext = work;

    miSize++;
}

template<class Object>
void ForwardList<Object>::pop_front(){
    if( empty() )
        throw std::out_of_range("[pop_front]: Nothing to pop here, sir.");
    else{
    	SLLNode * work = mpHead->mpNext->mpNext;

        mpHead->mpNext->miData.~Object();
        delete mpHead->mpNext;

        mpHead->mpNext = work;
    }

    miSize--;
}

template<class Object>
typename ForwardList<Object>::iterator ForwardList<Object>::before_begin( ){
    return iterator( mpHead );
}

template<class Object>
typename ForwardList<Object>::const_iterator ForwardList<Object>::cbefore_begin( ) const{
    return const_iterator( mpHead );
}

template<class Object>
typename ForwardList<Object>::iterator ForwardList<Object>::begin( ){
    return iterator( mpHead->mpNext );
}

template<class Object>
typename ForwardList<Object>::const_iterator ForwardList<Object>::cbegin( ) const{
    return const_iterator( mpHead->mpNext );
}

template<class Object>
typename ForwardList<Object>::iterator ForwardList<Object>::end( ){
    return iterator( mpTail );
}

template<class Object>
typename ForwardList<Object>::const_iterator ForwardList<Object>::cend( ) const{
    return const_iterator( mpTail );
}

////////////////////////
////////////////////////
////////////////////////

template<class Object>
typename ForwardList<Object>::iterator ForwardList<Object>::insert_after(
    typename ForwardList<Object>::const_iterator itr, const Object & _x ){
        // itr.current =~ mpHead + ?
        SLLNode * work;
        try{
            work = new SLLNode( _x, itr.current->mpNext );
        }catch( const std::bad_alloc & e ){
            throw e;
        }

        itr.current->mpNext = work;
        
        miSize++;
        
        return iterator( work );
}

template<class Object>
typename ForwardList<Object>::iterator ForwardList<Object>::insert_after(
    typename ForwardList<Object>::const_iterator pos, std::initializer_list<Object> ilist ){
    
    SLLNode * work;

    for ( auto element : ilist ) {
        
        try{
            work = new SLLNode( element, pos.current->mpNext );
        }catch( const std::bad_alloc & e ){
            throw e;
        }
        
        pos.current->mpNext = work;
        pos.current = work;
        
        miSize++;
        
    }
    
    return iterator( work );
}

template<class Object>
typename ForwardList<Object>::iterator ForwardList<Object>::erase_after(
    typename ForwardList<Object>::const_iterator itr ){
    
    SLLNode * work = itr.current->mpNext;
    itr.current->mpNext = work->mpNext;
    work->miData.~Object();
    delete work;
    
    miSize--;
    
    return iterator( itr.current->mpNext );
}

template<class Object>
typename ForwardList<Object>::iterator ForwardList<Object>::erase_after(
    typename ForwardList<Object>::const_iterator first, typename ForwardList<Object>::const_iterator last ){
    
    SLLNode * work;
    
    while( first.current->mpNext != last.current ){
        work = first.current->mpNext;

        first.current->mpNext = work->mpNext;
        
        work->miData.~Object();
        delete work;
        
        miSize--;
    }

    return iterator( last.current );
}

template<class Object>
typename ForwardList<Object>::const_iterator ForwardList<Object>::find(const Object & _x )const{
    
    const_iterator work = cbegin();
    
    while( work.current->mpNext->miData != _x and work != mpTail )
        work++;
        
    return work;
}

////////////////
// ITERADORES //
////////////////

template<class Object>
const Object & ForwardList<Object>::const_iterator::operator*() const{
    return current->miData;
}

// Tratamento de erro necessário?
template<class Object>
typename ForwardList<Object>::const_iterator & ForwardList<Object>::const_iterator::operator++(){
    current = current->mpNext;
    return *this;
}

template<class Object>
typename ForwardList<Object>::const_iterator ForwardList<Object>::const_iterator::operator++( int ){
    const_iterator ret( current );
    current = current->mpNext;
    return ret;
}

template<class Object>
bool ForwardList<Object>::const_iterator::operator==( const typename ForwardList<Object>::const_iterator & rhs ) const{
    return ( current == rhs.current );
}

template<class Object>
bool ForwardList<Object>::const_iterator::operator!=( const typename ForwardList<Object>::const_iterator & rhs ) const{
    return ( current != rhs.current );
}

template<class Object>
const Object & ForwardList<Object>::iterator::operator*() const{
    return const_iterator::current->miData;
}

template<class Object>
Object & ForwardList<Object>::iterator::operator*(){
    return const_iterator::current->miData;
}

template<class Object>
typename ForwardList<Object>::iterator & ForwardList<Object>::iterator::operator++(){
    iterator::current = iterator::current->mpNext;
    return *this;
}

template<class Object>
typename ForwardList<Object>::iterator ForwardList<Object>::iterator::operator++( int ){
    iterator ret( const_iterator::current );
    const_iterator::current = const_iterator::current->mpNext;
    return ret;
}