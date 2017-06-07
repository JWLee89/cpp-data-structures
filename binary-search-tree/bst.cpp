#include "stdafx.h"
#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree bst;
	bst.Add(10);
	bst.Add(8);
	bst.Add(16);
	bst.Add(2);

	bst.Remove(10);
	bst.Remove(16);

    return 0;
}
