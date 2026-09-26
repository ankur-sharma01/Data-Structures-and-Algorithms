/*
 * QUESTION:
 *
 * Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second, all nodes connected to a given node get burned. That is its left child, right child, and parent.
 * Note: The tree contains unique values.
 *
 * Example 1:
 * Input:
 *           1
 *         /   \
 *       2      3
 *     /  \      \
 *    4    5      6
 *        / \      \
 *       7   8      9
 *                    \
 *                    10
 *
 * Target Node = 8
 * Output: 7
 * Explanation: If the leaf with the value 8 is set on fire:
 * After 1 sec: 5 is set on fire.
 * After 2 sec: 2, 7 are set to fire.
 * After 3 sec: 4, 1 are set to fire.
 * After 4 sec: 3 is set to fire.
 * After 5 sec: 6 is set to fire.
 * After 6 sec: 9 is set to fire.
 * After 7 sec: 10 is set to fire.
 * It takes 7s to burn the complete tree.
 *
 * Find it: https://www.google.com/search?q=Given%20a%20binary%20tree%20and%20a%20node%20data%20called%20target.%20Find%20the%20minimum%20time%20required%20to%20burn%20the
 */

// ---- write your solution below ----


