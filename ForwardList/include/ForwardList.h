/*!
 *  \mainpage ForwardList
 *  \author Gustavo Araújo e Yuri Alessandro Martins
 *  \copyright Copyright &copy; 2016. All rights reserved.
 *  \version 1.0
 *
 *  \file ForwardList.h
 *  \brief Header file
 *
 *  File with the Forward List header
 */

#ifndef _FORWARDLIST_H_
#define _FORWARDLIST_H_

#include <iostream>
#include <stdexcept>

using size_type = int;

/**
 * \brief Classe da Lista Simples.
 */
template <class Object>
class ForwardList {
private:
    struct SLLNode {
        Object miData;      /**< Armazena a informação do nó. */
        SLLNode * mpNext;   /**< Armazena o endereço do próximo nó. */

        SLLNode( const Object & d = Object(), SLLNode * n = nullptr )
        : miData( d ), mpNext( n )
        { /* Empty */ }
    };                  /**< Nó de ponteiros. */

    SLLNode * mpHead;   /**< Nó cabeça da lista. */
    SLLNode * mpTail;   /**< Nó rabo da lista. */
    size_type miSize;   /**< Tamanho da lista. */

public:
    /**
     * \brief Construtor da lista.
     */
    ForwardList();
    
    /**
     * \brief Construtor cópia do ForwardList.
     * \param _vec Lista para onde será copiado.
     */
    ForwardList( const ForwardList & _vec );
    
    /**
     * \brief Construtor "move" do ForwardList
     * \param Lista onde o move será aplicado.
     */
    ForwardList( ForwardList && _vec );
    /**
     * \brief Sobrecarga do operador de atribuição por cópia.
     * \param _vec Lista de onde será copiado.
     * \return O próprio Lista que chamou o operador.
     */
    ForwardList & operator= ( const ForwardList & _vec );
    
    /**
     * \brief Sobrecarga do operador de atribuição por "move".
     * \param _vec Lista de onde será feito o "move".
     * \return O próprio Lista que chamou o operador.
     */
    ForwardList & operator= ( ForwardList && _vec );
    /**
     * \brief Destrutor da lista.
     */
    ~ForwardList();

    /**
     * \brief Classe que cria iteradores constantes.
     */
    class const_iterator{
    public:
        /**
         * \brief Contrutor da classe de iteradores constante.
         */
        const_iterator( ) {/* EMPTY */}
        /**
         * \brief Sobrecarga do operador de referenciamento.
         * \return O próprio objeto.
         */
        const Object & operator*() const;
        /**
         * \brief Sobrecarga do operador de incremento.
         * \return Retorna o valor após o incremento.
         */
        const_iterator & operator++();
        /**
         * \brief Sobrecarga do operador de incremento.
         * \return Retorna o valor antes do incremento.
         */
        const_iterator operator++( int );
        
        /*
        const_iterator & operator--();
        const_iterator operator --( int );
        */
        
        /**
         * \brief Sobrecarga de operador de igualidade.
         * \param rhs Objeto que deverá ser comparado com quem chamou o método.
         * \return True, se existe igualidade entre os membros, False, se não.
         */
        bool operator==( const const_iterator & rhs ) const;
        /**
         * \brief Sobrecarga do operador de diferença.
         * \param rhs Objeto que será comparado com quem chamou o operador.
         * \return True, se os membros são diferentes, False, se não.
         */
        bool operator!=( const const_iterator & rhs ) const;
    protected:
        SLLNode *current;                                           /**< Ponteiro atual do iterador. */
        const_iterator( SLLNode * p ) : current( p ) {/* EMPTY */ } /**< Construtor de iterador. */
        friend class ForwardList<Object>;                           /**< Determinação da herança da classe.*/
    };
    
    /**
     * \brief Classe que cria iteradores.
     */
    class iterator : public const_iterator{
    public:
        /**
         * \brief Contrutor da classe de iteradores constante.
         */
        iterator( ) : const_iterator( ) {/* EMPTY */ }
        /**
         * \brief Sobrecarga do operador de referenciamento.
         * \return Referência constante ao elemento.
         */
        const Object & operator* () const;
        /**
         * \brief Sobrecarga do operador de referenciamento.
         * \return Referência ao Objeto.
         */
        Object & operator* ();
        /**
         * \brief Sobrecarga do operador de incremento.
         * \return Retorna o valor apos o incremento.
         */
        iterator & operator++();
        /**
         * \brief Sobrecarga do operador de incremento.
         * \return Retorna o valor antes doo incremento.
         */
        iterator operator++( int );
        
