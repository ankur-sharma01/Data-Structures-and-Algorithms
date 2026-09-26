/*
 * QUESTION:
 *
 * Given an n x n matrix 'isConnected' representing connections between cities (nodes), find the total number of provinces in the graph.
 *
 * Explanation:
 * - The problem can be solved using Depth First Search (DFS).
 * - We first convert the given matrix 'isConnected' into an adjacency list 'adj' representing the graph.
 * - We use a 'vis' vector to keep track of visited cities, initialized to 'false' for all cities.
 * - We initialize a variable 'ans' to store the number of provinces.
 * - We then perform DFS from each city and mark all directly or indirectly connected cities as visited.
 * - We increment the 'ans' for each unvisited city and continue the process until all cities are visited.
 * - Finally, we return the 'ans' which represents the total number of provinces in the graph.
 *
 * Find it: https://www.google.com/search?q=Given%20an%20n%20x%20n%20matrix%20%27isConnected%27%20representing%20connections%20between%20cities%20%28nodes%29%2C%20find%20the%20total%20number%20of%20provinces
 */

// ---- write your solution below ----


