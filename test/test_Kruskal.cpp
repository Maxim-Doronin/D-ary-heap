#include "gtest.h"
#include "Kruskal.h"

TEST(KRUSKAL, algorithm_is_correct)
{
	Graph *g = new Graph(6, 7);
	g->addEdge(1, 5, 1);
	g->addEdge(1, 2, 3);
	g->addEdge(2, 3, 5);
	g->addEdge(2, 5, 4);
	g->addEdge(3, 4, 2);
	g->addEdge(3, 5, 6);
	g->addEdge(4, 5, 7);

	Graph *tree = Kruskal::kruskal(g);
	Edge** edges = tree->getEdgeSet();
	if ((edges[0]->N == 1) && (edges[0]->K == 5) &&
		(edges[1]->N == 3) && (edges[1]->K == 4) &&
		(edges[2]->N == 1) && (edges[2]->K == 2) &&
		(edges[3]->N == 2) && (edges[3]->K == 3) &&
		(tree->getRealSize() == 4))
		ASSERT_TRUE(1);
	else
		ASSERT_TRUE(0);	
	delete tree;
	delete g;
}

TEST(KRUSKAL, throws_when_graph_has_no_vertices)
{
	Graph *g = new Graph(0);
	ASSERT_ANY_THROW(Kruskal::kruskal(g));
}

TEST(KRUSKAL, can_do_algorithm_when_there_is_no_edges)
{
	Graph *g = new Graph(5);
	Graph *tree = Kruskal::kruskal(g);
	EXPECT_EQ(tree->getRealSize(), 0);
}

TEST(KRUSKAL, algorithm_doesnt_change_sourse_tree)
{
	Graph *g = new Graph(5, 10);
	g->addEdge(1, 2, 10);
	g->addEdge(2, 4, 80);
	g->addEdge(1, 3, -10);
	Graph *tree = Kruskal::kruskal(g);
	EXPECT_EQ(tree->getRealSize(), 3);
}
	