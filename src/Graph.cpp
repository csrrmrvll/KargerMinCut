#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include "Graph.h"

const Vertices & Graph::vertices() const { return this->vertices_; }
const Edges & Graph::edges() const { return this->edges_; }

using namespace std;

istream & operator>>(istream & in, Graph & graph)
{
    string line;
    Vertices vertices;
    Edges edges;
    using Vector = vector<int>;
    while (getline(in,line))
    {
        Vector v;
        istringstream iss(line);
        copy(istream_iterator<int>(iss),istream_iterator<int>(), back_insert_iterator<Vector>(v));
        copy(begin(v),end(v),ostream_iterator<int>(cout, " "));
        cout << endl;
        const int vertexId = v[0];
        Vertex vertex(vertexId);
//        const Vector aux(++begin(v),end(v));
//        for (int n : aux)
//        {
//            const Edge edge(vertex, Vertex(n));
//            vertex.add(edge);
//            edges.emplace_back(edge);
//        }
        vertices.emplace_back(vertex);
    }
    graph.vertices_ = vertices;
    graph.edges_ = edges;
    return in;
}
