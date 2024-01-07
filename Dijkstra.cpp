#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Structure to represent an edge in the graph
struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

// Implementation of Dijkstra's algorithm
void dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& dist) {
    int n = graph.size();
    dist.assign(n, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const Edge& e : graph[u]) {
            int v = e.to;
            int w = e.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    // Example usage
    int n = 5; // Number of vertices
    vector<vector<Edge>> graph(n);

    // Add edges to the graph
    graph[0].emplace_back(1, 2);
    graph[0].emplace_back(2, 4);
    graph[1].emplace_back(3, 3);
    graph[2].emplace_back(3, 1);
    graph[3].emplace_back(4, 5);

    vector<int> dist;
    dijkstra(graph, 0, dist);

    // Print the shortest distances from the source
    for (int i = 0; i < n; ++i) {
        cout << "Shortest distance from 0 to " << i << ": " << dist[i] << endl;
    }

    return 0;
}

