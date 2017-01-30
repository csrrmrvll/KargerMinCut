#ifndef GRAPH_H
#define GRAPH_H

#include <istream>
#include <vector>
#include "Vertex.h"
#include "Edge.h"

using Vertices = std::vector<Vertex>;
using Edges = std::vector<Edge>;
using Vector = std::vector<int>;
class AdjacencyList;

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

#endif // GRAPH_H
