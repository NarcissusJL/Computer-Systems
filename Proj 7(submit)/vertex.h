// vertex.h
// The Vertex class must overload relational operators for the usage in the MinPriorityQueue
// template when implementing the Prim algorithm
// Zuoyu Wang & Huiyang Li
#ifndef VERTEX_H
#define VERTEX_H

#include "list.h"

class Graph;

class Vertex
{
    friend class Graph;

public:
    Vertex(int v);
    Vertex(int v, int weight);

    // overload operators for comparision
    bool operator<(const Vertex &obj);
    bool operator>(const Vertex &obj);
    bool operator<=(const Vertex &obj);
    bool operator>=(const Vertex &obj);

private:
    // vertex identifier
    int v;
    // weight of the incident edge
    int weight;
    // the source endpoint of the incident edge to this vertex
    int source;
    // the adjacency list
    List<Vertex> adjlist;
};

#endif
