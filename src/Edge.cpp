#include "Edge.h"
#include "Vertex.h"

Edge::Edge(const Vertex & a, const Vertex & b)
:   endpoints_(std::make_pair(a,b))
{
}

Endpoints & Edge::endpoints() { return this->endpoints_; }

