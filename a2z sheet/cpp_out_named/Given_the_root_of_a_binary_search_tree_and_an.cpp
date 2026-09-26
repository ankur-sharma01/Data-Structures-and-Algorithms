/*
 * QUESTION:
 *
 * Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
 *
 * Explanation:
 * - We are using two stacks, one for the left traversal and one for the right traversal of the BST.
 * - The next() function returns the next smallest element in the BST by popping the top element from the left stack and pushing all the leftmost nodes in its right subtree to the stack.
 * - The before() function returns the next largest element in the BST by popping the top element from the right stack and pushing all the rightmost nodes in its left subtree to the stack.
 * - We use the two pointer
 *
 * Find it: https://www.google.com/search?q=Given%20the%20root%20of%20a%20binary%20search%20tree%20and%20an%20integer%20k%2C%20return%20true%20if%20there%20exist%20two
 */

// ---- write your solution below ----


