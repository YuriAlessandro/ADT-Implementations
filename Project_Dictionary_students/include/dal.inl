/**
 * DAL class implementation.
 *
 */

#include "dal.h"

/////////// Private ////////////////

template < typename Key, typename Data, typename KeyComparator >
int DAL<Key,Data,KeyComparator>::compare( const Key & _x, const Key & _y ) const {
	KeyComparator comparator;
	return comparator( _x, _y );
}


template < typename Key, typename Data, typename KeyComparator >
int DAL<Key,Data,KeyComparator>::_search( const Key & _x ) const
{
	auto i(0);
	for ( /* Empty */ ; i < mi_Length && compare( mpt_Data[i].id, _x ) != 0; i++ );

	return i;
}

/////////// Public /////////////////

/**
 * ---------------------------------------------------------------------------
 * Common methods from DAL.
 * ---------------------------------------------------------------------------
 */

template < typename Key, typename Data, typename KeyComparator >
bool DAL<Key,Data,KeyComparator>::remove( const Key & _x, Data & _result )
{
	int pos = this->_search( _x );

	if ( pos == mi_Length )		//Não achou
		return false;
	
	_result = mpt_Data[ pos ].info;

	mpt_Data[ pos ] = mpt_Data[ --mi_Length ];
	
	return true;
}

template < typename Key, typename Data, typename KeyComparator >
bool DAL<Key,Data,KeyComparator>::search( const Key & _x, Data & _result ) const
{
	int pos = this->_search( _x );

	if ( pos == mi_Length )		//Não achou
		return false;
	
	_result = mpt_Data[ pos ].info;
	return true;
}

template < typename Key, typename Data, typename KeyComparator >
bool DAL<Key,Data,KeyComparator>::insert( const Key & _novaId, const Data & _novaInfo )
{
	int pos = this->_search( _novaId );

	if ( pos < mi_Length )		//Existe repetido
		return false;

	if ( mi_Length == mi_Capacity )
		throw std::length_error( "[DAL::insert()]: Tamanho limite atingido" );

	mpt_Data[ mi_Length ].id = _novaId;
	mpt_Data[ mi_Length ].info = _novaInfo;
	mi_Length++;

	return true;
}

// Assume que existe ao menos um elemento no dicionário
template < typename Key, typename Data, typename KeyComparator >
Key DAL<Key,Data,KeyComparator>::min( void )
{
	Key min = mpt_Data[ 0 ].id;
	for ( int i = 0; i < mi_Length; i++ )
		min = ( compare( min, mpt_Data[i].id ) == 1 ) ? mpt_Data[i].id : min;

	return min;
}

// Assume que existe ao menos um elemento no dicionário
template < typename Key, typename Data, typename KeyComparator >
Key DAL<Key,Data,KeyComparator>::max( void )
{
	Key max = mpt_Data[ 0 ].id;
	for ( int i = 0; i < mi_Length; i++ )
		max = ( compare( max, mpt_Data[i].id ) == -1 ) ? mpt_Data[i].id : max;

	return max;
}

template < typename Key, typename Data, typename KeyComparator >
bool DAL<Key,Data,KeyComparator>::sucessor( const Key & _x, Key & _y ){
	Key highest = this->max();

	// Retorna falso se _x não está na lista ou se já é o maior
	if ( compare( _x, highest ) == 0 ) return false;

	for (int i = 0; i < mi_Length; i++)
		if ( compare( _x, mpt_Data[ i ].id ) == -1 && compare( mpt_Data[ i ].id, highest ) == -1 )
			highest = mpt_Data[ i ].id;

	_y = highest;

	return true;
}

template < typename Key, typename Data, typename KeyComparator >
bool DAL<Key,Data,KeyComparator>::predecessor( const Key & _x, Key & _y ){
	Key lowest = this->min();

	// Retorna falso se _x não está na lista ou se já é o menor
	if ( compare( _x, lowest ) == 0 ) return false;

	for (int i = 0; i < mi_Length; i++)
		if ( compare( _x, mpt_Data[ i ].id ) == 1 && compare( mpt_Data[ i ].id, lowest ) == 1 )
			lowest = mpt_Data[ i ].id;

	_y = lowest;

	return true;
}

// Construtor inicializa TAD.
template < typename Key, typename Data, typename KeyComparator >
DAL<Key,Data,KeyComparator>::DAL ( int _iMaxSz ) :
    mi_Length( 0 ),         // Tamanho logico.
    mi_Capacity( _iMaxSz ), // Guardar capacidade atual.
    mpt_Data( nullptr )
{
    if ( _iMaxSz < 0 )          // Nao aceitamos lista com tamanho negativo.
        throw std::invalid_argument( "[DAL()]: Tamanho de lista invalido!" );
    mpt_Data = new NodeAL[ _iMaxSz ]; // Tamanho maximo.
}
