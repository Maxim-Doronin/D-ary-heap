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
	virtual void remove(Node* node);
	virtual Node* pull(float key);
	virtual Node* pull(Node* node);

private:
	int balanceDetection(AVLNode *node);
	int depth(AVLNode *node);
	void decisionOnBalancing(AVLNode *&node);
	void singleRightTurn(AVLNode *&node);
	void singleLeftTurn(AVLNode *&node);
	void doubleRightTurn(AVLNode *&node);
	void doubleLeftTurn(AVLNode *&node);

	void recursiveIns(AVLNode *&localRoot, AVLNode *&node);
	Node* recursiveRem(AVLNode *&localRoot, float key); 
};