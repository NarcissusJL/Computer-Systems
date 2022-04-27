// graph.h
// This is the interface of the Graph class, which is based on an adjacent list
// representation.
// Zuoyu Wang & Huiyang Li

#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include <string>

class Graph
{
public:
    Graph(std::string filename);
    Graph(const Graph &g);
    ~Graph();
    Graph &operator=(const Graph &g);

    // perform a depth-first search of the graph
    void dfs();
    // detect if the graph contains a cycle - NOTE: the graph is treated as an
    // undirected graph here
    bool cycle();
    // perform the prim algorithm to construct a mst
    void prim(int root);

private:
    // number of vertices in the graph
    int nvertices;
    // array of vertices
    Vertex **vertices;

    // helper recursive function to perfrom DFS on the subgraph rooted at root
    void recurdfs(int root, bool visited[]);
    // helper recursive function to detect cycle in the subgraph rooted at v
    bool recurcycle(int v, bool visited[], int parent);

    void copy(const Graph &g);
    void destroy();
};

#endif
