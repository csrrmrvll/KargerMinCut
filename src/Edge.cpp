#include <algorithm>
#include "Edge.h"
#include "Vertex.h"

using namespace std;

Edge::Edge(const Vertex & a, const Vertex & b)
:   endpoints_(std::make_pair(max(a,b),min(a,b)))
{
}

Endpoints & Edge::endpoints() { return this->endpoints_; }

