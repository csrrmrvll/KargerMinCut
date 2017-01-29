#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

class Edge;

using Edges = std::vector<Edge>;

class Vertex
{
public:
    Vertex(int id, const Edges & edges);
    int id() const;
    const Edges & edges() const;

private:
    int id_;
    Edges edges_;
};

#endif // VERTEX_H
