#ifndef GRAPH_H
#define GRAPH_H

#include <ostream>
#include <vector>
#include "AdjacencyList.h"
#include "Edge.h"
#include "Vertex.h"

using Vertices = std::vector<Vertex>;
using Edges = std::vector<Edge>;
using Vector = std::vector<int>;

class Graph
{
public:
    Graph(const AdjacencyList & al);
    Vertices & vertices();
    Edges & edges();

private:
    Vertices vertices_;
    Edges edges_;
};

std::ostream & operator<<(std::ostream & os, Edges & edges);
std::ostream & operator<<(std::ostream & os, Vertices & vertices);

#endif // GRAPH_H
