#include "binary-search-trees.h"

BinarySearchTree::BinarySearchTree()
{
	root = 0;
}

BinarySearchTree::~BinarySearchTree()
{
	//DELETE TREE!
}

Node* BinarySearchTree::searchMin(Node *node)
{
	Node *tmp;
	if (!node)
		tmp = root;
	else
		tmp = node;
	if (!tmp)
		return 0;
	while (tmp->left)
		tmp = tmp->left;
	return tmp;
}

Node* BinarySearchTree::searchMax(Node *node)
{
	Node *tmp;
	if (!node)
		tmp = root;
	else
		tmp = node;
	if (!tmp)
		return 0;
	while (tmp->right)
		tmp = tmp->right;
	return tmp;
}

Node* BinarySearchTree::searchPrev(Node *node)
{
	if (!node)
		return 0;
	if(node->left)
		return searchMax(node);

	Node *tmp = node;
	while((tmp->parent) && (tmp == tmp->parent->left))
		tmp = tmp->parent;
	return tmp;
}

Node* BinarySearchTree::searchNext(Node *node)
{
	if (!node)
		return 0;
	if(node->right)
		return searchMin(node);

	Node *tmp = node;
	while((tmp->parent) && (tmp == tmp->parent->right))
		tmp = tmp->parent;
	return tmp;
}

Node* BinarySearchTree::search(float key)
{
	Node *tmp = root;
	if (!tmp) 
		return 0;
	while ((tmp) && (tmp->key != key))
	{
		if (key < tmp->key)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	return tmp;
}

void BinarySearchTree::insert(Node *&node)
{
	if (!root) 
	{
		root = node;
		return;
	}
	Node *tmp = root;
	Node *tmpPrev;
	while (tmp) {
		tmpPrev = tmp;
		if (tmp->key < node->key)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	node->parent = tmpPrev;
	if (tmpPrev->key <= node->key)
		tmpPrev->right = node;
	else
		tmpPrev->left = node;
}

Node* BinarySearchTree::pull(float key)
{
	Node *x = 0;
	Node *y = 0;
	Node *z = search(key);

	if ((z->left) && (z->right))
		y = searchNext(z);
	else
		y = z;
	if (y->left)
		x = y->left;
	else 
		x = y->right;
	if (x)
		x->parent = y->parent;
	if (y->parent)
		if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	if (y != z)
		z->key = y->key;
	return y;
}

void BinarySearchTree::remove(float key)
{
	delete pull(key);
}

void AVLTrees::insert(Node *&node)
{
	node->balance = 0;
	if (!root) 
	{
		root = node;
		return;
	}
	recursiveIns(root, node);
}

void AVLTrees::recursiveIns(Node *&localRoot, Node *&node)
{
	if (node->key < localRoot->key) {
		if (!localRoot->left) {
			localRoot->left = node;
			node->parent = localRoot;
		}
		else
			recursiveIns(localRoot->left, node);
	}
	else {
		if (!localRoot->right) {
			localRoot->right = node;
			node->parent = localRoot;
		}
		else
			recursiveIns(localRoot->right, node);
	}
	if (balanceDetection(localRoot) == 2)
		if (depth(localRoot->left) > depth(localRoot->right))
			insertSingleRightTurn(localRoot);
		else
			insertDoubleRightTurn(localRoot);
	if (balanceDetection(localRoot) == -2)
		if (depth(localRoot->right) > depth(localRoot->left))
			insertSingleLeftTurn(localRoot);
		else
			insertDoubleLeftTurn(localRoot);
}

void AVLTrees::remove(float key) 
{
	recursiveRem(root, key);
}

void AVLTrees::recursiveRem(Node *&localRoot, float key)
{
	if (!localRoot)
		return;
	if (key > localRoot->key)
		recursiveRem(localRoot->right, key);
	if (key < localRoot->key)
		recursiveRem(localRoot->left, key);
	if (key == localRoot->key) {
		if (!localRoot->left && !localRoot->right) {
			if (localRoot->parent->left == localRoot)
				localRoot->parent->left = 0;
			if (localRoot->parent->right == localRoot)
				localRoot->parent->right = 0;
			delete localRoot;
		}
		if (localRoot->left && !localRoot->right) {
			if (localRoot->parent->left == localRoot)
				localRoot->parent->left = localRoot->left;
			if (localRoot->parent->right == localRoot)
				localRoot->parent->right = localRoot->left;
			localRoot->left->parent = localRoot->parent;
			delete localRoot;
		}
		if (!localRoot->left && localRoot->right) {
			if (localRoot->parent->left == localRoot)
				localRoot->parent->left = localRoot->right;
			if (localRoot->parent->right == localRoot)
				localRoot->parent->right = localRoot->right;
			localRoot->right->parent = localRoot->parent;
			delete localRoot;
		}
		if (localRoot->left && localRoot->right) {
			Node *tmp = searchMin(localRoot->right);


	}
}