#include <bits/stdc++.h>
using namespace std;

// Define a structure to represent an edge of the graph
struct Edge {
    int u, v, w;
};

// Define a function to compare two edges by their weights (used for sorting)
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

// Define a function to find the parent of a node in the disjoint-set data structure
int find(int u, int parent[]) {
    if (u == parent[u]) // If u is the root of its set, return u
        return u;
    return parent[u] = find(parent[u], parent); // Otherwise, find the parent of u's parent recursively
}

// Define a function to merge two sets in the disjoint-set data structure
void merge(int u, int v, int parent[], int rank[]) {
    // Find the parent of u and the parent of v
    int p1 = find(u, parent);
    int p2 = find(v, parent);
    // If the two nodes are already in the same set, return
    if (p1 == p2)
        return;
    // Otherwise, merge the two sets by making the parent with the lower rank the parent of the other
    if (rank[p1] < rank[p2])
        parent[p1] = p2;
    else if (rank[p2] < rank[p1])
        parent[p2] = p1;
    else {
        parent[p1] = p2;
        rank[p2]++;
    }
}

// Define a function to find the MST of the given graph using Kruskal's algorithm
void kruskal(Edge edges[], int m, int n) {
    // Sort the edges in non-decreasing order of weight
    sort(edges, edges + m, cmp);

    // Initialize the parent and rank arrays for the disjoint-set data structure
    int parent[n], rank[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Initialize the MST and its weight
    Edge mst[n - 1];
    int mst_weight = 0;

    // Iterate over the sorted edges and add them to the MST if they don't create a cycle
    int i = 0, j = 0;
    while (i < n - 1 && j < m) {
        Edge e = edges[j++];
        if (find(e.u, parent) != find(e.v, parent)) {
            mst[i++] = e;
            merge(e.u, e.v, parent, rank);
            mst_weight += e.w;
        }
    }

    // Output the edges of the MST and its weight
    cout << "Edges in MST: " << endl;
    for (Edge e : mst)
        cout << "(" << e.u << ", " << e.v << ", " << e.w << ")" << endl;
    cout << "MST weight: " << mst_weight << endl;
}

int main() {
    // Read in the number of vertices and edges
    int n, m;
    cin >> n >> m;

    // Read in the edges and store them in an array
    Edge edges[m];
    for (int i = 0; i < m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
}
    // Find the MST of the graph
