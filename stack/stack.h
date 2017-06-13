#pragma once
#include <iostream>

template <typename T>
class Stack
{
private:

	typedef struct Node
	{
		Node *next;
		T data;
	} *nodePtr;

	// item at the top of the stack
	nodePtr head;
	size_t size;

	nodePtr CreateNewNode(T data);
	
	// Empty stack
	void Empty();

public:
	Stack();
	void Push(T data);
	int Size() const;
	T Pop();
	T Peek();
	~Stack();
};

template <typename T>
typename Stack<T>::nodePtr Stack<T>::CreateNewNode(T data)
{
	nodePtr node = new Node;
	node->data = data;
	node->next = nullptr;
	return node;
}

template <typename T>
void Stack<T>::Empty()
{
	nodePtr currentNodePtr = this->head;
	while (currentNodePtr != nullptr)
	{
		nodePtr temp = currentNodePtr->next;	// 0xccccc indicates uninitialized pointer
		std::cout << "deleting current item << " << currentNodePtr->data << std::endl;
		delete currentNodePtr;	
		currentNodePtr = temp;
	}
	this->size = 0;								// set Length to zero.
}

template <typename T>
Stack<T>::Stack(): size(0)
{
	this->head = nullptr;	// Arrggh I forgot to initialize this and spent 15 minutes trying to find out why it wasnt working ...
}

template <typename T>
void Stack<T>::Push(T data)
{
	nodePtr newHead = CreateNewNode(data);
	if (this->head == nullptr)
	{
		std::cout << "Inserting first element of stack" << std::endl;
		this->head = newHead;
	}
	else
	{
		nodePtr prevHead = this->head;
		newHead->next = prevHead;
		this->head = newHead;
	}
}

template <typename T>
int Stack<T>::Size() const
{
	return this->size;
}

template <typename T>
T Stack<T>::Pop()
{
	T data = this->head->data;
	nodePtr newHead = this->head->next;

	// Delete current head
	delete this->head;
	// Assign new head as the second last item on the top of the stack.
	this->head = newHead;

	return data;
}

template <typename T>
T Stack<T>::Peek()
{
	return this->head->data;
}

template <typename T>
Stack<T>::~Stack()
{
	std::cout << "Stack<T> destructor called << " << std::endl;
	this->Empty();
}
