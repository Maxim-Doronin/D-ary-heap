#include "binary-search-trees.h"

int BinarySearchTree::depth(Node* node)
{
	if (!node)
		return 0;
	int l = depth(node->left);
	int r = depth(node->right);
	return r > l ? r : l;
}

int BinarySearchTree::balanceDetection(Node *&node)
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
	node = B;
}

void BinarySearchTree::insertSingleLeftTurn(Node *&node)
{
	Node *A  = node;
	Node *B  = A->right;
	Node *t1 = A->left;
	Node *t2 = B->left;
	Node *t3 = B->right;

	A->right = t2;
	B->left = A;
	B->parent = A->parent;
	A->parent = B;
	t2->parent = A;

	node = B;
}

void BinarySearchTree::insertDoubleRightTurn(Node *&node)
{
	Node *A  = node;
	Node *B  = A->left;
	Node *C  = B->right;
	Node *t1 = B->left;
	Node *t2 = C->left;
	Node *t3 = C->right;
	Node *t4 = A->right;

	C->right = A;
	C->left  = B;
	C->parent = A->parent;
	A->parent = C;
	B->parent = C;
	B->right = t2;
	A->left = t3;
	t2->parent = B;
	t3->parent = A;

	node = C;
}

void BinarySearchTree::insertDoubleLeftTurn(Node *&node)
{
	Node *A  = node;
	Node *B  = A->right;
	Node *C  = B->left;
	Node *t1 = A->left;
	Node *t2 = C->left;
	Node *t3 = C->right;
	Node *t4 = B->right;

	C->left = A;
	C->right  = B;
	C->parent = A->parent;
	A->parent = C;
	B->parent = C;
	B->left = t3;
	A->right = t2;
	t2->parent = A;
	t3->parent = B;

	node = C;
}