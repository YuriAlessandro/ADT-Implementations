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
    mpHead = nullptr;
}

template<class Object>
ForwardList<Object>::~ForwardList(){
    clear();
}

template<class Object>
size_type ForwardList<Object>::size() const{
    SLLNode * work = mpHead;
    size_type l = 0;
    while ( work != nullptr){
        l++;
        work = work->mpNext;
    }
    return l;
}

// Clear tem que dar ~Object()
template<class Object>
void ForwardList<Object>::clear(){
    if( mpHead != nullptr){
        SLLNode * work;
        while ( mpHead != nullptr){
            mpHead->miData.~Object();

            work = mpHead->mpNext;
            delete mpHead;
            mpHead = work;
        }
    }
}

template<class Object>
bool ForwardList<Object>::empty(){
    return ( mpHead == nullptr );
}

template<class Object>
void ForwardList<Object>::push_back( const Object & _x ){
    if ( mpHead == nullptr ) push_front( _x );
    else{
        SLLNode * tmp;
        try{
            tmp = new SLLNode;
        }catch(const std::bad_alloc & e){
            throw e;
        }
        tmp->miData = _x;
        tmp->mpNext = nullptr;

        SLLNode * tail = mpHead;

        while( tail->mpNext != nullptr )
            tail = tail->mpNext;

        tail->mpNext = tmp;
    }
}

// Tem que dar ~Object()
template<class Object>
void ForwardList<Object>::pop_back(){
    if( mpHead == nullptr ){
        throw std::out_of_range("Não tem nada pra popbackar aqui.");
    }else{
        SLLNode * work = nullptr;
        SLLNode * tail = mpHead;

        while( tail->mpNext != nullptr ){
            work = work->mpNext;
            tail = tail->mpNext;
        }

        tail->miData.~Object();
        delete tail;

        if ( work == nullptr )  // work não mudou, logo só havia um elemento
            mpHead = nullptr;
        else                    // work mudou, então só precisa mudar o penúltimo
            work->mpNext = nullptr;

    }
}

// O retorno está diferente aqui.
template<class Object>
const Object & ForwardList<Object>::back() const{
    SLLNode * tail;

    if ( tail == nullptr )
        throw std::out_of_range("Nem sei se é esse erro");

    while( tail->mpNext != nullptr )
        tail = tail->mpNext;

    return tail->miData;
}

template<class Object>
void ForwardList<Object>::assign( const Object & x ){

}

// Funções exclusivas à implementação de listas encadeadas
template<class Object>
void ForwardList<Object>::push_front( const Object & _x ){
    SLLNode * work = nullptr;
    try{
        work = new SLLNode;
    }catch (const std::bad_alloc & e){
        throw e;
    }
    work->miData = _x;
    work->mpNext = mpHead;
    mpHead = work;
}

// Destroy ~Object()
template<class Object>
void ForwardList<Object>::pop_front(){
    if( mpHead == nullptr )
        throw std::out_of_range("Nao sei se é esse erro");

	SLLNode * work = mpHead->mpNext;

    mpHead->miData.~Object();
    delete mpHead;

    mpHead = work;
}
