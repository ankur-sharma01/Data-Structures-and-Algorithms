/*
 * QUESTION:
 *
 * Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
 *
 * Explanation:
 * - We use a recursive function to traverse the binary tree in a bottom-up manner.
 * - At each node, we check if the left and right subtrees are binary search trees.
 * - If the current node satisfies the binary search tree condition (i.e., the value of the current node is greater than the maximum value in the left subtree and less than the minimum value in the right subtree), then we update the size of the largest subtree.
 * - We return a triplet containing the size of the subtree, the minimum value in the subtree, and the maximum value in the subtree.
 *
 * Find it: https://www.google.com/search?q=Given%20a%20binary%20tree.%20Find%20the%20size%20of%20its%20largest%20subtree%20that%20is%20a%20Binary%20Search%20Tree.%20Explanation%3A
 */

// ---- write your solution below ----


