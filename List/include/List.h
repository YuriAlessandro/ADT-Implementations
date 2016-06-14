/*!
 *  \mainpage Vector
 *  \author Gustavo Araújo e Yuri Alessandro Martins
 *  \copyright Copyright &copy; 2016. All rights reserved.
 *  \version 1.0
 *
 *  \file List.h
 *  \brief Header file
 *
 *  File with the List header
 */

#ifndef _LIST_H_
#define _LIST_H_

#include <stdexcept>

using size_type = int;

/**
 * \brief Classe da Lista Duplamente Encadeada.
 */
template <class Object>
class List{
private:
    struct DLLNode {
        Object miData;      /**< Armazena a informação do nó. */
        DLLNode *mpNext;    /**< Armazena o endereço do próximo nó. */
        DLLNode *mpBefore;  /**< Armazena o endereço do nó anterior. */

        DLLNode( const Object & d = Object(), DLLNode * n = nullptr, DLLNode * b = nullptr )
        : miData( d ), mpNext( n ), mpBefore( b )
        { /* Empty */ }
    };

    DLLNode *mpHead;    /**< Nó cabeça da lista. */ 
    DLLNode *mpTail;    /**< Nó rabo da lista. */
    size_type miSize;   /**< Tamanho da lista. */
    
public:

    /**
     * \brief Construtor da classe de Lista duplamente encadeada.
     */
    List();

    /**
     * \brief Construtor cópia do List.
     */
    List( const List & _vec );
    
    /**
     * \brief Construtor "move" do List
     */
    List( List && _vec );
    
    /**
     * \brief Sobrecarga do operador de atribuição por cópia.
     * \param _vec Origem da qual os elementos deverão ser copiados.
     * \return A própria lista que chamou o método.
     */
    List & operator= ( const List & _vec );
    /**
     * \brief Sobrecarga do operador de atribuição por "move".
     * \param _vec Origem da qual os elementos irão dar "move".
     * \return A própria lista que chamou o método.
     */
    List & operator= ( List && _vec );
    /**
     * \brief Destruidor da classe.
     */
    ~List();
    /**
     * \brief Classe que cria iteradores constantes.
     */
    class const_iterator{
    public:
        /**
         * \brief Contrutor da classe de iteradores constante.
         */
        const_iterator();
        /**
         * \brief Sobrecarga do operador de referenciamento.
         */
        const Object & operator*() const;
        /**
         * \brief Sobrecarga do operador de incremento.
         * \return Valor após o incremento.
         */
        const_iterator & operator++();
        /**
         * \brief Sobrecarga do operador de incremento.
         * \param Inteiro que irá incrementar.
         * \return Valor antes do incremento.
         */
        const_iterator operator++( int );
        /**
         * \brief Sobrecarga do operador de decremento.
         * \return Valor antes após o incremento.
         */
        const_iterator & operator--();
        /**
         * \brief Sobrecarga do operador de decremento.
         * \param Inteiro que irá decrementar.
         * \return Valor antes antes do incremento.
         */
        const_iterator operator --( int );
        /**
         * \brief Sobrecarga de operador de igualidade.
         * \param rhs Iterador que será comparado com o iterador que chamou o método.
         * \return True, se as duas listas forem iguais, False, se não.
         */
        bool operator==( const const_iterator & rhs ) const;
        /**
         * \brief Sobrecarga do operador de diferença.
         * \param rhs Iterador que será comparado com iterador que chamou o método.
         * \return True, se as duas listas forem diferentes
         */
        bool operator!=( const const_iterator & rhs ) const;
    protected:
        DLLNode *current;                                           /**< Ponteiro atual do iterador. */
        const_iterator( DLLNode * p ) : current( p ){/* EMPTY */}   /**< Construtor de iterador. */
        friend class List<Object>;                                  /**< Determinação da herança da classe.*/
    };
    /**
     * \brief Classe que cria iteradores.
     */
    class iterator : public const_iterator{
    public:
        /**
         * \brief Contrutor da classe de iteradores.
         */
        iterator( ) : const_iterator( ) {/* EMPTY */ }
        /**
         * \brief Operador de referenciamento.
         * \return O próprio objeto.
         */
        const Object & operator* () const;
        /**
         * \brief Sobrecarga do operador de referenciamento.
         * \return O próprio objeto.
         */
        Object & operator* ();
        /**
         * \brief Sobrecarga do operador de incremento.
         * \return Valor após o incremento.
         */
        iterator & operator++();
        /**
         * \brief Sobrecarga do operador de incremento.
         * \return Valor antes do incremento.
         */
        iterator operator++( int );
        /**
         * \brief Sobrecarga do operador de decremento.
         * \return Valor antes após o incremento.
         */
        iterator & operator--();
        /**
         * \brief Sobrecarga do operador de decremento.
         * \return Valor antes antes do incremento.
         */
        iterator operator--( int );
    protected:
        iterator( DLLNode *p ) : const_iterator( p ) {/* EMPTY */ }
        friend class List<Object>;
    };

