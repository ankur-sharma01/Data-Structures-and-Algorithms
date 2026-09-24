// Prim's Algorithm

// minimum spanning tree

class Solution {
public:
    int mst(int n, vector<vector<int>>& edges) {
        // build adjacency list:
        vector<vector<pair<int,int>>> a(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int s = edges[i][0];
            int d = edges[i][1];
            int wt = edges[i][2];
            a[s].push_back({d, wt});
            a[d].push_back({s, wt});
        }
        int sum = 0;
        // min heap:
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0,0});

        while (!pq.empty())
        {
            pair<int,int> p = pq.top();
            pq.pop();
            int wt = p.first;
            int node = p.second;

            if (vis[node] == 1)
                continue;

            vis[node] = 1;
            sum = sum + wt;

            for (int j = 0; j < a[node].size(); j++)
            {
                int neighbour = a[node][j].first;
                int w = a[node][j].second;

                if (vis[neighbour] == 0)
                {
                    pq.push({w, neighbour});
                }
            }
        }
        return sum;
    }
}