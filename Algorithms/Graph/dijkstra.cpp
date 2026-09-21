// mix concepts of adjacency list, min heap, priority queue, weighted graph

adjacency matrix for weighted graph:
    each index contains pairs of {path,weight}.


vector<int> dijsktra(int n, vector<vector<int>>& edges, int src) {
    // making adjacency list:
    vector<vector<pair<int,int>>> a(n);

    for (int i = 0; i < edges.size(); i++)
    {
        int s = edges[i][0];
        int d = edges[i][1];
        int w = edges[i][2];
        a[s].push_back({d,w});
        a[d].push_back({s,w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // pair<int, int> (Type):
    // The elements stored in the queue are std::pair<int, int>. By convention in Dijkstra, we store {distance, node}.
    // vector<pair<int, int>> (Underlying Container):
    // std::priority_queue is an adapter, meaning it needs an underlying sequence container to store its data. C++ defaults to std::vector for this.
    // greater<pair<int, int>> (Comparator):
    // By default, std::priority_queue uses std::less, which creates a Max-Heap (largest element at the top).
    // Passing greater flips the ordering to create a Min-Heap (smallest element at the top).

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});
    
    while(!pq.empty())
    {
        pair<int,int> p = pq.top();
        pq.pop();
        int d = p.first;
        int currentNode = p.second;
        if (d > dist[currentNode])
            continue;

        for (int j = 0; j < a[currentNode].size(); j++)
        {
            int neigh = a[currentNode][j].first;
            int wt = a[currentNode][j].second;

            if (d != INT_MAX && (d + wt) < dist[neigh])
            {
                dist[neigh] = wt + d;
                pq.push({dist[neigh], neigh});
            }
        }
    }
    return dist;
}