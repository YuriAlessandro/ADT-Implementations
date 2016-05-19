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

// O retorno está diferente aqui.
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

// Funções exclusivas à implementação de listas encadeadas
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

typename ForwardList<Object>::iterator ForwardList<Object>::insert_after(
    typename ForwardList<Object>::const_iterator itr, const Object & _x ){
        // itr.current =~ mpHead + ?
        SLLNode * work;
        try{
            work = new SLLNode( _x, itr.current->mpNext );
        }catch( const bad_alloc & e ){
            throw e;
        }

        itr->mpNext = work;

        return iterator( work );
}

/*
typename ForwardList<Object>::iterator ForwardList<Object>::insert_after(
    typename ForwardList<Object>::const_iterator pos, std::initializer_list<Object> ilist ){

}

typename ForwardList<Object>::iterator ForwardList<Object>::erase_after(
    typename ForwardList<Object>::const_iterator itr ){

}

typename ForwardList<Object>::iterator ForwardList<Object>::erase_after(
    typename ForwardList<Object>::const_iterator first, typename ForwardList<Object>::const_iterator last ){

}

typename ForwardList<Object>::const_iterator ForwardList<Object>::find(const Object & _x )const{

}
*/
