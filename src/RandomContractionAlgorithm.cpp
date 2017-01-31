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
                e = Edge(endpoints);
            });
}

using myclock = chrono::high_resolution_clock;

int randomIndex(int first, int last, myclock::time_point beginning)
{
    mt19937_64 rng(default_random_engine{}());
    uniform_int_distribution<int> distribution(first, last);
    const chrono::nanoseconds d = myclock::now() - beginning;
    size_t seed = d.count();
    rng.seed(seed);
    rng.discard(700000);
    const int result = distribution(rng);
    return result;
}

Edge randomEdge(const Edges & edges, myclock::time_point beginning)
{
    size_t sz = edges.size();
    int idx = randomIndex(0, sz - 1, beginning);
    return edges[idx];
}

size_t RandomContractionAlgorithm::run(Graph & graph)
{
    const myclock::time_point beginning = myclock::now();
    size_t size = graph.vertices().size();
    size_t  runs = size * size,
            minCut = UINT_MAX;
    for (size_t i = 0; i < runs; ++i)
    {
        Graph g = graph;
        Edges & edges = g.edges();
        Vertices & vertices = g.vertices();
        while(vertices.size() > 2)
        {
            Edge edge = randomEdge(edges, beginning);
            mergeVertices(edge, g);
            removeSelfLoops(g);
        }
        size_t cut = edges.size();
        if (cut < minCut)
        {
            minCut = cut;
        }
    }
    return minCut;
}
