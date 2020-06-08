#include <iostream>
#include <stack>
 
// std::stack only provides access to the topmost element. If we want to
// print all elements, we need to copy the stack (by passing it by value)
// and pop elements until the stack is empty.
void printStack(std::stack<int> stack)
{
	std::cout << "( ";
	while (!stack.empty())
	{
		std::cout << stack.top() << ' ';
		stack.pop();
	}
	std::cout << ")\n";
}
 
int main()
{
	// Create a std::stack that holds ints.
	std::stack<int> stack{};
 
	printStack(stack);
 
	stack.push(5);
	stack.push(3);
	stack.push(8);
	printStack(stack);
 
	stack.pop();
	printStack(stack);
 
	// To clear the stack, assign it an empty stack.
	stack = {};
	printStack(stack);
 
	return 0;
}