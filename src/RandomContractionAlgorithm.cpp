#include <algorithm>
#include <chrono>
#include <random>
#include "RandomContractionAlgorithm.h"
#include "Graph.h"

using namespace std;

void removeSelfLoops(Graph & graph)
{
    Edges & edges = graph.edges();
    edges.erase(remove_if(begin(edges),end(edges),
                        [](Edge & edge)->bool
                        {
                              const auto & endpoints = edge.endpoints();
                              return endpoints.first == endpoints.second;
                        }),
                        end(edges));
}

void mergeVertices(Edge & edge, Graph & graph)
{
    Vertices & vertices = graph.vertices();
    vertices.erase(remove_if(begin(vertices),end(vertices),
                             [&edge](const Vertex & vertex)->bool
                             {
                                 const Endpoints & endpoints = edge.endpoints();
                                 const int id = vertex.id();
                                 return endpoints.second == id;
                              }),
                              end(vertices));
    Edges & edges = graph.edges();
    for_each(begin(edges),end(edges),
            [&edge](Edge & e)->void
            {
                const int   newId = edge.endpoints().first.id(),
                            oldId = edge.endpoints().second.id();
                Endpoints & endpoints = e.endpoints();
                if (oldId == endpoints.first)
                {
                    endpoints.first = newId;
                }
                if (oldId == endpoints.second)
                {
                    endpoints.second = newId;
                }
            });
}

int randomIndex(int first, int last)
{
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> dist(first, last);
    const int result = dist(rng);
    return result;
}

Edge randomEdge(const Edges & edges)
{
    size_t sz = edges.size();
    int idx = sz > 1 ? randomIndex(0, sz - 1) : 0;
    return edges[idx];
}

size_t RandomContractionAlgorithm::run(Graph graph)
{
    Vertices & vertices = graph.vertices();
    size_t size = vertices.size();
    double ln = log(size);
    size_t  runs = size * size * ln,
            minCut = UINT_MAX;
    Edges & edges = graph.edges();
    for (size_t i = 0; i < runs; ++i)
    {
        removeSelfLoops(graph);
        while(vertices.size() > 2)
        {
            Edge edge = randomEdge(edges);
            mergeVertices(edge, graph);
            removeSelfLoops(graph);
        }
        size_t cut = edges.size();
        if (cut < minCut)
        {
            minCut = cut;
        }
    }
    return minCut;
}
