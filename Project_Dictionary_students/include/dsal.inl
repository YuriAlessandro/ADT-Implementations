template < typename Key, typename Data, typename KeyComparator >
int DSAL<Key,Data,KeyComparator>::_search ( const Key & _x ) const
{
	int l = 0;
	int r = DAL< Key, Data, KeyComparator >::mi_Length-1;
	int m;

	while( l <= r ) {
	    m = ( l + r )/2;

	    if( DAL< Key, Data, KeyComparator >::compare( DAL< Key, Data, KeyComparator >::mpt_Data[m].id, _x ) == 0 ) return m;

	    if( DAL< Key, Data, KeyComparator >::compare( DAL< Key, Data, KeyComparator >::mpt_Data[m].id, _x ) == -1 )   l = m + 1;
	    else r = m - 1;
	}

	return DAL< Key, Data, KeyComparator >::mi_Length;
}

template < typename Key, typename Data, typename KeyComparator >
bool DSAL<Key,Data,KeyComparator>::remove ( const Key & _x , Data & _result )
{
	int pos = this->_search( _x );

	if ( pos == DAL< Key, Data, KeyComparator >::mi_Length )		//Não achou
		return false;

	_result = DAL< Key, Data, KeyComparator >::mpt_Data[pos].info;

	for ( auto i = pos; i < DAL< Key, Data, KeyComparator >::mi_Length-1; i++ )
		DAL< Key, Data, KeyComparator >::mpt_Data[ i ] = DAL< Key, Data, KeyComparator >::mpt_Data[ i+1 ];

	DAL< Key, Data, KeyComparator >::mi_Length--;

	return true;
}

template < typename Key, typename Data, typename KeyComparator >
bool DSAL<Key,Data,KeyComparator>::insert ( const Key & _novaId , const Data & _novaInfo )
{

	int pos = this->_search( _novaId );

	if ( pos < DAL< Key, Data, KeyComparator >::mi_Length )		//Existe repetido
		return false;

	if ( DAL< Key, Data, KeyComparator >::mi_Length == DAL< Key, Data, KeyComparator >::mi_Capacity )
		throw std::length_error( "[DAL::insert()]: Tamanho limite atingido" );


	int l = 0, r = DAL< Key, Data, KeyComparator >::mi_Length-1, m;

	while ( l <= r ){
	    m = ( l + r )/2;

	    if( DAL< Key, Data, KeyComparator >::compare( DAL< Key, Data, KeyComparator >::mpt_Data[m].id, _novaId ) == -1 ) l = m + 1;
	    else{
	    	pos = m;
	    	r = m - 1;
	    }
	}

	for ( int i = DAL< Key, Data, KeyComparator >::mi_Length; i > pos; i-- )
		DAL< Key, Data, KeyComparator >::mpt_Data[ i ] = DAL< Key, Data, KeyComparator >::mpt_Data[ i - 1 ];

	DAL< Key, Data, KeyComparator >::mpt_Data[ pos ].id = _novaId;
	DAL< Key, Data, KeyComparator >::mpt_Data[ pos ].info = _novaInfo;
	DAL< Key, Data, KeyComparator >::mi_Length++;

	return true;

}

template < typename Key, typename Data, typename KeyComparator >
Key DSAL<Key,Data,KeyComparator>::min ( ) const // Recupera a menor chave do dicionário.
{
	return DAL< Key, Data, KeyComparator >::mpt_Data[ 0 ].id;
}

template < typename Key, typename Data, typename KeyComparator >
Key DSAL<Key,Data,KeyComparator>::max ( ) const // Recupera a maior chave do dicionário.
{
	return DAL< Key, Data, KeyComparator >::mpt_Data[ DAL< Key, Data, KeyComparator >::mi_Length-1 ].id;
}

// Recupera em _y a chave sucessora a _x , se existir ( true ).
template < typename Key, typename Data, typename KeyComparator >
bool DSAL<Key,Data,KeyComparator>::sucessor( const Key & _x, Key & _y ) const{
	int pos = _search( _x );

	if ( pos < DAL< Key, Data, KeyComparator >::mi_Length - 1 ){
		_y = DAL< Key, Data, KeyComparator >::mpt_Data[ pos + 1 ].id;
		return true;
	}

	else return false;

}

// Recupera em _y a chave antecessora a _x , se existir ( true ).
template < typename Key, typename Data, typename KeyComparator >
bool DSAL<Key,Data,KeyComparator>::predecessor( const Key & _x, Key & _y ) const{
	int pos = _search( _x );

	if ( pos == 0 ) return false;

	_y = DAL< Key, Data, KeyComparator >::mpt_Data[ pos - 1 ].id;

	return true;
}
