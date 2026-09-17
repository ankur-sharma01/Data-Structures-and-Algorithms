// LC 785. Is Graph Bipartite?
// used in Amazon: Bipartite Graph

// There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

// There are no self-edges (graph[u] does not contain u).
// There are no parallel edges (graph[u] does not contain duplicate values).
// If v is in graph[u], then u is in graph[v] (the graph is undirected).
// The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
// A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

// Return true if and only if it is bipartite.
// EXAMPLE: 
// Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
// Output: false
// Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.


class Solution {
public:
// graph here provided is adjacency list:

    void dfs(vector<vector<int>>& graph, int currentNode, int colorType, vector<int>& colors, bool& res) {
        // color the current node:
        colors[currentNode] = colorType;

        // check its neighbours:
        for (int i = 0; i < graph[currentNode].size(); i++) {
            int neighbour = graph[currentNode][i];

            // If neighbor is colored and has the same color -> Conflict!
            if (colors[neighbour] != -1 && colors[neighbour] == colorType) {
                res = false;
                return;
            }

            // If not colored -> recurse with opposite color
            if (colors[neighbour] == -1) {
                dfs(graph, neighbour, (1 - colorType), colors, res);
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        bool res = true;
        vector<int> colors(n, -1);

        // iterating over each component of graph as it can have more than one component or sub graph (two graphs):
        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                dfs(graph, i, 0, colors, res);
            }
        }
        return res;
    }
};