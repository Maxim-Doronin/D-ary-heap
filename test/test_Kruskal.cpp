#include "gtest.h"
#include "Kruskal.h"

TEST(KRUSKAL, algorithm_is_correct1)
{
	Graph *g = new Graph(6, 7);
	g->addEdge(1, 5, 1);
	g->addEdge(1, 2, 3);
	g->addEdge(2, 3, 5);
	g->addEdge(2, 5, 4);
	g->addEdge(3, 4, 2);
	g->addEdge(3, 5, 6);
	g->addEdge(4, 5, 7);

	bool flag = false;
	int isConnected;
	Graph *tree = Kruskal::kruskal(g, isConnected, 0);
	Edge** edges = tree->getEdgeSet();
	if ((edges[0]->N == 1) && (edges[0]->K == 5) &&
		(edges[1]->N == 3) && (edges[1]->K == 4) &&
		(edges[2]->N == 1) && (edges[2]->K == 2) &&
		(edges[3]->N == 2) && (edges[3]->K == 3) &&
		(tree->getRealSize() == 4))
			flag = true;
	ASSERT_TRUE(flag);
	delete tree;
	delete g;
}

TEST(KRUSKAL, algorithm_is_correct2)
{
	Graph *g = new Graph(6, 7);
	g->addEdge(0, 1, 1);
	g->addEdge(1, 2, 2);
	g->addEdge(2, 0, 1);
	g->addEdge(2, 3, 3);
	g->addEdge(3, 4, 1);
	g->addEdge(4, 5, 1);
	g->addEdge(5, 3, 2);
	
	bool flag = true;
	int isConnected;
	Graph *tree = Kruskal::kruskal(g, isConnected, 1);
	Edge** edges = tree->getEdgeSet();
	for (int i = 0; i < tree->getRealSize(); i++)
		if (edges[i]->weight == 2)
			flag = false;
	
	ASSERT_TRUE(flag);
	delete tree;
	delete g;
}

TEST(KRUSKAL, algorithm_is_correct3)
{
	Graph *g = new Graph(7, 12);
	g->addEdge(0, 1, 16);
	g->addEdge(0, 2, 12);
	g->addEdge(0, 3, 21);
	g->addEdge(1, 4, 20);
	g->addEdge(1, 3, 17);
	g->addEdge(2, 3, 28);
	g->addEdge(2, 5, 31);
	g->addEdge(3, 4, 18);
	g->addEdge(3, 5, 19);
	g->addEdge(3, 6, 23);
	g->addEdge(4, 6, 11);
	g->addEdge(5, 6, 27);

	int weightCount = 0;
	int isConnected;
	Graph *tree = Kruskal::kruskal(g, isConnected, 0);
	Edge** edges = tree->getEdgeSet();
	for (int i = 0; i < tree->getRealSize(); i++)
		weightCount += edges[i]->weight;
	
	EXPECT_EQ(weightCount, 93);
	delete tree;
	delete g;
}

TEST(KRUSKAL, throws_when_graph_has_no_vertices)
{
	Graph *g = new Graph(0);
	int isConnected;
	ASSERT_ANY_THROW(Kruskal::kruskal(g, isConnected, 1));
}

TEST(KRUSKAL, can_do_algorithm_when_there_is_no_edges)
{
	Graph *g = new Graph(5);
	int isConnected;
	Graph *tree = Kruskal::kruskal(g, isConnected, 0);
	EXPECT_EQ(tree->getRealSize(), 0);
}

TEST(KRUSKAL, algorithm_doesnt_change_sourse_tree)
{
	Graph *g = new Graph(5, 10);
	g->addEdge(1, 2, 10);
	g->addEdge(2, 4, 80);
	g->addEdge(1, 3, -10);
	int isConnected;
	Graph *tree = Kruskal::kruskal(g, isConnected, 1);
	EXPECT_EQ(tree->getRealSize(), 3);
}
	