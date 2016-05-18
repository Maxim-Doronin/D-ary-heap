#include "AVL-Trees.h"

char AVLNode::getBalance() const 
{
	return balance;
}

void AVLNode::setBalance(const char balance)
{
	this->balance = balance;
}

AVLTree::AVLTree() : BinarySearchTree()
{
}

void AVLTree::insert(AVLNode *&node)
{
	node->parent = 0;
	node->left = 0;
	node->right = 0;
	node->setBalance(0);
	if (!root) 
	{
		root = node;
		return;
	}
	recursiveIns((AVLNode*&)root, node);
}

void AVLTree::recursiveIns(AVLNode *&localRoot, AVLNode *&node)
{
	if (node->key < localRoot->key) {
		if (!localRoot->left) {
			localRoot->left = node;
			node->parent = localRoot;
		}
		else
			recursiveIns((AVLNode*&)localRoot->left, node);
	}
	else {
		if (!localRoot->right) {
			localRoot->right = node;
			node->parent = localRoot;
		}
		else
			recursiveIns((AVLNode*&)localRoot->right, node);
	}
	
	decisionOnBalancing(localRoot);
}

void AVLTree::remove(float key) 
{
	delete recursiveRem((AVLNode*&)root, key);
}

void AVLTree::remove(Node* node)
{
	delete recursiveRem((AVLNode*&)root, node->key);
}

Node* AVLTree::pull(float key)
{
	return recursiveRem((AVLNode*&)root, key);
}

Node* AVLTree::pull(Node* node)
{
	return recursiveRem((AVLNode*&)root, node->key);
}

Node* AVLTree::recursiveRem(AVLNode *&localRoot, float key)
{
	Node *result;
	if (!localRoot)
		return 0;
	if (key < localRoot->key)
		result = recursiveRem((AVLNode*&)localRoot->left, key);
	else if (key > localRoot->key)
		result = recursiveRem((AVLNode*&)localRoot->right, key);
	else {
		if (!localRoot->left && !localRoot->right) {
			if (localRoot->parent)
				if (localRoot->parent->left == localRoot)
					localRoot->parent->left = 0;
				else
					localRoot->parent->right = 0;
			else 
				root = 0;
			return localRoot;
		}
		else if (localRoot->left && !localRoot->right) {
			Node* son = localRoot->left;
			Node* killed = localRoot;
			son->parent = localRoot->parent;
			if (localRoot->parent)
				if (localRoot->parent->left == localRoot)
					localRoot->parent->left = son;
				else
					localRoot->parent->right = son;
			else
				root = son;
			return killed;
		}
		else if (!localRoot->left && localRoot->right) {
			Node* son = localRoot->right;
			Node* killed = localRoot;
			son->parent = localRoot->parent;
			if (localRoot->parent)
				if (localRoot->parent->left == localRoot)
					localRoot->parent->left = son;
				else
					localRoot->parent->right = son;
			else
				root = son;
			return killed;
		}
		else {
			Node *next = searchNext(localRoot);
			AVLNode *tmp = (AVLNode*)next->parent;
			if (next->right)
				next->right->parent = tmp;
			if (next->parent->left == next)
				tmp->left = next->right;
			else
				tmp->right = next->right;
			next->parent = localRoot->parent;
			next->left = localRoot->left;
			next->right = localRoot->right;
			if (next->left)
				next->left->parent = next;
			if (next->right)
				next->right->parent = next;

			while ((tmp != next) && (tmp)) {
				decisionOnBalancing(tmp);
				tmp = (AVLNode*)tmp->parent;
			}
			return localRoot;
		}
	}
	
	decisionOnBalancing(localRoot);
	return result;
}