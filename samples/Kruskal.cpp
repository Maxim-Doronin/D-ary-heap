#include "priority-queue.h"
#include "shared-set.h"
#include "graphs.h"

Graph* Kruskal(Graph *&graph, int n, int m);

int main(int argc, char **argv)
{
	if (argc != 5) 
		return 1;
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
	int minRange = atoi(argv[3]);
	int maxRange = atoi(argv[4]);

	Graph *graph = new Graph(n, m);
	graph->generateGraph(minRange, maxRange);
	graph->printList();

	Graph *tree = Kruskal(graph, n, m);
	tree->printList();
}

Graph* Kruskal(Graph *&graph, int n, int m)
{
	Graph *tree = new Graph(n);

	SharedSet *set = new SharedSet(n);
	for (int i = 0; i < n; i++)
		set->singleton(i);
	
	int realM = graph->getRealSize();
	Data **data = new Data*[realM];
	for (int i = 0; i < realM; i++)
		data[i] = new DataValues(graph->getEdgeSet()[i]);

	PriorityQueue *queue = new PriorityQueue(data, realM, 4);
	
	int treeEdgeSize = 0;
	while ((treeEdgeSize < n-1)&&(!queue->isEmpty()))
	{
		Data* tmp = queue->popMin();
		int N = ((DataValues*)tmp)->edge->N;
		int K = ((DataValues*)tmp)->edge->K;
		int weight = ((DataValues*)tmp)->edge->weight;
		int An = set->defineSet(N);
		int Ak = set->defineSet(K);
		if (An != Ak)
		{
			set->association(An, Ak);
			tree->addEdge(N, K, weight);
			treeEdgeSize++;
		}
	}

	return tree;	
}



