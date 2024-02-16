#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9; // define infinity as a large constant

vector<pair<int, int>> adj[100001]; // adjacency list to store the graph

void dijkstra(int s, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INF); // initialize all distances to infinity
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // print the shortest distances from the source node
    for (int i = 1; i <= n; ++i) {
        if (dist[i] != INF) {
            cout << "Shortest distance from " << s << " to " << i << " is " << dist[i] << endl;
        }
        else {
            cout << "No path from " << s << " to " << i << endl;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // add edge from u to v with weight w
        adj[v].push_back({u, w}); // add edge from v to u with weight w
    }

    int s;
    cin >> s;

    dijkstra(s, n);

    return 0;
}
