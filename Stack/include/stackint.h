#ifndef _STACKINT_H_
#define _STACKINT_H_

#include <stdexcept>

class StackInt{
private:
	int *m_stack;
	int m_top;
	int m_capacity;

	void resize( const int & );

public:

	StackInt( int _size = 10 ){
		// A capacidade fica como 1 caso o usuário insira um número menor que 0
        m_capacity = ( _size > 0 ) ? _size : 1;

		m_stack = new int[ m_capacity ];
		m_top = 0;
	}

	~StackInt(){
		delete[] m_stack;
	}

	StackInt( const StackInt & ) = delete;

	void push( const int & );
	int pop();
	int top();

	bool isEmpty() const;
	void makeEmpty();
};

#endif
