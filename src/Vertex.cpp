#include "Vertex.h"
#include "Edge.h"

Vertex::Vertex(int id)
:   id_(id)
{
}

int Vertex::id() const { return this->id_; }
