#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

class Graph
{
private:
    vector<vector<pair<int, int>>> g;
    int n;

public:
    Graph(int num_vertices);
    void adicionar_aresta(int u, int v, int w);
    int dijkstra_par(int s);
};

#endif // GRAPH_HPP