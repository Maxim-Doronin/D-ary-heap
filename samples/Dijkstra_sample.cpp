#include "graphs.h"
#include "Dijkstra.h"
#include <cfloat>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char **argv)
{
	Graph *graph;
	int n;
	int m;
	int s;
	if (argc == 6)	{				//���� ���������	
		try {
			n = atoi(argv[1]);
			m = atoi(argv[2]);
			int minRange = atoi(argv[3]);
			int maxRange = atoi(argv[4]);
			s = atoi(argv[5]);
			graph = new Graph(n, m);
			graph->generateGraph(minRange, maxRange);
		}
		catch (...) {
			return -1;
		}
	}
	else if (argc == 3)	{			//���� ����� ��������
		string filename(argv[1]);
		ifstream input(filename);
		if (!input) {
			cout << "error!";
			return 2;
		}
		try {
			input >> n;
			input >> m;
			s = atoi(argv[2]);
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

	float *dist;
	int *up;
	try {
		Dijkstra::dijkstra(graph, s, dist, up);
	}
	catch (...) {
		return -2;
	}

	remove("ways.txt");	
	ofstream output("ways.txt");
	output.precision(2);
	
	output << n << ' ' << m << endl;//������� ���������� ������
	output << s << endl;			//������� ��������� �������

	m = graph->getRealSize();
	Edge* edge;
	for (int j = 0; j < m; j++) {
		edge = graph->getEdge(j);
		output << edge->N << ' ' << edge->K << ' ' << edge->weight << endl;
	}

	for (int i = 0; i < n; i++)
		if (dist [i] != FLT_MAX)
			cout << dist[i] << ' ';
		else
			cout << "inf" << ' ';

	for (int i = 0; i < n; i++) {
		output << endl;
		output << i;
		output << ' ' << dist[i];
		output << ' ' << up[i];
	}

	output.close();
	delete graph;
	delete []dist;
	delete []up;
	return 0;
}