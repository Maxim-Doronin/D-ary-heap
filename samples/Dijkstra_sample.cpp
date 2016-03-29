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
	if (argc == 6)	{				//граф рандомный	
		n = atoi(argv[1]);
		m = atoi(argv[2]);
		int minRange = atoi(argv[3]);
		int maxRange = atoi(argv[4]);
		s = atoi(argv[5]);

		graph = new Graph(n, m);
		graph->generateGraph(minRange, maxRange);
	}
	else if (argc == 3)	{			//граф задан матрицей
		string filename(argv[1]);
		ifstream input(filename);
		if (!input) {
			cout << "error!";
			return 2;
		}
		input >> n;
		s = atoi(argv[2]);
		graph = new Graph(n);
		float weight;
		for (int i = 0; i < n; i++){
			int N, K;
			float weight;
			while(!input.eof()){
				input >> N;
				input >> K;
				input >> weight;
				graph->addEdge(N, K, weight);
			}
		}
	}
	else return 1;

	graph->printList();
	cout << endl;

	float *dist = Dijkstra::dijkstra(graph, s);

	fstream output;
	output.open("ways.txt", fstream::in | fstream::out);
	if(output)
		remove("ways.txt");			//удалил, если такой уже есть
	ofstream ofs("ways.txt");		//создал файл
	if(!output)
		output.open("ways.txt", fstream::in | fstream::out);
	output << n << ' ' << m << endl;//печатаю количество вершин
	output << s << endl;			//печатаю стартовую вершину

	m = graph->getRealSize();
	Edge* edge;
	for (int j = 0; j < m; j++) {
		edge = graph->getEdge(j);
		output << edge->K << ' ' << edge->N << ' ' << edge->weight << endl;
	}

	output << endl;
	for (int i = 0; i < n; i++)
		if (dist [i] != FLT_MAX)
			cout << dist[i] << ' ';
		else
			cout << "inf" << ' ';

	for (int i = 0; i < n; i++) {
		output << i;
		if (dist[i] != FLT_MIN) 
			output << ' ' << dist[i];
		output << endl;
	}

	output.close();
	delete graph;
	delete []dist;
	return 0;
}