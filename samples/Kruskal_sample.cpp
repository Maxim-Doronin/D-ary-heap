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
	if (argc == 5)	{				//���� ���������	
		n = atoi(argv[1]);
		m = atoi(argv[2]);
		int minRange = atoi(argv[3]);
		int maxRange = atoi(argv[4]);

		graph = new Graph(n, m);
		graph->generateGraph(minRange, maxRange);
	}
	else if (argc == 2)	{			//���� ����� ��������
		string filename(argv[1]);
		ifstream input(filename);
		if (!input) {
			cout << "error!";
			return 2;
		}
		input >> n;
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
	else return 1;

	graph->printList();
	cout << endl;
	Graph *tree = Kruskal::kruskal(graph);
	tree->printList();

	fstream output;
	output.open("tree.txt", fstream::in | fstream::out);
	if(output)
		remove("tree.txt");			//������, ���� ����� ��� ����
	ofstream ofs("tree.txt");		//������ ����
	if(!output)
		output.open("tree.txt", fstream::in | fstream::out);
	output << n << ' ' << m << endl;			//������� ���������� ������ � �����
	
	m = graph->getRealSize();
	Edge* edge;
	for (int j = 0; j < m; j++) {
		edge = graph->getEdge(j);
		output << edge->K << ' ' << edge->N << ' ' << edge->weight << endl;
	}

	m = tree->getRealSize();
	output << endl;
	for (int j = 0; j < m; j++) {
		edge = tree->getEdge(j);
		output << edge->K << ' ' << edge->N << ' ' << edge->weight << endl;
	}

	output.close();
	delete graph;
	delete tree;
	//system("pause");
    return 0;
}



