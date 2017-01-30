#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include "Graph.h"
#include "RandomContractionAlgorithm.h"

using namespace std;
using Vector = vector<int>;
using AdjacencyList = vector<Vector>;

AdjacencyList read()
{
    AdjacencyList al;
    ifstream is;
    is.open("C:\\Users\\csr\\Documents\\Algorithm design and analyisis I\\programming assignments\\KargerMinCut\\KargerMinCut.txt",std::ios::in);
    if (is.is_open())
    {
        string line;
        while (getline(is,line))
        {
            Vector v;
            istringstream iss(line);
            copy(istream_iterator<int>(iss),istream_iterator<int>(), back_insert_iterator<Vector>(v));
            copy(begin(v),end(v),ostream_iterator<int>(cout, " "));
            cout << endl;
            al.emplace_back(v);
        }
    }
    else
    {
        throw runtime_error("File is not open!!");
    }
    is.close();
    return al;
}

int main()
{
    const AdjacencyList al{read()};
    const Graph g{al};
    const int minCut = RandomContractionAlgorithm().run(g);
    cout << "Minimum cut: " << minCut << endl;
    return 0;
}
