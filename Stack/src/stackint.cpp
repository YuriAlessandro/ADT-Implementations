#include "stackint.h"

//Somente aumenta, não diminui
void StackInt::resize( const int & _newSize ){

	int *_newStack = new int[ _newSize ];

	for ( auto i = 0; i < m_top; i++ )
		_newStack[ i ] = m_stack[ i ];

	delete[] m_stack;

	m_stack =_newStack;

	m_capacity = _newSize;
}

void StackInt::push( const int & _new ){
	if ( m_top == m_capacity )
		this->resize( 2 * m_capacity );

	m_stack[ m_top++ ] = _new;
}

int StackInt::pop(){
	if ( isEmpty() )
		throw std::out_of_range ("[pop()]: Sem elementos no stack");

	return m_stack[ --m_top ];
}

int StackInt::top(){
	return m_stack[ m_top-1 ];
}

bool StackInt::isEmpty() const{
	return ( m_top == 0 );
}

void StackInt::makeEmpty(){
	m_top = 0;

}
