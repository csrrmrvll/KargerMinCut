#include <set>
#include "AdjacencyList.h"
#include "Graph.h"

using namespace std;

Graph::Graph(const AdjacencyList & al)
{
    const List & list = al.list();
    for (const List::value_type & v : list)
    {
        const Vertex & first = v.first;
        this->vertices_.push_back(first);
        const set<Vertex> & adjacentVertices = v.second;
        for (const set<Vertex>::value_type & second : adjacentVertices)
        {
            const Edge edge(first, second);
            this->edges_.push_back(edge);
        }
    }
}

Vertices & Graph::vertices() { return this->vertices_; }
Edges & Graph::edges() { return this->edges_; }
