# Lista Encadeada simples
## Autoria
Gustavo Araújo Carvalho

## Para compilar
	g++ -Wall -std=c++11 -I include/ src/les_v1.cpp src/drive_les_v1.cpp -o exe

## Funções
### Funções obrigatórias implementadas:
- print
- length
- empty
- clear
- front
- back
- pushFront
- pushBack
- popFront
- find
- insert
- remove

### Funções extras implementadas:
- reverse
- reverseContent

### Notas
- A função reverseContent é uma implementação ingênua que inverte a lista pelo
conteúdo, enquanto a reverse inverte a lista pela direção dos ponteiros.
- Se for testar com a lista vazia, lembre que os "cout" da "main" geram facilmente
erros de segmentação