    /**
     * \brief Recupera o tamanho atual da lista.
     * \return size_type Tamanho da lista.
     */
    size_type size() const;
    /**
     * \brief Limpa a lista, tornando-a vazia.
     */
    void clear();
    /**
     * \brief Verifica se a lista está vazia.
     * \return True, Se a lista estiver vazia, False, caso contrário.
     */
    bool empty() const;
    /**
     * \brief Adiciona uma nova informação no final da lista.
     * @param _x Nova informação a ser adicionada na lista.
     */
    void push_back( const Object & x );
    /**
     * \brief Retira o último elemento da lista.
     */
    void pop_back();
    /**
     * \brief Recupera o último elemento da lista.
     * \return Elemento do final da lista.
     */
    const Object & back() const;
    /**
     * \brief Recupera o primeiro elemento da lista.
     * \return Elemento do ínico da lista.
     */
    const Object & front() const;
    /**
     * \brief Muda a informação de todos os elementos da lista.
     * @param _x Nova informação.
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
     * \return Iterador constante que aponta para o ínicio da lista.
     */
    const_iterator cbegin( ) const;
    /**
     * \brief Iterador que aponta para o último elemento da lista.
     * \return Iterador que aponta para o final da lista.
     */
    iterator end( );
    /**
     * \brief Iterador constante que aponta para o último elemento da lista.
     * \return Iterador constante que aponta para o final da lista
     */
    const_iterator cend( ) const;
    /**
     * \brief Insere uma informação na posição anterior à posição solicitada.
     * \param pos Posição a qual o novo objeto deverá ser adicionado antes.
     * \param x Nova informação a ser armazenada.
     * \return Iterador que aponta para o novo objeto inserido.
     */
    iterator insert( iterator pos, const Object & x );
    /**
     * \brief
     * \param pos
     * \param first
     * \param last
     * \return
     */
    // template <typename InItr>
    // iterator insert( iterator pos, InItr first, InItr last );
    /**
     * \brief Insere uma lista após a posição solicitada.
     * \param pos A lista será inserida após essa posição pedida pelo cliente.
     * \param ilist Lista que será adicionada na Lista solicitada.
     * \return Iterador que aponta para a posição do último objeto da nova lista adiconada.
     */
    iterator insert( const_iterator pos, std::initializer_list<Object> ilist );
    /**
     * \brief Remove o elemento da lista na posição informada.
     * \param pos Iterador que aponta para o elemento que será excluído.
     * \return Iterador que aponta para o primeiro elemento após o que foi excluído.
     */
    iterator erase( iterator pos );
    /**
     * \brief Remove os elementos da lista no intervalo solicitado.
     * \param firt Iterador que aponta para o índice inicial do processo de exclusão.
     * \param last Iterador que aponta para o índice onde a exclusão de objetos deve parar.
     * \return Iterador que aponta para o primeiro objeto após o último excluído.
     */
    iterator erase( iterator first, iterator last );
    /**
     * \brief 
     * \param first 
     * \param last
     * \return
     */
    // template <typename InItr>
    // void assign( InItr first, InItr last );
    /**
     * \brief
     * \param ilist
     * \return
     */
    // void assign( std::initializer_list<Object> ilist );

};

#include "List.inl"

#endif
