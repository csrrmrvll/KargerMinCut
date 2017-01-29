#include "Vertex.h"
#include "Edge.h"

Vertex::Vertex(int id)
:   id_(id), edges_()
{
}

int Vertex::id() const { return this->id_; }

const Edges & Vertex::edges() const { return this->edges_; }

void Vertex::add(const Edge & edge)
{
    this->edges_.emplace_back(edge);
}
