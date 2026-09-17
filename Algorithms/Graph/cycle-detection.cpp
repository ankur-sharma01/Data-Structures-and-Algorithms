// adjacency list:
// Graph:
// 0 ── 1
// │  /
// │ /
// 2 ───3

// Adjacency List Representation:
// Index 0 -> [1, 2]
// Index 1 -> [0, 2]
// Index 2 -> [0, 1, 3]
// Index 3 -> [2]


// GFG Undirected Graph Cycle:
// Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.
// Note: The graph can have multiple component.
// EXAMPLE:
// Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
// Output: true


// undirected:
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& adj, int currentNode, int parent, vector<bool>& vis, bool& cycle) {
        // 1. Mark current node as visited
        vis[currentNode] = true;

        // 2. Explore all neighbors of currentNode
        for (int j = 0; j < adj[currentNode].size(); j++) {
            int neigh = adj[currentNode][j]; // Get the j-th connected neighbor

            // Case A: Neighbor visited AND NOT immediate parent -> Cycle!
            if (vis[neigh] == true && neigh != parent) {
                cycle = true;
            }

            // Case B: Neighbor unvisited -> Step into it recursively
            if (vis[neigh] == false) {
                // Pass 'neigh' as the new currentNode, and 'currentNode' as the new parent
                dfs(adj, neigh, currentNode, vis, cycle);
            }
        }
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        // 1. Build Adjacency List (V = nodes count)
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int src = edges[i][0];
            int dest = edges[i][1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }

        vector<bool> vis(V, false);
        bool cycle = false;

        // 2. Loop through all nodes to cover disconnected components
        for (int i = 0; i < V; i++) {
            if (vis[i] == false) {
                dfs(adj, i, -1, vis, cycle);
            }
        }

        return cycle;
    }
};