        /**
        iterator & operator--();
        iterator operator--( int );
        */
        
    protected:
        iterator( SLLNode *p ) : const_iterator( p ) {/* EMPTY */ } /**< Construtor de iteradores.*/
        friend class ForwardList<Object>; /**< Determinação da herança da classe.*/
    };
    
    /**
     * \brief Recupera o tamanho atual da lista.
     * \return size_type Tamanho da lista.
     */
    size_type size( ) const;
    /**
     * \brief Limpa a lista, tornando-a vazia.
     */
    void clear( );
    /**
     * \brief Verifica se a lista está vazia.
     * \return True, Se a lista estiver vazia, False, caso contrário.
     */
    bool empty( ) const;
    /**
     * \brief Adiciona uma nova informação no final da lista.
     * \param _x Nova informação a ser adicionada na lista.
     */
    void push_back( const Object & x );
    /**
     * \brief Retira o último elemento da lista.
     */
    void pop_back( );
    /**
     * \brief Recupera o primeiro elemento da lista.
     * \return Elemento do ínico da lista.
     */
    const Object & front( ) const;
    /**
     * \brief Recupera o último elemento da lista.
     * \return Elemento do final da lista.
     */
    const Object & back( ) const;
    /**
     * \brief Muda a informação de todos os elementos da lista.
     * \param _x Nova informação.
     */ 
    void assign( const Object & x );

    /**
     * \brief Adiciona um elemento no inicio da lista.
     * \return _x Nova informação que será adicionado.
     */
    void push_front( const Object & x );
    /**
     * \brief Remove o elemento no ínicio da lista.
     */
    void pop_front();

    /**
     * \brief Iterador que aponta para a "cabeça" da lista.
     * \return Iterador para o head da lista.
     */
    iterator before_begin( );
    /**
     * \brief Iterador que aponta para a "cabeça" da lista.
     * \return Iterador para o head da lista.
     */
    const_iterator cbefore_begin( ) const;
    /**
     * \brief Iterador que aponta para o ínicio da lista.
     * \return Iterador para o primeiro elemento da lista.
     */
    iterator begin( );
    /**
     * \brief Iterador constante que aponta para o ínicio da lista.
     * \return Iterador constante que a aponta para o ínicio da lista.
     */
    const_iterator cbegin( ) const;
    /**
     * \brief Iterador que aponta para o último elemento da lista.
     * \return Iterador que aponta para o fim da lista.
     */
    iterator end( );
    /**
     * \brief Iterador constante que aponta para o último elemento da lista.
     * \return Iterador constante que aponta para o fim da lista.
     */
    const_iterator cend( ) const;

    /**
     * \brief Insere uma determinada informação após o iterador passado.
     * \param itr Iterador de referência para a inserção.
     * \param _x Informação a ser inserida.
     * \return Iterador que aponta para a informação inserida.
     */ 
    iterator insert_after( const_iterator itr, const Object & _x );
    /**
     * \brief Insere uma lista após um interador passado.
     * \param pos Iterador de referência para a inserção.
     * \param ilist Lista para ser inserida após pos.
     * \return Iterador que aponta para a última posição da nova lista inserida.
     */
    iterator insert_after( const_iterator pos, std::initializer_list <Object> ilist );
    /**
     * \brief Apagar um elemento após o iterador passado.
     * \param itr Iterador de referência para a remoção.
     * \return Iterador que aponta para o elemento após o que foi removido.
     */
    iterator erase_after( const_iterator itr );
    /**
     * \brief Apaga todas as informações entre os iteradores passados.
     * \param first, Iterador que marca o ínicio da remoção.
     * \param last Iterador que marca até onde deve ser removido.
     * \return Iterador que aponta para o elemento imediatamente após o último que foi removido.
     */
    iterator erase_after( const_iterator first, const_iterator last );
    /**
     * \brief Encontra um elemento na lista.
     * \param _x Informação a ser encontrada.
     * \return Iterador que aponta para o elemento anterior ao que foi achado.
     */
    const_iterator find( const Object & _x ) const;

};

#include "ForwardList.inl"

#endif
