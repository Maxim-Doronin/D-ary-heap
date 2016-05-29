#pragma once
#include "d-ary-heap.h"
#include "graphs.h"
#include "priority-queue.h"
#include "separated-set.h"

class DataEdge : public Data {
public:	
	DataEdge(Edge *edge);
	Edge *edge;
};

class Kruskal {
public:
	static Graph* kruskal(Graph *&graph, int &isConnected, int fid);
};