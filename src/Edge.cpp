#include "Edge.h"
#include "Vertex.h"

Edge::Edge(const Vertex & a, const Vertex & b)
:   endpoints_(std::make_pair(a,b))
{
}

const Endpoints & Edge::endpoints() const { return this->endpoints_; }

