// Dijkstra ---> struggles with negative

// fix ---> Bellman Ford Algorithm
// single src -> shortest path using all nodes, works for negative paths too, can be used for detection of negative cycle!

// more efficient!

// relaxation happens only for n-1 times, where n is total no. of nodes. More than one relaxation can happen at a time.

vector<int> bellman(int n, vector<vector<int>>& edges, int src) {
    // no adjacency list required: why? -> we have to relax edges without looking at the neighbours of a node.
    vector<int> res(n, INT_MAX);
    res[src] = 0;
    for (int i = 0; i < n-1; i++) // no. of times the relaxation should happen
    {
        for (int j = 0; j < edges.size(); j++) // relaxing all the nodes at once
        {
            int s = edges[j][0];
            int d = edges[j][1];
            int wt = edges[j][2];

            if (res[s] != INT_MAX && res[d] > res[s] + wt)
            {
                res[d] = res[s] + wt;
            }
        }
    }
    // for checking:
    for (int j = 0; j < edges.size(); j++)
    {
        int s = edges[j][0];
        int d = edges[j][1];
        int wt = edges[j][2];

        if (res[s] != INT_MAX && res[d] > res[s] + wt)
            return {-1};
    }
    return res;

}