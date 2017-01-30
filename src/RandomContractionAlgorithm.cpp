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
    Endpoints & endpoints = edge.endpoints();
    const Vertex    & merged = endpoints.first,
                    & toMerge = endpoints.second;
    vertices.erase(remove(begin(vertices),end(vertices),toMerge));
    Edges & edges = graph.edges();
    for_each(begin(edges),end(edges),
            [&merged,&toMerge](Edge & e)->void
            {
                Endpoints & endpoints = e.endpoints();
                if (toMerge == endpoints.first)
                {
                    endpoints.first = merged;
                }
                if (toMerge == endpoints.second)
                {
                    endpoints.second = merged;
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
