#pragma once
#include <ctime>
#include <cstdlib>
#include <iostream>

class Edge {
public: 
	int N;
	int K;
	float weight;

	Edge(){};
	Edge(int N, int K, float weight);
};

class Graph {
private:
	int n;
	int m;
	int m_cur;
	Edge** edges;
	int* vertices;
public:
	Graph(int n, int m);

	void generateGraph(float minRange, float maxRange);

	void addVertexSet(int *vertices);
	void addVertex(int vertex);
	void addEdge(int N, int K, float weight);

	void printList();

private:
	void generateVertices(int &N, int &K);
	bool originalityCheck(int N, int K);
	float generateWeight(float minRange, float maxRange);
	void cleaner();
};

