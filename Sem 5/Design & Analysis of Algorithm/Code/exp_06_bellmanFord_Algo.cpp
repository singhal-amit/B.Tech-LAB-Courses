#include <chrono>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

// Structure to represent an edge in the graph
struct Edge
{
  int from;
  int to;
  int weight;
};

// Function to add an edge to the graph
void addEdge(vector<Edge> &edges, int u, int v, int weight)
{
  edges.push_back({u, v, weight});
}

// Function to display the graph
void displayGraph(const vector<Edge> &edges, int n)
{
  cout << "Graph edge list representation:\n";
  for (const auto &edge : edges)
  {
    cout << "Edge from " << edge.from << " to " << edge.to << " with weight " << edge.weight << endl;
  }
}

// Bellman-Ford algorithm implementation
vector<int> bellmanFord(const vector<Edge> &edges, int n, int source, bool &hasNegativeCycle, int64_t &timeTaken)
{
  vector<int> dist(n, INT_MAX); // Distance array, initialized to infinity
  dist[source] = 0;             // Distance to source is 0

  // Measure time start
  auto start = high_resolution_clock::now();

  // Relax all edges |V| - 1 times
  for (int i = 0; i < n - 1; ++i)
  {
    for (const auto &edge : edges)
    {
      int u = edge.from;
      int v = edge.to;
      int weight = edge.weight;

      if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
      {
        dist[v] = dist[u] + weight;
      }
    }
  }

  // Check for negative-weight cycles
  hasNegativeCycle = false;
  for (const auto &edge : edges)
  {
    int u = edge.from;
    int v = edge.to;
    int weight = edge.weight;

    if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
    {
      hasNegativeCycle = true;
      break;
    }
  }

  // Measure time end
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(stop - start);
  timeTaken = duration.count(); // Time in nanoseconds

  return dist;
}

int main()
{
  cout << "\n5C6 - Amit Singhal (11614802722)\n"
       << endl;

  int n, e, source;

  // Input: Number of nodes and edges
  cout << "Enter the number of nodes and edges: ";
  cin >> n >> e;

  vector<Edge> edges;

  // Input: Edges
  cout << "\nEnter the edges (u, v, weight):\n";
  for (int i = 0; i < e; ++i)
  {
    int u, v, weight;
    cin >> u >> v >> weight;
    addEdge(edges, u, v, weight);
  }

  cout << endl;

  // Display the graph
  displayGraph(edges, n);

  // Input: Source node
  cout << "\nEnter the source node: ";
  cin >> source;

  // Time taken for calculating the shortest paths
  int64_t totalTime;
  bool hasNegativeCycle;

  // Find shortest paths from the source node to all other nodes using Bellman-Ford
  vector<int> dist = bellmanFord(edges, n, source, hasNegativeCycle, totalTime);

  // Check for negative-weight cycle
  if (hasNegativeCycle)
  {
    cout << "\nGraph contains a negative weight cycle. Shortest paths cannot be computed.\n";
  }
  else
  {
    // Display shortest distances from the source to all other nodes
    cout << "\nShortest distances from node " << source
         << " to all other nodes:\n";
    for (int i = 0; i < dist.size(); ++i)
    {
      if (dist[i] == INT_MAX)
      {
        cout << "To node " << i << " : Unreachable\n";
      }
      else
      {
        cout << "To node " << i << " : " << dist[i] << endl;
      }
    }

    // Display time complexity
    cout << "\nTime taken to compute shortest paths from node " << source
         << ": " << totalTime << " nanoseconds" << endl;
  }

  return 0;
}
