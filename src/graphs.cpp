#include "graphs.h"

Edge::Edge(int N, int K, float weight)
{
	this->N = N;
	this->K = K;
	this->weight = weight;
}

Graph::Graph(int n)
{
	if ((n < 0)||(n > 45))
		throw "Graph: Invalid namber of vertices";
	else
		this->n = n;
	this->m = n*(n-1)/2;
	m_cur = 0;
	vertices = new int[n];
	edges = new Edge*[m];
}

Graph::Graph(int n, int m)
{
	if ((n < 0)||(n > 45))
		throw "Graph: Invalid namber of vertices";
	else
		this->n = n;

	if ((m < 0)||(m > n*(n-1)/2))
		throw "Graph: Invalid namber of edges";
	else
		this->m = m;
	
	m_cur = 0;

	vertices = new int[n];
	edges = new Edge*[m];
}

Graph::~Graph()
{
	cleaner();
	delete [] edges;
	delete []vertices;
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
	return rand() % (int)(maxRange - minRange -1) + minRange;// + 1.0/(float)rand();	
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

	if (minRange > maxRange)
		throw "Graph: Invalid ranges";

	if (!m_cur){
		cleaner();
		m_cur = 0;
	}

	srand(time(NULL));
	for (int i = 0; i < m; i++){
		generateVertices(N, K);
		weight = generateWeight(minRange, maxRange);
		edges[i] = new Edge(N, K, weight);
		m_cur++;
	}
}

void Graph::addEdge(int N, int K, float weight)
{
	if (m_cur == m)
		throw "Graph: Graph is full";
	if (N == K)
		throw "Graph: Loops are disabled";
	edges[m_cur] = new Edge(N, K, weight);
	m_cur++;
}

void Graph::delEdge(int N, int K)
{
	for (int j = 0; j < m_cur; j++)
		if ((edges[j]->K == K) &&
			(edges[j]->N == N) ||
			(edges[j]->N == K) &&
			(edges[j]->K == N))
		{
			edges[j] = edges[m_cur - 1];
			m_cur--;
		}	
}

int Graph::getVerticesNum()
{
	return n;
}

int Graph::getEdgeSize()
{
	return m;
}

int Graph::getRealSize()
{
	return m_cur;
}

Edge** Graph::getEdgeSet()
{
	return edges;
}

float Graph::getWeight(int N, int K)
{
	for (int j = 0; j < m_cur; j++)
		if ((edges[j]->K == K) &&
			(edges[j]->N == N) ||
			(edges[j]->N == K) &&
			(edges[j]->K == N))
			return edges[j]->weight;
	throw "Graph: Invalid edge!";
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
				cout << edges[j]->K << '(' << edges[j]->weight<< ')'<< ", ";
			if (edges[j]->K == i)
				cout << edges[j]->N << '(' << edges[j]->weight<< ')'<< ", ";
		}
		cout << endl;
	}
}