#include "graphs.h"
#include "Dijkstra.h"
#include <cfloat>

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

	float *dist = Dijkstra::dijkstra(graph, 3);
	
	using namespace std;
	cout << endl;
	for (int i = 0; i < n; i++)
		if (dist[i] == FLT_MAX)
			cout << "inf ";
		else
		cout << dist[i] << ' ';
	cout << endl;

	delete graph;
	delete []dist;
}