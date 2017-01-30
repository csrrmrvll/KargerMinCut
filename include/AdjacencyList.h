#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <map>
#include <set>

class Vertex;
using List = std::map<Vertex,std::set<Vertex>>;

class AdjacencyList
{
public:
    const List & list() const;
    bool addVertex(const Vertex & vertex);
    bool addEdge(const Vertex & first, const Vertex & second);

private:
    List list_;
};

#endif // ADJACENCYLIST_H
