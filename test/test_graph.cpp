#include "gtest.h"
#include "graphs.h"

TEST(GRAPH, can_create_graph_with_actual_n)
{
	Graph *g;
	ASSERT_NO_THROW(g = new Graph(10));
}

TEST(GRAPH, throws_when_try_create_graph_with_neg_n)
{
	Graph *g;
	ASSERT_ANY_THROW(g = new Graph(-10));
}

TEST(GRAPH, throws_when_try_create_graph_with_large_n)
{
	Graph *g;
	ASSERT_ANY_THROW(g = new Graph(maxVerticesSize + 1));
}

TEST(GRAPH, can_create_graph_with_actual_n_and_m)
{
	Graph *g;
	ASSERT_NO_THROW(g = new Graph(10, 20));
}

TEST(GRAPH, throws_when_try_create_graph_with_neg_m)
{
	Graph *g;
	ASSERT_ANY_THROW(g = new Graph(10, -20));
}

TEST(GRAPH, throws_when_try_create_graph_with_large_m)
{
	Graph *g;
	ASSERT_ANY_THROW(g = new Graph(10, 46));
}

TEST(GRAPH, can_generate_graph)
{
	Graph *g = new Graph(10);
	ASSERT_NO_THROW(g->generateGraph(-100, 100));
}

TEST(GRAPH, throws_when_try_generate_with_invalid_ranges)
{
	Graph *g = new Graph(10);
	ASSERT_ANY_THROW(g->generateGraph(100, -100));
}

TEST(GRAPH, can_regenerate_graph)
{
	Graph *g = new Graph(10);
	g->generateGraph(-50, 50);
	ASSERT_NO_THROW(g->generateGraph(-100, 100));
}

TEST(GRAPH, can_add_edge)
{
	Graph *g = new Graph(10);
	ASSERT_NO_THROW(g->addEdge(1, 5, 50));
}

TEST(GRAPH, throws_when_try_add_edge_to_full_graph)
{
	Graph *g = new Graph(10);
	g->generateGraph(-100, 100);
	ASSERT_ANY_THROW(g->addEdge(1, 5, 50));
}

TEST(GRAPH, throws_when_try_add_loop)
{
	Graph *g = new Graph(10);
	ASSERT_ANY_THROW(g->addEdge(1, 1, 50));
}

TEST(GRAPH, throws_when_try_add_multiple_edge)
{
	Graph *g = new Graph(10);
	g->addEdge(1, 5, 40);
	ASSERT_ANY_THROW(g->addEdge(1, 5, 50));
}

TEST(GRAPH, can_delete_edge)
{
	Graph *g = new Graph(10);
	g->addEdge(1, 5, 40);
	ASSERT_NO_THROW(g->delEdge(1, 5));
}

TEST(GRAPH, throws_when_try_delete_non_existent_edge)
{
	Graph *g = new Graph(10);
	g->addEdge(1, 5, 40);
	ASSERT_ANY_THROW(g->delEdge(1, 4));
}

TEST(GRAPH, throws_when_try_delete_edge_from_empty_graph)
{
	Graph *g = new Graph(10);
	ASSERT_ANY_THROW(g->delEdge(1, 4));
}

TEST(GRAPH, getVerticesNum_is_correct)
{
	Graph *g = new Graph(10);
	EXPECT_EQ(g->getVerticesNum(), 10);
}

TEST(GRAPH, getEdgeSize_is_correct)
{
	Graph *g = new Graph(10);
	EXPECT_EQ(g->getEdgeSize(), 45);
}

TEST(GRAPH, getRealSize_is_correct)
{
	Graph *g = new Graph(10);
	g->addEdge(1, 5, 40);
	EXPECT_EQ(g->getRealSize(), 1);
}

TEST(GRAPH, getRealSize_after_delete)
{
	Graph *g = new Graph(10);
	g->addEdge(1, 5, 40);
	g->delEdge(1, 5);
	EXPECT_EQ(g->getRealSize(), 0);
}

TEST(GRAPH, getEdgeSet_return_null_when_graph_is_empty)
{
	Graph *g = new Graph(10);
	EXPECT_EQ((int)g->getEdgeSet(), 0);
}

TEST(GRAPH, getWeight_is_correct)
{
	Graph *g = new Graph(10);
	g->addEdge(1, 5, 40);
	EXPECT_EQ(g->getWeight(1, 5), 40);
}

TEST(GRAPH, throws_when_try_getWeight_of_non_existent_edge)
{
	Graph *g = new Graph(10);
	g->addEdge(1, 5, 40);
	ASSERT_ANY_THROW(g->getWeight(1, 4));
}