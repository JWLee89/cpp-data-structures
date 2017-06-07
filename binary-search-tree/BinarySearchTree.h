#pragma once
#include <string>
#include <iostream>

class BinarySearchTree
{
private:
	typedef struct Node
	{
		int data;
		Node *leftChild;
		Node *rightChild;
	} *node_ptr;

	node_ptr root;
	size_t sz;

	void IncrementSize();
	void DecrementSize();

	node_ptr CreateNewNode(int data) const;
	node_ptr GetMaxNode(node_ptr currentNode) const;
	node_ptr GetMinNode(node_ptr currentNode) const;

	void EmptyTree(node_ptr currentNodePtr) const;

	void AddNode(node_ptr nodePtr, int dataToAdd) const;
	node_ptr RemoveNode(node_ptr currentNode, int dataToRemove);

public:
	BinarySearchTree();
	void Add(int data);
	void Remove(int data);
	~BinarySearchTree();
};
