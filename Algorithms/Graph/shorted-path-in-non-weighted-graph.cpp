// GFG Shorted Part in Non-Weighted Graph:


vector<int> fun(vector<vector<int>>& edges, int n, int src) {
    // form adjacency matrix:
    vector<vector<int>> adj(n);
    for (int i = 0; i < edges.size(); i++)
    {
        int s = edges[i][0];
        int d = edges[i][1];
        adj[s].push_back(d);
        adj[d].push_back(s);
    }

    vector<int> res(n, -1);
    vector<int> vis(n, 0);
    queue<pair<int,int>> q;
    // pair is of {src node, distance}:
    q.push({src, 0});
    vis[src] = 1;
    while (!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        int currentNode = p.first;
        int distance = p.second;
        res[currentNode] = distance;
        
        for (int j = 0; j < adj[currentNode].size(); j++)
        {
            int neighbour = adj[currentNode][j];
            if (vis[neighbour] == 0)
            {
                q.push({neighbour, distance + 1});
                vis[neighbour] = 1;
            }
        }
    }
    return res;
}