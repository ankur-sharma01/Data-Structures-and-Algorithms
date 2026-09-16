// what will be provided? : list of edges and number of vertices.

vector<vector<int>> edges;
vector<vector<int>> mat;
for (int i = 0; i < n; i++) {
    vector<int> edge = edges[i];
    int src = edge[0];
    int dest = edge[1];
    mat[src][dest] = 1;
    mat[dest][src] = 1;
}

// adjacency list:
vector<vector<int>> adj[n];
// we take src as index and push value inside it which makes the destination part of it!
vector<vector<int>> edges;
for (int i = 0; i < n; i++) {
    vector<int> edge = edges[i];
    int src = edge[0];
    int dest = edge[1];
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}