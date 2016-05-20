#ifndef _VECTOR_H_
#define _VECTOR_H_

/**
 *  \file Vector.h
 *  \brief Vector headers.
 */

#include <memory>

using size_type = int;

/**
 * Classe que intancia um Vector.
 */
template <class Object>
class Vector {

public:
    /**
     * \brief Classe de iteradores constantes
     */
    class const_iterator{
    public:
        /**
         * \brief Construtor da classe de iteradores constantes
         */
        const_iterator(){/* Empty */}
        /**
         * \brief Sobrecarga do operador de incremento.
         * \return Retorna o valor após o incremento.
         */
        const_iterator & operator++();
        /**
         * \brief Sobrecarga do operador de incremento.
         * \return Retorna o valor antes do incremento.
         */
        const_iterator operator++(int);
        /**
         * \brief Sobrecarga do operador de decremento.
         * \return Retorna o valor após o decremento.
         */
        const_iterator & operator--();
        /**
         * \brief Sobrecarga do operador de decremento.
         * \return Retorna o valor antes do decremento.
         */
        const_iterator operator--(int);
        /**
         * \brief Sobrecarga de operador de igualidade.
         * \param RHS Vector que será comparado com o Vector que chamou o método.
         * \return True Se os dois Vectores forem iguais, False, caso contrário.
         */
        bool operator==( const const_iterator & RHS ) const;
        /**
         * \brief Sobrecarga do operador de diferença.
         * \param RHD Vector que será comparado com o Vector que chamou o método.
         * \return True, se os dois Vectors forem diferentes, False, caso contrário.
         */
        bool operator!=( const const_iterator & RHS ) const;
        /**
         * \brief Sobrecarga do operador de referenciamento.
         * \return Próprio objeto, referenciado.
         */
        const Object & operator*() const;

    protected:
        Object * m_ptr;             /**< Ponteiro do iterador. */
        const_iterator( Object * _new = nullptr ) : m_ptr( _new ){/* Empty */}  /**< Construtor de iteradores. */
        friend class Vector;    /**< Determina a herança da classe. */

    };
    
    /**
     * \brief Classe que cria iteradores.
     */
    class iterator : public const_iterator{
    public:
        /**
         * \brief Construtor da classe de iteradores constantes
         */
        iterator( ) : const_iterator( ) {/* Empty */}
        /**
         * \brief Sobrecarga do operador de incremento.
         * \return Retorna o valor após o incremento.
         */
        iterator & operator++();
        /**
         * \brief Sobrecarga do operador de incremento.
         * \return Retorna o valor antes do incremento.
         */
        iterator operator++(int);
        /**
         * \brief Sobrecarga do operador de decremento.
         * \return Retorna o valor após o decremento.
         */
        iterator & operator--();
        /**
         * \brief Sobrecarga do operador de decremento.
         * \return Retorna o valor antes do decremento.
         */
        iterator operator--(int);
        /**
         * \brief Sobrecarga do operador de referenciamento.
         * \return Próprio objeto, constante, referenciado.
         */
        const Object & operator*() const;
        /**
         * \brief Sobrecarga do operador de referenciamento.
         * \return Referência ao próprio objeto.
         */
        Object & operator*();
    protected:
        iterator( Object * _new ) : const_iterator( _new ){/* Empty */} /**< Construtor de iteradores. */
        friend class Vector<Object>;                                    /**< Determina a herança da classe. */
    };

    /**
     * \brief Construtor do Vector.
     */
    Vector( size_type _newSize = 10 );
    
    /**
     * \brief Construtor cópia do Vector.
     */
    Vector( const Vector & _vec );
    
    /**
     * \brief Construtor "move" do Vector
     */
    Vector( Vector && _vec );
    
    /**
     * \brief Sobrecarga do operador de atribuição por cópia.
     * \param _vec Origem de onde será feita a cópia.
     * \return Próprio vector que chamou pelo método.
     */
    Vector & operator= ( const Vector & _vec );
    /**
     * \brief Sobrecarga do operador de atribuição por "move".
     * \param _vec Origem de onde será feito o "move".
     * \return Próprio vector que chamou pelo método.
     */
    Vector & operator= ( Vector && _vec );
    
    /**
     * \brief Iterador constante que aponta para o índice inicial do Vector.
     * \return Iterador constante que aponta para o ínicio do Vector.
     */
    const_iterator cbegin() const;
    
    /**
     * \brief Iterador constante que aponta para o último índice do Vector.
     * \return Iterador constante que aponta para o fim do vector.
     */
    const_iterator cend() const;
    
    /**
     * \brief Iterador que aponta para o índice de inicio do Vector.
     * \return Iterador que aponta para o ínicio do Vector.
     */
    iterator begin() const;
    
    /**
     * \brief Iterador constante que aponta para o ultimo índice do Vector.
     * \return Iterador que aponta para o fim do Vector.
     */
    iterator end() const;
    
    /**
     * \brief Recupera o atual tamanho do Vector.
     * \return Tamanho do Vector no momento da chamada.
     */
    size_type size() const;
    
    /**
     * \brief Esvazia o Vector, deixando-o limpo.
     */
    void clear();
    
    /**
     * \brief Informa se o Vector está vazio.
     * \return True, se o Vector estiver vazio, False, se não.
     */
    bool empty();
    
    /**
     * \brief Adiciona um objeto para o final do Vector.
     * \param x Informação a ser adicionada no Vector.
     */
    void push_back( const Object & x );
    
    /**
     * \brief Remove o objeto que estiver no final do Vector.
     */
    void pop_back();
    
    /**
     * \brief Recupera o objeto que se encontra na última posição do Vector.
     * \return Objeto no final do Vector.
     */
    const Object & back() const;
    
    /**
     * \brief Recupera o objeto que está na primeira posição do Vector.
     */
    const Object & front() const;
    
    /**
     * \brief Faz com que todos os objetos do Vector tornem-se o que foi solicitado.
     * \param x Objeto que irá ser distribuído por todo o Vector.
     */
    void assign( const Object & x );

    /**
     * \brief Operador de atribuição do tamanho do Vector.
     * \param idx Tamanho que o cliente deseja que o Vector tenha.
     * \return Objeto do índice passado.
     */
    Object & operator[]( size_type idx);
    
    /**
     * \brief Acessa um elemento específico do Vector.
     * \param idx Indice que o cliente deseja recuperar o objeto.
     * \return Objeto na posição pedida.
     */
    Object & at ( size_type idx );
    
    /**
     * \brief Recupera qual a capacidade ("limite") de armazenamento do Vector.
     * \return Capacidade atual do Vector.
     */
    size_type capacity() const;
    
    /**
     * \brief Reserva um espaço pedido para o Vector, aumentando sua capacidade.
     * \param new_capacity Nova capacidade que o Vector deverá ter.
     */
    void reserve( size_type new_capacity );
    
    /**
     * \brief Ponteiro padrão para a primeira posição do Vector.
     * \return Ponteiro padrão para a primeira posição do Vector.
     */
    Object * data() const;

private:
    std::unique_ptr<Object[]> mpArray;  /**< Ponteiro de Objetos para armazenamento. */
    size_type miCapacity;               /**< Capacidade máxima do Vector. */
    size_type miSize;                   /**< Tamanho atual do Vector. */
};

#include "Vector.inl"

#endif
