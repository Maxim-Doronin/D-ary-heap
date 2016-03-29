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
private:
	Node* root;
public:
	BinarySearchTree();
	~BinarySearchTree();

	Node* searchMin(Node *node = 0);
	Node* searchMax(Node *node = 0);
	Node* searchPrev(Node *node);
	Node* searchNext(Node *node);
	Node* search(float key);

	void insert(Node *node);
	void remove(float key);
	Node* pull(float key);

private:
	char balanceDetection(Node *&node);
	int depth(Node *node);
	void insertSingleRightTurn(Node *&node);
};