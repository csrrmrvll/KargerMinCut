#include <fstream>
#include <iostream>
#include "Graph.h"

using namespace std;

Graph read()
{
    Graph g;
    ifstream is;
    is.open("C:\\Users\\csr\\Documents\\Algorithm design and analyisis I\\programming assignments\\KargerMinCut\\KargerMinCut.txt",std::ios::in);
    if (is.is_open())
    {
        is >> g;
        is.close();
    }
    else
    {
        throw runtime_error("file is not open!!");
    }
    return g;
}

int randomContractionAlgorithm(const Graph & g)
{
    return 3;
}

int main()
{
    const Graph g = read();
    const int minCut = randomContractionAlgorithm(g);
    cout << "Minimum cut: " << minCut << endl;
    return 0;
}
