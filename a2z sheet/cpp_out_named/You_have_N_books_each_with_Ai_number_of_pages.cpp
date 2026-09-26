/*
 * QUESTION:
 *
 * You have N books, each with Ai number of pages. M students need to be allocated contiguous books, with each student getting at least one book. Out of all the permutations, the goal is to find the permutation where the student with the most pages allocated to him gets the minimum number of pages, out of all possible permutations.
 *
 * Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order.
 *
 * Example:
 *
 * Input:
 * N = 4
 * A[] = {12,34,67,90}
 * M = 2
 * Output: 113
 * Explanation:
 * Allocation can be done in following ways:
 * {12} and {34, 67, 90} Maximum Pages = 191
 * {12, 34} and {67, 90} Maximum Pages = 157
 * {12, 34, 67} and {90} Maximum Pages = 113.
 * Therefore, the minimum of these cases is 113, which is selected as the output.
 *
 * Find it: https://www.google.com/search?q=You%20have%20N%20books%2C%20each%20with%20Ai%20number%20of%20pages.%20M%20students%20need%20to%20be%20allocated%20contiguous%20books%2C
 */

// ---- write your solution below ----


