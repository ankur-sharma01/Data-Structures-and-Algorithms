/*
 * QUESTION:
 *
 * Given a directed graph, perform Breadth First Traversal (BFS) of the graph starting from vertex 0 and visit all the nodes directly or indirectly connected to Node 0.
 *
 * Explanation:
 * - We initialize an empty vector 'ans' to store the BFS traversal.
 * - We also initialize a vector 'vis' to keep track of visited nodes, initialized with 'false' for all nodes.
 * - We use a queue 'q' to perform BFS. We start by pushing vertex 0 into the queue and mark it as visited.
 * - While the queue is not empty, we pop the front element and add it to the 'ans' vector.
 * - For each adjacent vertex of the current node, if it has not been visited, we push it into the queue and mark it as visited.
 * - We continue this process until the queue becomes empty and all connected nodes are visited.
 * - Finally, we return the 'ans' vector containing the BFS traversal.
 *
 * Find it: https://www.google.com/search?q=Given%20a%20directed%20graph%2C%20perform%20Breadth%20First%20Traversal%20%28BFS%29%20of%20the%20graph%20starting%20from%20vertex%200%20and%20visit
 */

// ---- write your solution below ----


