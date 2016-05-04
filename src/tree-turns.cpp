#include "binary-search-trees.h"

int AVLTrees::depth(Node* node)
{
	if (!node)
		return -1;
	int l = depth(node->left);
	int r = depth(node->right);
	return r > l ? r+1 : l+1;
}

int AVLTrees::balanceDetection(Node *&node)
{
	int leftDepth = depth(node->left);
	int rightDepth = depth(node->right);
	/*if (leftDepth > rightDepth)
		node->balance = -1;
	else if (leftDepth < rightDepth)
		node->balance = 1;
	else 
		node->balance = 0; */
	node->balance = leftDepth - rightDepth;
	return node->balance;
}

void AVLTrees::insertSingleRightTurn(Node *&node)
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

	balanceDetection(A);
	balanceDetection(B);

	node = B;
}

void AVLTrees::insertSingleLeftTurn(Node *&node)
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

	balanceDetection(A);
	balanceDetection(B);

	node = B;
}

void AVLTrees::insertDoubleRightTurn(Node *&node)
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

	balanceDetection(A);
	balanceDetection(B);
	balanceDetection(C);

	node = C;
}

void AVLTrees::insertDoubleLeftTurn(Node *&node)
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

	balanceDetection(A);
	balanceDetection(B);
	balanceDetection(C);

	node = C;
}