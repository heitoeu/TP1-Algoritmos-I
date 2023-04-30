#include "graph.hpp"
#include <iostream>

using namespace std;

Graph::Graph(int num_vertices)
{
  this->g = vector<vector<pair<int, int>>>(2 * num_vertices);
  this->n = 2 * num_vertices;
}

void Graph::adicionar_aresta(int u, int v, int w)
{
  // u ida
  this->g[u].push_back({w, v + (n / 2)}); // par impar
  this->g[u + (n / 2)].push_back({w, v}); // impar par

  // u volta
  this->g[v].push_back({w, u + (n / 2)});
  this->g[v + (n / 2)].push_back({w, u});
}

int Graph::dijkstra(int s)
{
  int f = (n / 2) - 1; // destino final
  priority_queue<pair<int, int>> fp;
  vector<int> visitados(n, false);
  vector<int> dist(n, INF);

  dist[s] = 0;
  fp.push({-dist[s], s});

  while (!fp.empty())
  {
    pair<int, int> v = fp.top(); // v = (peso, vertice)
    visitados[v.second] = true;
    fp.pop();

    for (auto u : g[v.second]) // para cada vizinho w de v
    {
      if (visitados[u.second] == false && dist[u.second] > dist[v.second] + u.first)
      {
        dist[u.second] = dist[v.second] + u.first;
        fp.push({-dist[u.second], u.second});
      }
    }
  }

  if (dist[f] == INF)
  {
    return -1;
  }
  return dist[f];
}