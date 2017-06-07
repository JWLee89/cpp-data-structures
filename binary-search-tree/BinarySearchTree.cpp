#include "stdafx.h"
#include "BinarySearchTree.h"
#include <string>
#include <iostream>

void BinarySearchTree::IncrementSize()
{
	this->sz++;
}

void BinarySearchTree::DecrementSize()
{
	this->sz--; 
}

BinarySearchTree::node_ptr BinarySearchTree::GetMaxNode(node_ptr currentNode) const
{
	node_ptr result = currentNode;
	while (currentNode->rightChild != nullptr)
	{
		result = currentNode->rightChild;
	}
	return result;
}

BinarySearchTree::node_ptr BinarySearchTree::GetMinNode(node_ptr currentNode) const
{
	node_ptr result = currentNode;
	while (currentNode-> leftChild != nullptr)
	{
		result = currentNode->leftChild;
	}
	return result; 
}


void BinarySearchTree::AddNode(node_ptr nodePtr, int dataToAdd) const
{
	// Base case
	if (nodePtr == nullptr)
	{
		return;
	}
	else
	{
		int data = nodePtr->data;
		// Go to left sub-tree
		if (data > dataToAdd)
		{
			if (nodePtr->leftChild == nullptr)
			{
				nodePtr->leftChild = CreateNewNode(dataToAdd);
			}
			else
			{
				AddNode(nodePtr->leftChild, dataToAdd);
			}
		}
		else
		{
			if (nodePtr->rightChild == nullptr)
			{
				nodePtr->rightChild = CreateNewNode(dataToAdd);
			}
			else
			{
				AddNode(nodePtr->rightChild, dataToAdd);
			}
		}
	}
}

/**
 *@param currentNode the root node of the current subtree
 *@param dataToRemove
 */
BinarySearchTree::node_ptr BinarySearchTree::RemoveNode(node_ptr currentNode, int dataToRemove)
{
	if (currentNode == nullptr)
	{
		return currentNode;
	}

	int currentData = currentNode->data;

	node_ptr leftChild = currentNode->leftChild;
	node_ptr rightChild = currentNode->rightChild;

	// Found data to remove
	if (currentData == dataToRemove)
	{
		std::cout << "Found data to remove" << std::endl;
		// delete
		if (leftChild == nullptr && rightChild == nullptr)
		{
			std::cout << "removing node << " << currentData << std::endl;
			delete currentNode;
			return nullptr;
		}

		// node to delete has right child
		if (leftChild == nullptr)
		{
			delete currentNode;
			return rightChild;
		}
		// Node to delete has left child
		else if (rightChild == nullptr)
		{
			delete currentNode;
			return leftChild;
		}
		// Two children.
		else
		{
			std::cout << "found node with two children: " << currentData << std::endl;
			node_ptr maxNodeFromLeftSubTree = GetMaxNode(leftChild);

			// Swap node to delete with two children with max node from left sub-tree
			node_ptr nodeToDelete = currentNode;
			currentNode->data = maxNodeFromLeftSubTree->data; maxNodeFromLeftSubTree;
			currentNode->leftChild = RemoveNode(leftChild, maxNodeFromLeftSubTree->data);

			return currentNode;
		}
	}
	// Go left
	else if (currentData > dataToRemove)
	{
		currentNode->leftChild = RemoveNode(leftChild, dataToRemove);
	}
	else // Go right
	{
		currentNode->rightChild = RemoveNode(rightChild, dataToRemove);
	}
	return currentNode;
}

void BinarySearchTree::EmptyTree(node_ptr currentNodePtr) const
{
	// Base case
	if (currentNodePtr == nullptr) {
		return;
	}
	EmptyTree(currentNodePtr->leftChild);
	EmptyTree(currentNodePtr->rightChild);

	// delete
	std::cout << "deleting --> " << currentNodePtr->data << std::endl;
	delete currentNodePtr;	
}

BinarySearchTree::node_ptr BinarySearchTree::CreateNewNode(int data) const
{
	node_ptr node = new Node;
	node->data = data;
	node->leftChild = nullptr;
	node->rightChild = nullptr;
	return node;
}

void BinarySearchTree::Add(int data)
{
	if (this->root == nullptr)
	{
		this->root = CreateNewNode(data);
	}
	else
	{
		AddNode(this->root, data);
	}
	IncrementSize();
}

BinarySearchTree::~BinarySearchTree()
{
	std::cout << "Destroying binary search tree" << std::endl;
	EmptyTree(this->root);
}

void BinarySearchTree::Remove(int data)
{
	if (this->root == nullptr)
	{
		return;
	}
	RemoveNode(this->root, data);
}

BinarySearchTree::BinarySearchTree() : sz(0)
{
	this->root = nullptr;
}
