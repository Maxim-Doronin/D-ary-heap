#include "Kruskal.h"

DataEdge::DataEdge(Edge *edge)
{
	this->edge = edge;
	priorities = edge->weight;
}

Graph* Kruskal::kruskal(Graph *&graph)
{
	int n = graph->getVerticesNum();
	int m = graph->getRealSize();
	Graph *tree = new Graph(n);

	SeparatedSet *set = new SeparatedSet(n);
	for (int i = 0; i < n; i++)
		set->singleton(i);
	
	Data **data = new Data*[m];
	for (int i = 0; i < m; i++)
		data[i] = new DataEdge(graph->getEdgeSet()[i]);

	PriorityQueue *queue = new PriorityQueue(data, m, 4);
	
	int treeEdgeSize = 0;
	while ((treeEdgeSize < n-1)&&(!queue->isEmpty()))
	{
		Data* tmp = queue->pop();
		int N = ((DataEdge*)tmp)->edge->N;
		int K = ((DataEdge*)tmp)->edge->K;
		int weight = ((DataEdge*)tmp)->edge->weight;
		int An = set->defineSet(N);
		int Ak = set->defineSet(K);
		if (An != Ak)
		{
			set->association(An, Ak);
			tree->addEdge(N, K, weight);
			treeEdgeSize++;
		}
	}

	for (int i = 0; i < m; i++)
		delete data[i];
	delete []data;
	delete set;
	delete queue;

	return tree;	
}