#include "priority-queue.h"

PriorityQueueTree::PriorityQueueTree()
{
	tree = new AVLTree();
}

PriorityQueueTree::PriorityQueueTree(Data **keys, int num)
{
	tree = new AVLTree();
	for (int i = 0; i < num; i++)
	{
		AVLNode *node = new AVLNode;
		node->parent = 0;
		node->left = 0;
		node->right = 0;
		node->key = keys[i]->priorities;
		node->data = keys[i];
		tree->insert(node);
	}
}

PriorityQueueTree::~PriorityQueueTree()
{
	delete tree;
}

void PriorityQueueTree::push(Data *&key)
{
	AVLNode *node = new AVLNode;
	node->parent = 0;
	node->left = 0;
	node->right = 0;
	node->key = key->priorities;
	node->data = key;
	tree->insert(node);
}

Data* PriorityQueueTree::pop()
{
	Node *tmp = tree->searchMin();
	tree->remove(tmp->key);
	return (Data*)tmp->data;
}

void PriorityQueueTree::refresh()
{

}

int PriorityQueueTree::isFull()
{
	return 0;
}

int PriorityQueueTree::isEmpty()
{
	return tree->isEmpty();
}

