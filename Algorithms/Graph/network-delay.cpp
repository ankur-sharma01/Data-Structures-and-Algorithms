// LC 743. Network Delay Time
// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
// EXAMPLE:
// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // int n = times.size();
        vector<vector<pair<int,int>>> a(n+1); // indexed from 1
        // build adjacency list:
        for (int i = 0; i < times.size(); i++)
        {
            int s = times[i][0];
            int d = times[i][1];
            int w = times[i][2];
            a[s].push_back({d, w});
            // a[d].push_back({s, w}); --> it is a directed graph
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty())
        {
            pair<int,int> p = pq.top();
            pq.pop();
            int d = p.first;
            int node = p.second;
            if (d > dist[node])
                continue;

            for (int j = 0; j < a[node].size(); j++)
            {
                int neighbour = a[node][j].first;
                int wt = a[node][j].second;
                if (d != INT_MAX && (d + wt) < dist[neighbour])
                {
                    dist[neighbour] = d + wt;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }
        // find max:
        int max_element = -1;
        for (int i = 1; i < n+1; i++)
        {
            if (dist[i] == INT_MAX) return -1;
            max_element = max(dist[i], max_element);
        }
        return max_element;
    }
};