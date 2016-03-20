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
	if (argc == 5)					//граф рандомный	
	{
		n = atoi(argv[1]);
		m = atoi(argv[2]);
		int minRange = atoi(argv[3]);
		int maxRange = atoi(argv[4]);

		graph = new Graph(n, m);
		graph->generateGraph(minRange, maxRange);
		graph->printList();
	}
	else if (argc == 2)	{			//граф задан матрицей
		string filename(argv[1]);
		ifstream input(filename);
		//ifstream input("C:/Users/asus/D-ary-heap/sln/mp2-lab4-graphs/Debug/graph.txt");
		if (!input) 
		{
			cout << "error!";
			return 2;
		}
		input >> n;
		graph = new Graph(n);
		float weight;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < i; j++)
				input >> weight;
			for (int j = i; j < n; j++){
				weight = 0;
				input >> weight;
				if (weight != 0)
					graph->addEdge(i, j, weight);
			}
		}
	}
	else return 1;

	Graph *tree = Kruskal::kruskal(graph);
	
	std::cout << std::endl;
	tree->printList();

	fstream output;
	output.open("tree.txt", fstream::in | fstream::out);
	if(output)
		remove("tree.txt");			//удалил, если такой уже есть
	ofstream ofs("tree.txt");		//создал файл
	output << n << endl;			//печатаю количество вершин

	float **matrix = new float*[n]; //матрица смежности
	for (int i = 0; i < n; i++)
		matrix[i] = new float[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = 0;
	
	m = graph->getRealSize();
	Edge* edge;
	for (int j = 0; j < m; j++) {	//матрица -- исходный граф
		edge = graph->getEdge(j);
		matrix[edge->N][edge->K] = edge->weight;
		matrix[edge->K][edge->N] = edge->weight;
	}

	for (int i = 0; i < n; i++) {	//записываем матрицу
		for (int j = 0; j < n; j++)
			output << matrix[i][j] << ' ';
		output << endl;
	} 

	for (int i = 0; i < n; i++)		//обнуляем матрицу
		for (int j = 0; j < n; j++)
			matrix[i][j] = 0;

	m = tree->getRealSize();
	for (int j = 0; j < m; j++)	{	//матрица -- дерево
		edge = tree->getEdge(j);
		matrix[edge->N][edge->K] = edge->weight;
		matrix[edge->K][edge->N] = edge->weight;
	}
    
	output << endl;
	for (int i = 0; i < n; i++)	{	//записываем дерево
		for (int j = 0; j < n; j++)
			output << matrix[i][j] << ' ';
		output << endl;
	} 
	
	output.close();
	delete graph;
	delete tree;
    return 0;
}



