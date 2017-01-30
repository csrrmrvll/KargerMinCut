#include "AdjacencyList.h"
#include "Vertex.h"

using namespace std;

const List & AdjacencyList::list() const { return this->list_;}

bool AdjacencyList::addVertex(const Vertex & vertex)
{
    const pair<List::iterator,bool> result = this->list_.insert(make_pair(vertex, set<Vertex>()));
    return result.second;
}

bool AdjacencyList::addEdge(const Vertex & first, const Vertex & second)
{
    const pair<set<Vertex>::iterator,bool> result = this->list_[first].insert(second);
    return result.second;
}
