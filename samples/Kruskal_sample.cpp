#include "graphs.h"
#include "Kruskal.h"

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

	Graph *tree = Kruskal::kruskal(graph);
	
	std::cout << std::endl;
	tree->printList();

	delete graph;
	delete tree;
}



