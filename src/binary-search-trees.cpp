#include "binary-search-trees.h"

BinarySearchTree::BinarySearchTree()
{
}

BinarySearchTree::~BinarySearchTree()
{
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

void BinarySearchTree::insert(Node *node)
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

Node* BinarySearchTree::remove(float key)
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
	{
		z->key = y->key;
		delete y;
	}
	return 0;
}