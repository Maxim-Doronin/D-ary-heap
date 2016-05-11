#pragma once
#include "binary-search-trees.h"

class AVLNode : public Node {
protected:
	char balance;
public:
	char getBalance() const;
	void setBalance(const char balance);
};

class AVLTree : public BinarySearchTree {
public:
	AVLTree();
	virtual ~AVLTree(){};

	virtual void insert(AVLNode *&node);
	virtual void remove(float key);

private:
	int balanceDetection(AVLNode *node);
	int depth(AVLNode *node);
	void insertSingleRightTurn(AVLNode *&node);
	void insertSingleLeftTurn(AVLNode *&node);
	void insertDoubleRightTurn(AVLNode *&node);
	void insertDoubleLeftTurn(AVLNode *&node);

	void removeSingleRightTurn(AVLNode *&node);
	void removeSingleLeftTurn(AVLNode *&node);
	void removeDoubleRightTurn(AVLNode *&node);
	void removeDoubleLeftTurn(AVLNode *&node);

	void recursiveIns(AVLNode *&localRoot, AVLNode *&node);
	void recursiveRem(AVLNode *&localRoot, float key); 
};