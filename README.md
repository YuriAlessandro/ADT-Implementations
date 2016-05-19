# ADT-Implementations #
Esse diretório possi três implementações diferentes para três Tipos Abstratos de 
Dados, sendo eles o Vector, Lista Simples e Lista Duplamente Encadaeada.

Essas implementações tem como objetivo fixar o conteúdo da disciplina de 
Estrutura de Dados Básica do curso de Bacharelado em Tecnologia da Informação
da Universidade Federal do Rio Grande do Norte (UFRN).

## Vector ##
Implementação de uma classe que armazena objetos em um vetor dinâmicamente alocado.
## Forward List ##
Implementação de uma classe que armazena objetos dinâmicamente, por meio de nós,
que possuem duas partes: A informação em sim, que deve ser armazenada, e um endereço
do próximo nó. Diferente do Vector, não permite que memória alocada fique sem ser 
utilizada.
## List ##
Implementação de uma classe que armazena objetos dinâmicamente, tal como a Lista Simples,
só que também possui uma outra parte: O endereço do nó anterior.

# Autores
- Gustavo Araújo
- Yuri Alessandro Martins

## Como compilar
Para compilar qualquer um das três implementações, entre na pasta fonte dela no
terminal e coloque:
    
    $ make

Isso irá gerar um arquivo dentro da pasta bin.

## O que foi feito
- Implementação das funções básicas das classes Vector, ForwardList, e List.
- Implementação de iteradores em todas as classes.
- Implementação de todas as funções baseadas em iteradores do ForwardList.
- Implementação dos construtores cópia e move do Vector e suas atribuições pelo
operador =
## O que poderia ter sido feito melhor?
- Melhor tratamento de erros com mensagens customizadas.
- Construtor cópia e move das classes List e ForwardList.
- Finalização das funções da classe List. 