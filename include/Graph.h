#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Vertex;
using Vertices = std::vector<Vertex>;
class Edge;
using Edges = std::vector<Edge>;

class Graph
{
public:
    Graph(const Vertices & vertices, const Edges & edges);

    const Vertices & vertices() const;
    const Edges & edges() const;

private:
    Vertices vertices_;
    Edges edges_;
};

#endif // GRAPH_H
