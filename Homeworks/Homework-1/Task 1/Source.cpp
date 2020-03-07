#include <iostream>
#include "IntStack.h"

// Original tests during debugging
void testStack() {
	IntStack stack1;
	
	std::cout << "Empty stack: " << stack1.isEmpty() << ", expected 1" << std::endl;
	std::cout << "Peek in stack: " << stack1.peek() << ", expected Error" << std::endl;
	stack1.print();
	std::cout << ", expected Error" << std::endl;
	std::cout << "Pop from stack: " << stack1.pop() << ", expected Error" << std::endl;

	// Fill stack1
	stack1.push(3);
	stack1.push(5);
	stack1.push(-222);
	stack1.push(123);
	stack1.push(331);
	stack1.push(0);
	stack1.push(22);

	// Print stack1
	stack1.print();
	std::cout << ", expected no error" << std::endl;

	// Try copy constructor
	IntStack stack2(stack1);
	// Print stack2
	stack2.print();
	std::cout << ", expected no error, same values" << std::endl;

	// Remove some items from stack 2
	std::cout << "Pop item from stack2: " << stack2.pop() << ", expected 22" << std::endl;
	std::cout << "Pop item from stack2: " << stack2.pop() << ", expected 0" << std::endl;
	// Print stack2
	stack2.print();
	std::cout << ", expected two values less" << std::endl;

	// Try operator=
	stack2 = stack1;
	// Print stack2 again
	stack2.print();
	std::cout << ", expected original values" << std::endl;

	// Test the sorting function
	IntStack stack3 = sortStack(stack2);

	// Print stack2 and stack3 for comparison
	stack2.print();
	std::cout << std::endl;
	stack3.print();
	std::cout << std::endl;
	std::cout << ", expected first row unsorted and second row sorted." << std::endl;
}

int main() {
	// Original tests during debugging
	// testStack();
	
	// Final tests for the task
	IntStack stack;

	// Enter elements into the stack
	stack.push(3);
	stack.push(-1);
	stack.push(22);
	stack.push(101);
	stack.push(-404);
	stack.push(3);
	stack.push(1);

	// Print stack elements
	std::cout << "Current stack elements:" << std::endl;
	stack.print();
	std::cout << std::endl;

	// Sort stack
	IntStack sorted = sortStack(stack);
	
	// Print sorted stack elements
	std::cout << "Sorted stack elements:" << std::endl;
	sorted.print();
	std::cout << std::endl;

	return 0;
}