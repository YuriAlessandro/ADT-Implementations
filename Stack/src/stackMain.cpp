#include <iostream>
#include "stackint.h"
#include "stackar.h"

int main(int argc, char const *argv[])
{
	//StackInt stack(0);
	StackAr<int> stack(2);
	stack.push(3);
	stack.push(2);
	stack.push(123);
	stack.push(1234);
	stack.push(12345);
	stack.push(123456);
	stack.push(1234567);

/* Teste com strings

	StackAr<std::string> stack(3);
	stack.push("Um");
	stack.push("Dois");
	stack.push("Três");
	stack.push("Quatro");
	stack.push("Cinco");
*/
	std::cout << "No topo: " << stack.top() << std::endl;

	while( !stack.isEmpty() ){
		std::cout << stack.pop() << " ";
	}

	std::cout << "\n";
	return 0;
}
