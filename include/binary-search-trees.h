#pragma once

class Node {
public:
	float key;
	Node* left;
	Node* right;
	Node* parent;
	char balance;
};

class BinarySearchTree {
protected:
	Node* root;
public:
	BinarySearchTree();
	virtual ~BinarySearchTree();

	Node* searchMin(Node *node = 0);
	Node* searchMax(Node *node = 0);
	Node* searchPrev(Node *node);
	Node* searchNext(Node *node);
	Node* search(float key);

	virtual void insert(Node *&node);
	virtual void remove(float key);
	virtual Node* pull(float key);
};

class AVLTrees : public BinarySearchTree {
public:
	AVLTrees();
	virtual ~AVLTrees();

	virtual void insert(Node *&node);
	virtual void remove(float key);
	virtual Node* pull(float key);

private:
	int balanceDetection(Node *&node);
	int depth(Node *node);
	void insertSingleRightTurn(Node *&node);
	void insertSingleLeftTurn(Node *&node);
	void insertDoubleRightTurn(Node *&node);
	void insertDoubleLeftTurn(Node *&node);

	void removeSingleRightTurn(Node *&node);
	void removeSingleLeftTurn(Node *&node);
	void removeDoubleRightTurn(Node *&node);
	void removeDoubleLeftTurn(Node *&node);

	void recursiveIns(Node *&localRoot, Node *&node);
	void recursiveRem(Node *&localRoot, float key); 
};