# ADT-Implementations #
Esse diretório possi três implementações diferentes para três Tipos Abstratos de 
Dados, sendo eles o Vector, Lista Simples e Lista Duplamente Encadeada.

Essas implementações tem como objetivo fixar o conteúdo da disciplinas de 
Estrutura de Dados Básica e Linguagem de Programação do curso de Bacharelado em Tecnologia da Informação
da Universidade Federal do Rio Grande do Norte (UFRN).

## Vector ##
Implementação de uma classe que armazena objetos em um vetor dinâmicamente alocado.

## Forward List ##
Implementação de uma classe que armazena objetos dinâmicamente, por meio de nós,
que possuem duas partes: A informação em si, e um endereço
para próximo nó. Diferente do Vector, não permite que memória alocada fique sem ser 
utilizada, porém ocupa mais.

## List ##
Implementação de uma classe que armazena objetos dinâmicamente, tal como a Lista Simples,
só que também possui uma outra parte: O endereço do nó anterior. Possui as mesmas características
da Lista Simples, em termo de memória, mas seus métodos são mais otimizados devido a 
maior facilidade de percorrer os nós.


## Como compilar
Para compilar qualquer um das três implementações, entre na pasta fonte dela no
terminal e coloque:
    
    $ make

Isso irá gerar um arquivo "exe" dentro da pasta bin.

# Autores
- Gustavo Araújo
- Yuri Alessandro Martins

## O que foi feito
- Implementação das funções básicas das classes Vector, ForwardList, e List.
- Implementação de iteradores em todas as classes.
- Implementação de várias funções baseadas em iteradores.
- Implementação dos construtores cópia e move (e operadores "="") de todas as
- classes.

## O que poderia ter sido feito melhor?
- As seguintes funções não foram implementadas pois estão com díficil compreensão
do que deve ser realizado:
```Shell
    template <typename InItr>
    iterator insert( iterator pos, InItr first, InItr last );
```
```Shell
    template <typename InItr>
    void assign( InItr first, InItr last );
```
```Shell
    void assign( std::initializer_list<Object> ilist );
```
    
- Erros de bad_alloc poderiam utilizar mensagens descritivas.