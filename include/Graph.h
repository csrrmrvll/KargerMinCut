#ifndef GRAPH_H
#define GRAPH_H

#include <istream>
#include <vector>
#include "Vertex.h"
#include "Edge.h"

using Vertices = std::vector<Vertex>;
using Edges = std::vector<Edge>;
using Vector = std::vector<int>;
using AdjacencyList = std::vector<Vector>;

class Graph
{
public:
    Graph(const AdjacencyList & al);
    const Vertices & vertices() const;
    const Edges & edges() const;

private:
    Vertices vertices_;
    Edges edges_;
};

#endif // GRAPH_H
