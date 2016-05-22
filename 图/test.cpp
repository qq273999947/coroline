#include <iostream>
using namespace std;
#include "GraphMatrix.h"
#include "GraphLink.h"

void testMatrix()
{
	char a[5] = {'A','B','C','D','E'};
	GraphMatrix<char,int> gm(5,a);
	gm.Display();

	gm.AddEdges('A','B',3);
	gm.Display();
}
void testLink()
{
	char a[5] = {'A','B','C','D','E'};
	GraphLink<char,int> g(a,5);
	g.AddEdge('A', 'D', 10);
	g.AddEdge('A', 'E', 20);
	g.AddEdge('B', 'C', 10);
	g.AddEdge('B', 'D', 20);
	g.AddEdge('B', 'E', 30);
	g.AddEdge('C', 'E', 40);
	g.Display();
	g.DFS(0);
	g.BFS(0);
}

int main()
{
	testLink();
	return 0;
}