// Implementation of the Vertex class
// Zuoyu Wang & Huiyang Li

#include "vertex.h"
#include <climits>

Vertex::Vertex(int v) : Vertex(v, INT_MAX)
{
}

Vertex::Vertex(int v, int weight)
{
    this->v = v;
    this->weight = weight;
}

bool Vertex::operator<(const Vertex &obj)
{
    return weight < obj.weight;
}

bool Vertex::operator>(const Vertex &obj)
{
    return weight > obj.weight;
}

bool Vertex::operator<=(const Vertex &obj)
{
    return weight <= obj.weight;
}

bool Vertex::operator>=(const Vertex &obj)
{
    return weight >= obj.weight;
}
