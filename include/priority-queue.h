#pragma once
#include "d-ary-heap.h"
#include "AVL-Trees.h"

enum QueueID {
	HEAP = 0,
	AVLTREE = 1
};

class PriorityQueue {
public:
	PriorityQueue(){};

	virtual void push(Data *&key) = 0;
	virtual Data* pop() = 0;
	virtual void refresh() = 0;

	virtual int isFull() = 0;
	virtual int isEmpty() = 0;
};

class PriorityQueueHeap : public PriorityQueue {
protected:
	DAryHeap *heap;
public:
	PriorityQueueHeap(int d = 4);
	PriorityQueueHeap(const PriorityQueueHeap &queue);
	PriorityQueueHeap(Data **keys, int num, int d = 4);
	~PriorityQueueHeap();

	virtual void push(Data *&key);
	virtual Data* pop();
	virtual void refresh();

	virtual int isFull();
	virtual int isEmpty();
};

class PriorityQueueTree : public PriorityQueue {
protected:
	AVLTree *tree;
public:
	PriorityQueueTree();
	PriorityQueueTree(Data **keys, int num);
	~PriorityQueueTree();

	virtual void push(Data *&key);
	virtual Data* pop();
	virtual void refresh(){};

	virtual int isFull();
	virtual int isEmpty();
};

class QueueFactory {
public:
	static PriorityQueue* createQueue(QueueID qid)
	{
		PriorityQueue *queue;
		switch (qid)
		{
		case 0: queue = new PriorityQueueHeap(); break;
		case 1: queue = new PriorityQueueTree(); break;
		}
		return queue;
	}

};