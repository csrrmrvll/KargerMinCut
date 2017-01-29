#ifndef EDGE_H
#define EDGE_H

#include <utility>
#include "Vertex.h"

using Endpoints = std::pair<Vertex,Vertex>;

class Edge
{
public:
    Edge(const Vertex & a, const Vertex & b);
    const Endpoints & endpoints() const;

private:
    std::pair<Vertex,Vertex> endpoints_;
};

#endif // EDGE_H
