#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

class Edge;

using Edges = std::vector<Edge>;

class Vertex
{
public:
    Vertex(int id);
    int id() const;
    const Edges & edges() const;
    void add(const Edge & edge);

private:
    int id_;
    Edges edges_;
};

#endif // VERTEX_H
