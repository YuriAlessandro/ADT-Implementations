#ifndef _LIST_H_
#define _LIST_H_

#include <stdexcept>

using size_type = int;

template <class Object>
class List{
private:
    struct SLLNode {
        Object miData;      /**< Armazena a informação do nó. */
        SLLNode *mpNext;    /**< Armazena o endereço do próximo nó. */
        SLLNode *mpBefore;  /**< Armazena o endereço do nó anterior. */

        SLLNode( const Object & d = Object(), SLLNode * n = nullptr, SLLNode * b = nullptr )
        : miData( d ), mpNext( n ), mpBefore( b )
        { /* Empty */ }
    };

    SLLNode *mpHead;    /**< Nó cabeça da lista. */ 
    SLLNode *mpTail;    /**< Nó rabo da lista. */
    size_type miSize;   /**< Tamanho da lista. */
    
public:

    /**
     * @brief Construtor da classe de Lista duplamente encadeada.
     */
    List();

    /**
     * @brief Destruidor da classe.
     */
    ~List();

    /**
     * @brief Classe que cria iteradores constantes.
     */
    class const_iterator{
    public:
        const_iterator();
        const Object & operator*() const;
        const_iterator & operator++();
        const_iterator operator++( int );
        const_iterator & operator--();
        const_iterator operator --( int );
        bool operator==( const const_iterator & rhs ) const;
        bool operator!=( const const_iterator & rhs ) const;
    protected:
        SLLNode *current;
        const_iterator( SLLNode * p ) : current( p ){/* EMPTY */}
        friend class List<Object>;
    };
    /**
     * @brief Classe que cria iteradores.
     */
    class iterator : public const_iterator{
    public:
        iterator( ) : const_iterator( ) {/* EMPTY */ }
        const Object & operator* () const;
        Object & operator* ();

        iterator & operator++();
        iterator operator++( int );
        iterator & operator--();
        iterator operator--( int );
    protected:
        iterator( SLLNode *p ) : const_iterator( p ) {/* EMPTY */ }
        friend class List<Object>;
    };

    /**
     * @brief Recupera o tamanho atual da lista.
     * @return size_type Tamanho da lista.
     */
    size_type size() const;
    /**
     * @brief Limpa a lista, tornando-a vazia.
     */
    void clear();
    /**
     * @brief Verifica se a lista está vazia.
     * @return True, Se a lista estiver vazia, False, caso contrário.
     */
    bool empty() const;
    /**
     * @brief Adiciona uma nova informação no final da lista.
     * @param _x Nova informação a ser adicionada na lista.
     */
    void push_back( const Object & x );
    /**
     * @brief Retira o último elemento da lista.
     */
    void pop_back();
    /**
     * @brief Recupera o último elemento da lista.
     * @return Elemento do final da lista.
     */
    const Object & back() const;
    /**
     * @brief Recupera o primeiro elemento da lista.
     * @return Elemento do ínico da lista.
     */
    const Object & front() const;
    /**
     * @brief Muda a informação de todos os elementos da lista.
     * @param _x Nova informação.
     */
    void assign( const Object & x );
    /**
     * @brief Adiciona um elemento no inicio da fila.
     * @return _x Nova informação que será adicionado.
     */
    void push_front( const Object & x );
    /**
     * @brief Remove o elemento no ínicio da fila.
     */
    void pop_front();
    /**
     * @brief Iterador que aponta para a "cabeça" da fila.
     * @return Iterador para o head da fila.
     */
    iterator before_begin( );
    /**
     * @brief Iterador que aponta para a "cabeça" da fila.
     * @return Iterador para o head da fila.
     */
    const_iterator cbefore_begin( ) const;
    /**
     * @brief Iterador que aponta para o ínicio da fila.
     * @return Iterador para o primeiro elemento da fila.
     */
    iterator begin( );
    /**
     * @brief Iterador constante que aponta para o ínicio da fila.
     */
    const_iterator cbegin( ) const;
    /**
     * @brief Iterador que aponta para o último elemento da lista.
     */
    iterator end( );
    /**
     * @brief Iterador constante que aponta para o último elemento da lista.
     */
    const_iterator cend( ) const;

    // Funções que precisam de Iteradores
    iterator insert( iterator pos, const Object & x );
    template <typename InItr>
    iterator insert( iterator pos, InItr first, InItr last );
    iterator insert( const_iterator pos, std::initializer_list<Object> ilist );
    iterator erase( iterator pos );
    iterator erase( iterator first, iterator last );
    template <typename InItr>
    void assign( InItr first, InItr last );
    void assign( std::initializer_list<Object> ilist );

};

#include "List.inl"

#endif
