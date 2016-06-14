# Hashmap #
Esse diretório possui uma implementação do Tipo Abstrado de Dados (TAD) 
Tabela de Dispersão (Hash Table).

A implementação realizada foi feita com dispersão dupla. Isso significa que iremos
usar uma função de dispersão feita pelo cliente, e outra definida (fixa) pela
própria aplicação.

Para teste da TAD de Tabela de Dispersão, fo feita uma aplicação de teste que se baseia
no armazenamento de usários de um banco. As informações armazenadas são Nome do cliente,
Banco, Agência, Número da Conta e Saldo.

Esta implementação possui três versões de testes para a função de dispersão do cliente.
A primeira versão é a função de dispersão padrão do sistema, que mapeia a partir
do hashing no número da conta.

A segunda versão mapeia a partir de um par de informações - no caso do teste 
implementado aqui o número da conta e o nome do cliente, enquanto
que a terceira versão utiliza uma tupla que contém
o nome do cliente, o código do banco, o número da agência e o número da conta.

# Como compilar #
Para compilar essa aplicação, entre na pasta fonte pelo terminal e coloque:

    $ make

Isso irá gerar um executável dentro da pasta bin.

Como existem três versões disponíveis, você talvez queira compilar como:
    
    $ make V= <versão> 

Por padrão, a versão 3 irá ser usada se nenhuma for especificada.

# Como executar #

Para executar o arquivo de testes, você deve acessar a pasta fonte pelo terminal e colocar:

    $ ./bin/exe


# Autores #
- Gustavo Araújo
- Yuri Alessandro Martins



Essa implementação tem como objetivo fixar o conteúdo das disciplinas de 
Estrutura de Dados Básica e Linguagem de Programação do curso de Bacharelado em 
Tecnologia da Informação da Universidade Federal do Rio Grande do Norte (UFRN).