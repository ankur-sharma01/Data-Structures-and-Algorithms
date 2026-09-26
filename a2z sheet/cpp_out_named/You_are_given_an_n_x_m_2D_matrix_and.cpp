/*
 * QUESTION:
 *
 * You are given an n x m 2D matrix, and an array of size k denoting the number of operations. The matrix elements are 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0, which means there is no land in the matrix. The array has k operator(s) and each operator has two integers A[i][0], A[i][1], which means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to an island. Return how many islands are there in the matrix after each operation. You need to return an array of size k.
 * Note: An island means a group of 1s such that they share a common side.
 *
 * Example 1:
 * Input: n = 4, m = 5, k = 4, A = {{1,1},{0,1},{3,3},{3,4}}
 * Output: 1 1 2 2
 * Explanation:
 * 0.  00000
 *     00000
 *     00000
 *     00000
 * 1.  00000
 *     01000
 *     00000
 *     00000
 * 2.  01000
 *     01000
 *     00000
 *     00000
 * 3.  01000
 *     01000
 *     00000
 *     00010
 * 4.  01000
 *     01000
 *     00000
 *     00011
 *
 * Find it: https://www.google.com/search?q=You%20are%20given%20an%20n%20x%20m%202D%20matrix%2C%20and%20an%20array%20of%20size%20k%20denoting%20the%20number
 */

// ---- write your solution below ----


