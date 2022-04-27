// Unit tests for the Graph class
// Zuoyu Wang & Huiyang Li

#include "graph.h"
#include <assert.h>

int main()
{
    Graph g1("g1.txt");
    Graph g2("g2.txt");
    Graph g3("g3.txt");
    Graph g4("g4.txt");

    // test dfs()
    g1.dfs();

    // test cycle()
    assert(g1.cycle());
    assert(g2.cycle());
    assert(!g3.cycle());

    // test prim(int)
    g1.prim(0);
    g4.prim(0);

    // test copy constructor
    Graph g5 = g1;
    g1.dfs();

    // test assignment operator
    Graph *g6 = new Graph(g1);
    *g6 = g5;
    g6->dfs();

    // test ~Graph()
    delete g6;
    g5.dfs();

    return 0;
}
