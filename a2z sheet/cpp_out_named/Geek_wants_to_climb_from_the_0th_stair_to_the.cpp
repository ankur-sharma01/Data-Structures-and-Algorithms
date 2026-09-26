/*
 * QUESTION:
 *
 * Geek wants to climb from the 0th stair to the (n-1)th stair. At a time, the Geek can climb k steps.
 * A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i] - height[j]), where abs() means the absolute difference.
 * Return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.
 *
 * Example:
 * Input:
 * 4 2
 * 10 40 30 10
 * Output:
 * 40
 *
 * Explanation:
 * For 'n' = 4, 'k' = 2, height = {10, 40, 30, 10}
 *
 * Initially, we are present at stone 1 having height 10. We can reach stone 3 as 'k' is 2. So, the cost incurred is |10 - 30| = 20.
 *
 * Now, we are present at stone 3, we can reach stone 4 as 'k' is 2. So, the cost incurred is |30 - 10| = 20. So, the total cost is 40. We can show any other path will lead to greater cost.
 *
 * Find it: https://www.google.com/search?q=Geek%20wants%20to%20climb%20from%20the%200th%20stair%20to%20the%20%28n-1%29th%20stair.%20At%20a%20time%2C%20the%20Geek%20can
 */

// ---- write your solution below ----


