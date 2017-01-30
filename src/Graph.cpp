#include "Graph.h"

using namespace std;

Graph::Graph(const AdjacencyList & al)
{
    for (const Vector & v : al)
    {
        const int vertexId = v[0];
        const Vertex one(vertexId);
        this->vertices_.push_back(one);
        for (size_t j = 1; j < v.size(); ++j)
        {
            const Vertex two = v[j];
            this->vertices_.push_back(two);
            const Edge edge(one, two);
            this->edges_.push_back(edge);
        }
    }
}

const Vertices & Graph::vertices() const { return this->vertices_; }
const Edges & Graph::edges() const { return this->edges_; }
