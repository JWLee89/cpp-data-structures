#include "stdafx.h"
#include "Stack.h"
#include <string>

int main()
{
	Stack<int> stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	int num = stack.Pop();

	std::cout << "popped item << " << num << std::endl;

	Stack<std::string> strStack;
	strStack.Push("test");
	strStack.Push("rawrrr");

    return 0;
}
