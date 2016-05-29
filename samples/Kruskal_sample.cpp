#include "graphs.h"
#include "Kruskal.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char **argv)
{
	Graph *graph;
	int n;
	int m;
	int fid;
	if (argc == 6)	{				//граф рандомный	
		try {
			n = atoi(argv[1]);
			m = atoi(argv[2]);
			int minRange = atoi(argv[3]);
			int maxRange = atoi(argv[4]);
			fid = atoi(argv[5]);
			if (fid > 3 || fid < 0)
				return -3;
			graph = new Graph(n, m);
			graph->generateGraph(minRange, maxRange);
		}
		catch (...) {
			return -1;
		}
	}
	else if (argc == 2)	{			//граф задан матрицей
		string filename(argv[1]);
		ifstream input(filename);
		if (!input) {
			cout << "error!";
			return 2;
		}
		try { 
			input >> n;
			input >> m;
			input >> fid;
			if (fid > 3 || fid < 0)
				return -3;
			graph = new Graph(n);
			int N, K;
			float weight;
			while(!input.eof()){
				input >> N;
				input >> K;
				input >> weight;
				graph->addEdge(N, K, weight);
			}
		}
		catch (...) {
			return -1;
		}
		input.close();
	}
	else return 1;

	graph->printList();
	cout << endl;
	Graph *tree;
	int isConnected;
	try {
		tree = Kruskal::kruskal(graph, isConnected, fid);
	}
	catch (...) {
		return -2;
	}
	tree->printList();

	remove("tree.txt");
	ofstream output("tree.txt");
	output.setf(output.fixed, output.floatfield);
	output.precision(2);

	output << n << ' ' << m << endl;			//печатаю количество вершин и ребер
	output << isConnected << endl;

	m = graph->getRealSize();
	Edge* edge;
	for (int j = 0; j < m; j++) {
		edge = graph->getEdge(j);
		output << edge->N << ' ' << edge->K << ' ' << edge->weight << endl;
	}

	m = tree->getRealSize();
	for (int j = 0; j < m; j++) {
		edge = tree->getEdge(j);
		output << endl;
		output << edge->N << ' ' << edge->K << ' ' << edge->weight;
	}

	output.close();
	delete graph;
	delete tree;
    return 0;
}



