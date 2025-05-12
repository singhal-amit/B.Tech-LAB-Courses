#include <chrono>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using namespace std::chrono;

// Structure to represent an edge in the graph
struct Edge
{
  int to;
  int weight;
};

// Function to add an edge to the adjacency list
void addEdge(vector<vector<Edge> > &graph, int u, int v, int weight)
{
  graph[u].push_back({v, weight});
  graph[v].push_back({u, weight}); // For undirected graph
}

// Function to display the graph
void displayGraph(const vector<vector<Edge> > &graph)
{
  cout << "Graph adjacency list representation:\n";
  for (int i = 0; i < graph.size(); ++i)
  {
    cout << "Node " << i << ": ";
    for (const auto &edge : graph[i])
    {
      cout << "(to: " << edge.to << ", weight: " << edge.weight << ") ";
    }
    cout << endl;
  }
}

// Dijkstra's algorithm implementation
vector<int> dijkstra(const vector<vector<Edge> > &graph,
                     int source,
                     int64_t &timeTaken)
{
  int n = graph.size();
  vector<int> dist(n, INT_MAX); // Distance array, initialized to infinity
  dist[source] = 0;             // Distance to source is 0

  // Priority queue to store {distance, node}
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      pq;
  pq.push({0, source});

  // Measure time start
  auto start = high_resolution_clock::now();

  while (!pq.empty())
  {
    int u = pq.top().second; // Get the node with the smallest distance
    int d = pq.top().first;  // Get the distance of that node
    pq.pop();

    // If the distance in the queue is greater than the already found
    // shortest distance, skip
    if (d > dist[u])
      continue;

    // Explore the neighbors of node u
    for (const auto &edge : graph[u])
    {
      int v = edge.to;
      int weight = edge.weight;

      // Relaxation step
      if (dist[u] + weight < dist[v])
      {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});
      }
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

  vector<vector<Edge> > graph(n);

  // Input: Edges
  cout << "\nEnter the edges (u, v, weight):\n";
  for (int i = 0; i < e; ++i)
  {
    int u, v, weight;
    cin >> u >> v >> weight;
    addEdge(graph, u, v, weight);
  }

  cout << endl;

  // Display the graph
  displayGraph(graph);

  // Input: Source node
  cout << "\nEnter the source node: ";
  cin >> source;

  // Time taken for calculating the shortest paths
  int64_t totalTime;

  // Find shortest paths from the source node to all other nodes
  vector<int> dist = dijkstra(graph, source, totalTime);

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

  return 0;
}
