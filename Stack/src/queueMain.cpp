#include <iostream>
#include "queuear.h"

int main(int argc, char const *argv[])
{
	QueueAr<std::string> queue(2);
	queue.enqueue("Um");
	queue.enqueue("Dois");
	queue.enqueue("Três");
/*
	QueueAr<int> queue(2);

    queue.enqueue(100);
    queue.enqueue(200);
    queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);
	queue.enqueue(5);
	queue.enqueue(6);

	//Para causar um "loop" na lista
	queue.dequeue();
	queue.dequeue();
	queue.enqueue(7);
	queue.enqueue(8);
*/
    std::cout << "Valor que está na frente: " << queue.getFront() << std::endl;

	std::cout << "Imprimindo a lista: [ ";
    while( !queue.isEmpty() ){
		std::cout << queue.dequeue() << " ";
	}
	std::cout << "]" << std::endl << std::endl;

}
