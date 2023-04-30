#include <iostream>
#include "graph.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    int n, a;
    int u, v, w;
    cin >> n >> a;
    Graph grafo(n);

    while (cin >> u >> v >> w)
    {
        u--, v--;
        if (w % 2 == 0)
        {
            grafo.adicionar_aresta(u, v, w);
        }
    }
    cout << grafo.dijkstra(0) << endl;

    return 0;
}