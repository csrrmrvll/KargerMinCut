#include "Graph.h"

using namespace std;

Graph::Graph(const AdjacencyList & al)
{
    for (const Vector & v : al)
    {
        const int vertexId = v[0];
        const Vertex vertex(vertexId);
        this->vertices_.emplace_back(vertex);
    }
    for (size_t i = 0; i < al.size(); ++i)
    {
        Vertex & one = this->vertices_[i];
        const Vector & v = al[i];
        for (size_t j = 1; j < v.size(); ++j)
        {
            const Vertex & two = this->vertices_[j];
            const Edge edge(one, two);
//            one.add(edge);
            this->edges_.emplace_back(edge);
        }
    }
}

const Vertices & Graph::vertices() const { return this->vertices_; }
const Edges & Graph::edges() const { return this->edges_; }
