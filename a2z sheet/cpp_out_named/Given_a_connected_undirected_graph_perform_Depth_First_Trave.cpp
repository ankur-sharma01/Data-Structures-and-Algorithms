/*
 * QUESTION:
 *
 * Given a connected undirected graph, perform Depth First Traversal (DFS) of the graph starting from vertex 0 and visit all the nodes directly or indirectly connected to Node 0.
 *
 * Explanation:
 * - We initialize an empty vector 'ans' to store the DFS traversal.
 * - We also initialize a vector 'vis' to keep track of visited nodes, initialized with 'false' for all nodes.
 * - We start DFS from vertex 0 by calling the recursive function 'dfs'.
 * - In the 'dfs' function, we push the current node into the 'ans' vector and mark it as visited.
 * - For each adjacent vertex of the current node, if it has not been visited, we call the 'dfs' function recursively for that vertex.
 * - We continue this process until all connected nodes are visited.
 * - Finally, we return the 'ans' vector containing the DFS traversal.
 *
 * Find it: https://www.google.com/search?q=Given%20a%20connected%20undirected%20graph%2C%20perform%20Depth%20First%20Traversal%20%28DFS%29%20of%20the%20graph%20starting%20from%20vertex%200%20and
 */

// ---- write your solution below ----


