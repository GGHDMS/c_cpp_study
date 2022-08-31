#pragma warning(disable:4996)
#include "WGraphFloyd.h"

int main()
{
	WGraphFloyd g;
	g.load( "graph_Floyd.txt" );
	//g.display(); 
	printf("Shortest Path By Floyd Algorithm\n");
	g.pReset();
	g.ShortestPathFloyd( ) ;
	printf("%2s->", g.getVertex(98));
	g.printPath(98, 65);
	printf("%2s\n", g.getVertex(65));
	printf("%2s->", g.getVertex(98));
	g.printPath(98, 171);
	printf("%2s\n", g.getVertex(171));
	printf("%2s->", g.getVertex(98));
	g.printPath(98, 69);
	printf("%2s\n", g.getVertex(69));
}

