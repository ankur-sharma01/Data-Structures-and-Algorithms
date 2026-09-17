// GFG Kahn Algorithm : using BFS and DFS ---> DAG (Directed Acyclic Graph)

#include <vector>
#include <queue>
using namespace std;

vector<int> fun(int n, vector<vector<int>> edges) {
    // 1. Array tracking incoming edges count per node
    vector<int> indegree(n, 0);

    // 2. Directed Adjacency List
    vector<vector<int>> adj(n); 

    // Build graph and populate in-degrees
    for (int i = 0; i < edges.size(); i++) {
        int src = edges[i][0];
        int dest = edges[i][1];
        adj[src].push_back(dest);
        indegree[dest]++;
    }

    // 3. Queue to process nodes with 0 incoming dependencies
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> res;

    // 4. Process graph level by level
    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        res.push_back(currentNode);

        // Process all outward neighbors (currentNode -> neigh)
        for (int j = 0; j < adj[currentNode].size(); j++) {
            int neigh = adj[currentNode][j];
            indegree[neigh]--; // Remove dependency edge

            // If neighbor has 0 remaining dependencies, add to queue
            if (indegree[neigh] == 0) {
                q.push(neigh);
            }
        }
    }

    // 5. Cycle check: if res does not contain all n nodes, a cycle exists
    if (res.size() != n) {
        return {};
    }

    return res;
}