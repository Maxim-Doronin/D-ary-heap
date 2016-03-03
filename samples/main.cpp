#include "priority-queue.h"
#include "graphs.h"

int main()
{
	Graph graph(7, 10);
	graph.generateGraph(-100, 100);
	graph.printList();
	return 0;
}