#include "binary-search-trees.h"

int BinarySearchTree::depth(Node* node)
{
	if (!node)
		return 0;
	int l = depth(node->left);
	int r = depth(node->right);
	return r > l ? r : l;
}

char BinarySearchTree::balanceDetection(Node *&node)
{
	if (depth(node->left) > depth(node->right))
		node->balance = -1;
	else if (depth(node->left) < depth(node->right))
		node->balance = 1;
	else 
		node->balance = 0;
	return 0;
}

void BinarySearchTree::insertSingleRightTurn(Node *&node)
{
	Node *A  = node;
	Node *B  = A->left;
	Node *t1 = B->left;
	Node *t2 = B->right;
	Node *t3 = A->right;

	A->left  = t2;
	B->right = A;
	B->parent = A->parent;
	A->parent = B;
	t2->parent = A;

	A->balance = 0;
	B->balance = 0;
	A = B;
}
