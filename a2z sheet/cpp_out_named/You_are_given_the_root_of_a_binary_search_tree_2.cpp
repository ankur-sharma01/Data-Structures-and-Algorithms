/*
 * QUESTION:
 *
 * You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
 *
 * Explanation:
 * - We perform an in-order traversal of the BST to find the two nodes that are swapped.
 * - During the in-order traversal, we keep track of the previous node and compare it with the current node. If the current node is less than the previous node, then we have found the two swapped nodes.
 * - We swap the values of the two nodes to recover the BST.
 *
 * Find it: https://www.google.com/search?q=You%20are%20given%20the%20root%20of%20a%20binary%20search%20tree%20%28BST%29%2C%20where%20the%20values%20of%20exactly%20two%20nodes
 */

// ---- write your solution below ----


