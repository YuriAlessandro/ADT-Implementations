// This is a stub code (or skeleton code) just to allow the first compilation.

#include <iostream>
#include "les_v1.h"

using namespace std;

//! Prints the list.
/*! This a debugging function that prints the list content.
 *  @param _pAIL Pointer to the head of the list. It NULL, list is empty.
 */
void print( SNPtr _pAIL )
{
    std::cout << ">>>> Current list:\n[ ";

    while ( _pAIL != nullptr ){
        std::cout << _pAIL->miData << " ";
        _pAIL = _pAIL->mpNext;
    }

    std::cout << "]\n";
}

//! Length of the list.
/*! Calculates and return the length of the list. Length is zero, if list is empty.
 *  @param _pAIL Pointer to the head of the list. It NULL, list is empty.
 *  @return The length.
 */
int length( SNPtr _pAIL )
{
    int _ret = 0;
    for ( /* Empty */; _pAIL != nullptr; _pAIL = _pAIL->mpNext, _ret++ );

    return _ret;
}


bool empty( SNPtr _pAIL )
{
    // Nullptr == 0
    return !( _pAIL );
}


void clear( SNPtr & _pAIL )
{
    if ( !empty( _pAIL ) ){
        SNPtr work;
        while ( _pAIL != nullptr ){
            work = _pAIL->mpNext;
            delete _pAIL;
            _pAIL = work;
        }
    }
}


bool front( SNPtr _pAIL, int & _retrievedVal )
{
    if ( empty( _pAIL ) ) return false;

    _retrievedVal = _pAIL->miData;
    return true;
}


bool back( SNPtr _pAIL, int & _retrievedVal )
{
    if ( empty( _pAIL ) ) return false;

    while ( _pAIL->mpNext != nullptr )
        _pAIL = _pAIL->mpNext;

    _retrievedVal = _pAIL->miData;
    return true;
}


bool pushFront( SNPtr & _pAIL, int _newVal )
{
    SNPtr _temp;

    try{
        _temp = new SLLNode;
    }catch( const std::bad_alloc & e ){
        return false;
    }

    _temp->miData = _newVal;
    _temp->mpNext = _pAIL;

    _pAIL = _temp;
    return true;
}


bool pushBack( SNPtr & _pAIL, int _newVal )
{
    SNPtr _newNode;

    try{
        _newNode = new SLLNode;
    }catch( const std::bad_alloc & e ){
        return false;
    }

    _newNode->miData = _newVal;
    _newNode->mpNext = nullptr;

    // Caso Especial
    if ( _pAIL == nullptr ){
        _pAIL = _newNode;
        return true;
    }

    SNPtr tail = _pAIL;
    while ( tail->mpNext != nullptr )
        tail = tail->mpNext;

    tail->mpNext = _newNode;

    return true;
}


bool popFront( SNPtr & _pAIL, int & _retrievedVal )
{
    if ( empty( _pAIL ) ) return false;

    _retrievedVal = _pAIL->miData;
    SNPtr temp = _pAIL->mpNext;

    delete _pAIL;
    _pAIL = temp;

    return true;
}


bool popBack( SNPtr & _pAIL, int & _retrievedVal )
{
    if ( empty( _pAIL ) ) return false;

    SNPtr tail = _pAIL;
    SNPtr work = nullptr;   // Vai pontar para o elemento antes do tail

    while ( tail->mpNext != nullptr ){
        work = tail;
        tail = tail->mpNext;
    }

    _retrievedVal = tail->miData;
    delete tail;

    if ( work == nullptr )  // work não mudou, logo só havia um elemento
        _pAIL = nullptr;
    else                    // work mudou, então só precisa mudar o penúltimo
        work->mpNext = nullptr;

    return true;
}

// Retorna um ponteiro para o elemento antes do procurado
// Retorna nullptr caso esteja vazia a resposta seja o primeiro elemento
// Retorna o último da lista caso não encontre
SNPtr find( SNPtr _pAIL, int _targetVal )
{
    if( empty( _pAIL ) || _pAIL->miData == _targetVal )
        return nullptr;

    // Short-cutting garante que não haverá erros
    while ( _pAIL->mpNext != nullptr && (_pAIL->mpNext)->miData != _targetVal )
        _pAIL = _pAIL->mpNext;

    return _pAIL;
}

bool insert( SNPtr & _pAIL, SNPtr _pAnte, int _newVal )
{

    /* A linha abaixo pode ser usada para reduzir o tamanho da função,
    * tornando-a, porém, dependente de outra função.

    if ( _pAnte == nullptr ) return pushFront( _pAIL, _newVal);
    */

    // Cria o novo node
    SNPtr _newNode;

    try{
        _newNode = new SLLNode;
    }catch( const std::bad_alloc & e ){
        return false;
    }

    _newNode->miData = _newVal;

    // Se _pAnte é vazio, insere no inicio da lista
    if ( _pAnte == nullptr ) {
        _newNode->mpNext = _pAIL;
        _pAIL = _newNode;
    }else{
    // Se não, coloca após o node apontado por _pAnte
        _newNode->mpNext = _pAnte->mpNext;
        _pAnte->mpNext = _newNode;
    }

    return true;
}


bool remove( SNPtr & _pAIL, SNPtr _pAnte, int & _retrievedVal )
{
    /* A linha abaixo pode ser usada para reduzir o tamanho da função,
    * tornando-a, porém, dependente de outra função.

    if ( _pAnte == nullptr ) return popFront( _pAIL, _retrievedVal );
    */

    if ( empty( _pAIL ) ) return false;

    if ( _pAnte == nullptr ){
        _retrievedVal = _pAIL->miData;
        SNPtr temp = _pAIL->mpNext;

        delete _pAIL;
        _pAIL = temp;

    }else{
        _retrievedVal = _pAnte->miData;
        SNPtr temp = (_pAnte->mpNext)->mpNext;

        delete (_pAnte->mpNext);
        _pAnte->mpNext = temp;
    }

    return true;
}

// Inverte os elementos da lista pelo conteúdo
bool reverseContent( SNPtr _pAIL ){

    if ( empty( _pAIL ) )
        return false;

    SNPtr tail = nullptr;
    SNPtr work;

    while ( _pAIL != tail && _pAIL->mpNext != tail )
    {
        work = _pAIL;

        while ( (work->mpNext)->mpNext != tail )
            work = work->mpNext;

        tail = work->mpNext;

        std::swap( _pAIL->miData, tail->miData );

        _pAIL = _pAIL->mpNext;
    }

    return true;
}

// Inverte a lista trocando a direção dos ponteiros
bool reverse( SNPtr & _pAIL ){

    if ( empty( _pAIL ) ) return false;

    SNPtr afterMid = _pAIL->mpNext;
    SNPtr beforeMid = nullptr;

    while ( afterMid != nullptr )
    {
        _pAIL->mpNext = beforeMid;

        beforeMid = _pAIL;
        _pAIL = afterMid;
        afterMid = afterMid->mpNext;
    }

    _pAIL->mpNext = beforeMid;

    return true;
}


//**** ===================[ End of les_v1.cpp ]=================== ****//
