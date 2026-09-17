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


// for directed:
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& adj, int currentNode, vector<bool>& path, vector<bool>& vis, bool& cycle) {
        // 1. Mark node visited globally and in active recursion stack
        vis[currentNode] = true;
        path[currentNode] = true;

        for (int j = 0; j < adj[currentNode].size(); j++) {
            int neighbour = adj[currentNode][j];

            // 2. Visited AND active in current path -> Back-edge found (CYCLE!)
            if (vis[neighbour] == true && path[neighbour] == true) {
                cycle = true;
                return;
            }

            // 3. Unvisited -> Recurse deeper
            if (vis[neighbour] == false) {
                dfs(adj, neighbour, path, vis, cycle); // Fixed: Removed 'n'
            }
        }

        // 4. Backtrack: Unmark node from active path when unwinding stack
        path[currentNode] = false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build Directed Adjacency List
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int dest = prerequisites[i][0];
            int src = prerequisites[i][1];
            adj[src].push_back(dest);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> path(numCourses, false);
        bool cycle = false;

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == false) {
                dfs(adj, i, path, vis, cycle);
            }
        }

        return !cycle; // Returns true if no cycle exists
    }
};


// No, `path[neigh]` will **not** get set back to `true` automatically once it is reset to `false`.

// Because arrays/vectors are stored in memory and passed by reference, setting `path[currentNode] = false` permanently mutates that value to `false` until another execution explicitly changes it.

// When recursion backtracks, the call stack pops off, but the memory changes in `path` persist.

// ---

// ### Dry Run: Cycle vs. Cross-Edge

// Let's trace two different graphs with 3 nodes to see the exact state of `vis` and `path` side-by-side.

// #### Graph A: Cross-Edge (No Cycle)

// Edges: $0 \to 1$, $0 \to 2$, $1 \to 2$

// ```text
//        (0)
//       /   \
//      v     v
//     (1) ──> (2)

// ```

// 1. **`dfs(0)`**: `vis[0]=T`, `path[0]=T`. Neighbor is `1`.
// 2. **`dfs(1)`**: `vis[1]=T`, `path[1]=T`. Neighbor is `2`.
// 3. **`dfs(2)`**: `vis[2]=T`, `path[2]=T`. No neighbors.
// * Backtrack `2`: `path[2] = false`.
// * Backtrack `1`: `path[1] = false`.

// 4. Control returns to `dfs(0)`. Next neighbor of `0` is `2`.
// 5. Check Node `2`:
// * `vis[2]` is `true`
// * `path[2]` is **`false`** (since it was reset during step 3!)
// * Condition `vis[2] && path[2]` evaluates to **`false`**. No cycle!

// ---

// #### Graph B: Directed Cycle

// Edges: $0 \to 1$, $1 \to 2$, $2 \to 0$

// ```text
//     (0) ──> (1)
//      ^       │
//      │       v
//     (2) <─── ┘

// ```
// 1. **`dfs(0)`**: `vis[0]=T`, `path[0]=T`. Neighbor is `1`.
// 2. **`dfs(1)`**: `vis[1]=T`, `path[1]=T`. Neighbor is `2`.
// 3. **`dfs(2)`**: `vis[2]=T`, `path[2]=T`. Neighbor of `2` is `0`.
// 4. Check Node `0`:
// * `vis[0]` is `true`
// * `path[0]` is **`true`** (Node `0` is still active up in the call stack waiting for `dfs(1)` and `dfs(2)` to finish!)
// * Condition `vis[0] && path[0]` evaluates to **`true`** $\rightarrow$ **Cycle Detected!**

// ### Key Takeaway

// `path[i]` stays `true` **only while node `i` is actively being explored in the current stack chain**. Once DFS finishes exploring all descendants of `i` and backtracks, `path[i]` is turned back to `false`.