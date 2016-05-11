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
	if (balanceDetection(localRoot) == 2)
		if (depth((AVLNode*)localRoot->left->left) > depth((AVLNode*)localRoot->left->right))
			insertSingleRightTurn(localRoot);
		else
			insertDoubleRightTurn(localRoot);
	if (balanceDetection(localRoot) == -2)
		if (depth((AVLNode*)localRoot->right->right) > depth((AVLNode*)localRoot->right->left))
			insertSingleLeftTurn(localRoot);
		else
			insertDoubleLeftTurn(localRoot);
}

void AVLTree::remove(float key) 
{
	recursiveRem((AVLNode*&)root, key);
}

void AVLTree::recursiveRem(AVLNode *&localRoot, float key)
{
	if (!localRoot)
		return;
	if (key < localRoot->key)
		recursiveRem((AVLNode*&)localRoot->left, key);
	if (key > localRoot->key)
		recursiveRem((AVLNode*&)localRoot->right, key);
	if (key == localRoot->key) {
		if (!localRoot->left && !localRoot->right) {
			if (localRoot->parent->left == localRoot)
				localRoot->parent->left = 0;
			else
				localRoot->parent->right = 0;
			delete localRoot;
		}
		if (localRoot->left && !localRoot->right) {
			if (localRoot->parent->left == localRoot)
				localRoot->parent->left = localRoot->left;
			else
				localRoot->parent->right = localRoot->left;
			localRoot->left->parent = localRoot->parent;
			delete localRoot;
		}
		if (!localRoot->left && localRoot->right) {
			if (localRoot->parent->left == localRoot)
				localRoot->parent->left = localRoot->right;
			else
				localRoot->parent->right = localRoot->right;
			localRoot->right->parent = localRoot->parent;
			delete localRoot;
		}
		if (localRoot->left && localRoot->right) {
			Node *next = searchNext(localRoot);
			AVLNode *tmp = (AVLNode*)next->parent;
			next->right->parent = next->parent;
			if (next->parent->left == next)
				next->parent->left = next->right;
			else
				next->parent->right = next->right;
			next->parent = localRoot->parent;
			next->left = localRoot->left;
			next->right = localRoot->right;
			delete localRoot;

			while (tmp != next) {
				if (balanceDetection(tmp) == 2)
					if (depth((AVLNode*)tmp->left->left) > depth((AVLNode*)tmp->left->right))
						insertSingleRightTurn(tmp);
					else
						insertDoubleRightTurn(tmp);
				if (balanceDetection(tmp) == -2)
					if (depth((AVLNode*)tmp->right->right) > depth((AVLNode*)tmp->right->left))
						insertSingleLeftTurn(tmp);
					else
						insertDoubleLeftTurn(tmp);
				tmp = (AVLNode*)tmp->parent;
			}
		}
	}
	if (balanceDetection(localRoot) == 2)
		if (depth((AVLNode*)localRoot->left->left) > depth((AVLNode*)localRoot->left->right))
			insertSingleRightTurn(localRoot);
		else
			insertDoubleRightTurn(localRoot);
	if (balanceDetection(localRoot) == -2)
		if (depth((AVLNode*)localRoot->right->right) > depth((AVLNode*)localRoot->right->left))
			insertSingleLeftTurn(localRoot);
		else
			insertDoubleLeftTurn(localRoot);
}