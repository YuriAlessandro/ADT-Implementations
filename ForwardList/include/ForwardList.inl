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
 
#include <iostream>
#include <exception>

ForwardList();
~ForwardList();

template<class Object>
size_type ForwardList<Object>::size() const{
    size_type l = 0;
    while (_pAIL != nullptr){
        l++;
        _pAIL = _pAIL->mpNext;
    }
    return l;
}

// Clear tem que dar ~Object()
template<class Object>
void ForwardList<Object>::clear(){ 
    if( mp != nullptr){
        SLLNode * work;
        while ( _pAIL != nullptr){
            work = _pAIL->mpNext;
            delete _pAIL;
            _pAIL = work; 
        }
    }
}

template<class Object>
bool ForwardList<Object>::empty(){ 
    return ( _pAIL == nullptr );
}

template<class Object>
void ForwardList<Object>::push_back( const T & x ){ 
    if ( _pAIL == nullptr ) pushFront( _pAIL, _newVal );
    else{
        SLLNode * tmp = nullptr;
        try{
            tmp = new SLLNode;
        }catch(const std::bad_alloc & e){
            return false;
        }
        tmp->miData = _newVal;
        tmp->mpNext = nullptr;
        
        SLLNode * work = _pAIL;
    
        while( work->mpNext != nullptr )
            work = work->mpNext;
        work->mpNext = tmp;
    }
    return true;
}

// Tem que dar ~Object()
template<class Object>
void ForwardList<Object>::pop_back(){ 
    SLLNode * _pAIL = mpHead;
    if( _pAIL != NULL ){
        SLLNode * work = _pAIL;
        SLLNode * tail = _pAIL->mpNext;
        while( tail->mpNext != NULL ){
            work = work->mpNext;
        	tail = tail->mpNext;
        }
        delete tail;
        work->mpNext = NULL;
    }
}

template<class Object>
const Object & ForwardList<Object>::back() const{ 
    SLLNode * _pAIL;
    
    if (_pAIL == nullptr )
        throw std::out_of_bounds("Nem sei se é esse erro");
    
    while( _pAIL->mpNext != nullptr ){
        _pAIL = _pAIL->mpNext;
    }
    
    return _pAIL->miData;
}

template<class Object>
void ForwardList<Object>::assign( const Object & x ){ 
    
}

// Funções exclusivas à implementação de listas encadeadas
void ForwardList<Object>::push_front( const Object & x ){ 
    SLLNode * work = nullptr;
    try{
        work = new SLLNode;
    }catch (const std::bad_alloc & e){
        throw std::bad_alloc("Moisés");
    }
    work->miData = x;
    work->mpNext = _pAIL;
    _pAIL = work;
}

// Destroy ~Object()
void ForwardList<Object>::pop_front(){ 
    if( _pAIL == nullptr )
        throw std::out_of_bounds("Nao sei se é esse erro");
    
	SLLNode * work = mpHead->mpNext;
	delete mpHead;
	mpHead = work;
    
}