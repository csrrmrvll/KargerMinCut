#ifndef GRAPH_H
#define GRAPH_H

#include <istream>
#include <vector>
#include "Vertex.h"
#include "Edge.h"

using Vertices = std::vector<Vertex>;
using Edges = std::vector<Edge>;

class Graph
{
public:
    const Vertices & vertices() const;
    const Edges & edges() const;
    friend std::istream & operator>>(std::istream & in, Graph & graph);

private:
    Vertices vertices_;
    Edges edges_;
};

std::istream & operator>>(std::istream & in, Graph & graph);

#endif // GRAPH_H
