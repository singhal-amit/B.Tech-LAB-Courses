#include <iostream>
#include <vector>
#include <climits>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

struct Edge
{
  int src, dest, weight;
};

// Function to display the graph in a table format
void displayGraph(int V, const vector<Edge> &edges)
{
  cout << "Original Graph:\n";
  cout << setw(10) << left << "Edges" << setw(10) << left << "Weights" << endl;
  cout << "-----------------" << endl;
  for (const auto &edge : edges)
  {
    cout << setw(1) << edge.src << " - " << setw(8) << edge.dest << setw(10) << edge.weight << endl;
  }
}

// Function to convert edge list to adjacency matrix
vector<vector<int>> toAdjacencyMatrix(int V, const vector<Edge> &edges)
{
  vector<vector<int>> adjMatrix(V, vector<int>(V, 0));
  for (const auto &edge : edges)
  {
    adjMatrix[edge.src][edge.dest] = edge.weight;
    adjMatrix[edge.dest][edge.src] = edge.weight; // Since the graph is undirected
  }
  return adjMatrix;
}

// Function to find the vertex with the minimum key value
int minKey(const vector<int> &key, const vector<bool> &inMST)
{
  int min = INT_MAX, min_index;

  for (int v = 0; v < key.size(); ++v)
  {
    if (!inMST[v] && key[v] < min)
    {
      min = key[v];
      min_index = v;
    }
  }

  return min_index;
}

// Function to implement Prim's algorithm to find the MST
void primMST(int V, const vector<vector<int>> &graph)
{
  vector<int> parent(V, -1);    // Array to store constructed MST
  vector<int> key(V, INT_MAX);  // Key values to pick minimum weight edge
  vector<bool> inMST(V, false); // To represent vertices not yet included in MST

  key[0] = 0; // Start from the first vertex

  for (int count = 0; count < V - 1; ++count)
  {
    int u = minKey(key, inMST);
    inMST[u] = true;

    for (int v = 0; v < V; ++v)
    {
      if (graph[u][v] && !inMST[v] && graph[u][v] < key[v])
      {
        parent[v] = u;
        key[v] = graph[u][v];
      }
    }
  }

  // Print the constructed MST
  cout << "\nMinimum Spanning Tree (MST):\n";
  cout << setw(10) << left << "Edges" << setw(10) << left << "Weights" << endl;
  cout << "------------------" << endl;
  for (int i = 1; i < V; ++i)
  {
    cout << setw(1) << parent[i] << " - " << setw(8) << i << setw(10) << graph[i][parent[i]] << endl;
  }
}

int main()
{

  cout << "\n5C6 - Amit Singhal (11614802722)\n"
       << endl;

  int V = 4; // Number of vertices in the graph

  vector<Edge> edges = {
      {0, 1, 7},
      {0, 2, 9},
      {0, 3, 14},
      {1, 2, 10},
      {1, 3, 15},
      {2, 3, 11}};

  displayGraph(V, edges);

  // Convert edge list to adjacency matrix
  vector<vector<int>> adjMatrix = toAdjacencyMatrix(V, edges);

  // Measure the time taken to find the MST
  auto start = high_resolution_clock::now();
  primMST(V, adjMatrix);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "\nTime taken to find MST: " << duration.count() << " microseconds\n";

  return 0;
}
