#include "graphs.h"

Edge::Edge(int N, int K, float weight)
{
	this->N = N;
	this->K = K;
	this->weight = weight;
}

Graph::Graph(int n, int m)
{
	this->n = n;
	this->m = m;
	m_cur = 0;

	vertices = new int[n];

	edges = new Edge*[m];
}

void Graph::generateVertices(int &N, int &K)
{
	do {
		N = rand() % n;
		K = rand() % n;	}
	while ((N == K)||(!originalityCheck(N, K)));
}

bool Graph::originalityCheck(int N, int K)
{
	for (int j = 0; j < m_cur; j++)
		if ((edges[j]->K == K) &&
			(edges[j]->N == N) ||
			(edges[j]->N == K) &&
			(edges[j]->K == N))
			return false;
	return true;
}

float Graph::generateWeight(float minRange, float maxRange)
{
	return rand() % (int)(maxRange - minRange -1) + minRange + 1.0/(float)rand();	
}

void Graph::cleaner()
{
	for (int i = 0; i < m_cur; i++)
		delete edges[i];
}

void Graph::generateGraph(float minRange, float maxRange)
{
	int N;
	int K;
	float weight;

	if (!m_cur)
		cleaner(); 

	srand(time(NULL));
	for (int i = 0; i < m; i++){
		generateVertices(N, K);
		weight = generateWeight(minRange, maxRange);
		edges[i] = new Edge(N, K, weight);
		m_cur++;
	}
}

void Graph::addVertexSet(int *vertices)
{

}

void Graph::addVertex(int vertex)
{
}

void Graph::addEdge(int N, int K, float weight)
{
	if (m_cur == m)
		throw "Graph is full";
	if (N == K)
		throw "Loops are disabled";
	edges[m_cur] = new Edge(N, K, weight);
	m_cur++;
}

void Graph::printList()
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		cout << i << " : ";
		for (int j = 0; j < m_cur; j++)
		{
			if (edges[j]->N == i)
				cout << edges[j]->K << ", ";
			if (edges[j]->K == i)
				cout << edges[j]->N << ", ";
		}
		cout << endl;
	}
}