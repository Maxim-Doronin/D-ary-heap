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
	node->key = key->priorities;
	node->data = key;
	tree->insert(node);
}

Data* PriorityQueueTree::pop()
{
	Node *tmp = tree->searchMin();
	tree->pull(tmp);
	return (Data*)tmp->data;
}

void PriorityQueueTree::refresh()
{

}

int PriorityQueueTree::isFull()
{
	AVLNode *tmp;
	try {
		tmp = new AVLNode;
	}
	catch(...) {
		return 1;
	}
	delete tmp;
	return 0;
}

int PriorityQueueTree::isEmpty()
{
	return tree->isEmpty();
}

