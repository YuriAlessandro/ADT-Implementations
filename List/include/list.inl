#include <iostream>
#include <stdexcept>

template<class Object>
List<Object>::List(){
    mpHead = new SLLNode();
    mpTail = new SLLNode();

    mpHead->mpNext = mpTail;
    mpTail->mpBefore = mpHead;

    //TA DANDO FORA DO ESCOPO
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

// ITERADORES, precisa arrumar o "CHAMA" deles
template<class Object>
const Object & operator*() const{

}

template<class Object>
const_iterator & operator++(){

}

template<class Object>
const_iterator operator++( int ){

}

template<class Object>
const_iterator & operator--(){

}

template<class Object>
const_iterator operator --( int ){

}

template<class Object>
bool operator==( const const_iterator & rhs ) const{

}

template<class Object>
bool operator!=( const const_iterator & rhs ) const{

}

/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////

/*
template<class Object>
typename ForwardList<Object>::iterator ForwardList<Object>::insert(
    typename ForwardList<Object>::iterator pos, const Object & _x ){
    
}

template <class Object>
template <typename InItr>
typename ForwardList<Object>::iterator ForwardList<Object>::insert(
    typename ForwardList<Object>::iterator pos, InItr first, InItr last ){

}

template <class Object>
typename ForwardList<Object>::iterator ForwardList<Object>::insert(
    typename ForwardList<Object>::const_iterator pos, std::initializer_list<T> ilist ){

}

template <class Object>
typename ForwardList<Object>::iterator ForwardList<Object>::erase(
    typename ForwardList<Object>::iterator pos ){

}

template <class Object>
typename ForwardList<Object>::iterator ForwardList<Object>::erase(
    typename ForwardList<Object>::iterator first, typename ForwardList<Object>::iterator last ){

}

template <class Object>
template <typename InItr>
void ForwardList<Object>::assign( InItr first, InItr last ){

}

template <class Object>
void ForwardList<Object>::assign( std::initializer_list<T> ilist ){

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
*/
