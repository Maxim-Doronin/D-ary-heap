#include "Kruskal.h"

DataEdge::DataEdge(Edge *edge)
{
	this->edge = edge;
	priorities = edge->weight;
}

Graph* Kruskal::kruskal(Graph *&graph, int &isConnected, int fid)
{
	int n = graph->getVerticesNum();
	if (n == 0) throw "Kruskal: Graph has no vertices!";
	int m = graph->getRealSize();
	Graph *tree = new Graph(n);

	SeparatedSet *set = new SeparatedSet(n);
	for (int i = 0; i < n; i++)
		set->singleton(i);
	
	PriorityQueue *queue = QueueFactory::createQueue(static_cast<QueueID>(fid));
	Data **data = new Data*[m];
	for (int i = 0; i < m; i++) {
		data[i] = new DataEdge(graph->getEdgeSet()[i]);
		queue->push(data[i]);
	}
	
	int treeEdgeSize = 0;
	while ((treeEdgeSize < n-1)&&(!queue->isEmpty()))
	{
		Data* tmp = queue->pop();
		int N = ((DataEdge*)tmp)->edge->N;
		int K = ((DataEdge*)tmp)->edge->K;
		float weight = ((DataEdge*)tmp)->edge->weight;
		int An = set->defineSet(N);
		int Ak = set->defineSet(K);
		if (An != Ak)
		{
			set->association(An, Ak);
			tree->addEdge(N, K, weight);
			treeEdgeSize++;
		}
	}

	if (set->getSetSize(0) == n)
		isConnected = 1;
	else
		isConnected = 0;

	for (int i = 0; i < m; i++)
		delete data[i];
	delete []data;
	delete set;
	delete queue;

	return tree;	
}