#include "gtest.h"
#include "Dijkstra.h"

TEST(DIJKSTRA, throws_when_start_isnt_correct)
{
	Graph *g = new Graph(6, 7);
	g->addEdge(1, 5, 1);
	float *dist;
	int *up;
	ASSERT_ANY_THROW(Dijkstra::dijkstra(g, 100, dist, up));
	delete g;
}

TEST(DIJKSTRA, algorithm_is_correct1)
{
	Graph *g = new Graph(10);
	g->addEdge(0, 1, 5);
	g->addEdge(0, 2, 8);
	g->addEdge(0, 3, 12);
	g->addEdge(1, 4, 4);
	g->addEdge(2, 3, 3);
	g->addEdge(2, 4, 2);
	g->addEdge(3, 5, 8);
	g->addEdge(4, 5, 6);
	g->addEdge(4, 6, 1);
	g->addEdge(5, 6, 24);
	g->addEdge(5, 7, 13);
	g->addEdge(6, 7, 5);
	g->addEdge(7, 8, 1);
	g->addEdge(7, 9, 2);
	g->addEdge(8, 9, 5);

	float *dist;
	int *up;
	Dijkstra::dijkstra(g, 0, dist, up);

	bool flag = false;
	if ((dist[0] == 0)&&(dist[1] == 5)&&(dist[2] == 8) &&
		(dist[3] == 11)&&(dist[4] == 9)&&(dist[5] == 15) &&
		(dist[6] == 10)&&(dist[7] == 15)&&(dist[8] == 16) &&
		(dist[9] == 17)&&
		(up[0] == 0)&&(up[1] == 0)&&(up[2] == 0)&&
		(up[3] == 2)&&(up[4] == 1)&&(up[5] == 4)&&
		(up[6] == 4)&&(up[7] == 6)&&(up[8] == 7)&&
		(up[9] == 7))
		flag = true;

	ASSERT_TRUE(flag);
	delete []dist;
	delete []up;
	delete g;
}

TEST(DIJKSTRA, algorithm_is_correct2)
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

	float *dist;
	int *up;
	Dijkstra::dijkstra(g, 0, dist, up);

	bool flag = false;
	if ((dist[0] == 0)&&(dist[1] == 16)&&(dist[2] == 12) &&
		(dist[3] == 21)&&(dist[4] == 36)&&(dist[5] == 40) &&
		(dist[6] == 44)&&
		(up[0] == 0)&&(up[1] == 0)&&(up[2] == 0)&&
		(up[3] == 0)&&(up[4] == 1)&&(up[5] == 3)&&
		(up[6] == 3))
		flag = true;

	ASSERT_TRUE(flag);
	delete []dist;
	delete []up;
	delete g;
}