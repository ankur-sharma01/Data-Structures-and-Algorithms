/*
 * QUESTION:
 *
 * Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.
 * The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).
 *
 * Example 1:
 * Input: N = 5
 * arr = {40, 20, 30, 10, 30}
 * Output: 26000
 * Explanation: There are 4 matrices of dimension
 * 40x20, 20x30, 30x10, 10x30. Say the matrices are
 * named as A, B, C, D. Out of all possible combinations,
 * the most efficient way is (A*(B*C))*D.
 * The number of operations are -
 * 20*30*10 + 40*20*10 + 40*10*30 = 26000.
 *
 * Find it: https://www.google.com/search?q=Given%20a%20sequence%20of%20matrices%2C%20find%20the%20most%20efficient%20way%20to%20multiply%20these%20matrices%20together.%20The%20efficient%20way
 */

// ---- write your solution below ----


