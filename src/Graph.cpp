#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"

Graph::Graph(const Vertices & vertices, const Edges & edges)
:   vertices_(vertices), edges_(edges)
{
}

const Vertices & Graph::vertices() const { return this->vertices_; }
const Edges & Graph::edges() const { return this->edges_; }
