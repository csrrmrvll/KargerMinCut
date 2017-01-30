#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

class Vertex
{
public:
    Vertex(int id);
    int id() const;

private:
    int id_;
};

bool operator==(const Vertex & a, const Vertex & b);

#endif // VERTEX_H
