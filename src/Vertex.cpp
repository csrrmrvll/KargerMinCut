#include "Vertex.h"
#include "Edge.h"

Vertex::Vertex(int id, const Edges & edges)
:   id_(id), edges_(edges)
{
}

int Vertex::id() const { return this->id_; }

const Edges & Vertex::edges() const { return this->edges_; }
