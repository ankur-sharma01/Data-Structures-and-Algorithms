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
class Solution {    
public:
    int solve(int i, int k, vector<int>& heights, vector<int>& dp) {
        if (i == 0) return 0;

        if (dp[i] == -1) return dp[i];
        int minEnergy = INT_MAX;

        for (int j = 1; j <= k; j++)
        {
            if (i-j > 0)
            {
                int jumpCost = solve(i-j, k, heights, dp) + abs(heights[i] - heights[i-j]);
                minEnergy = min(minEnergy, jumpCost);
            }
        }

        return dp[i] = minEnergy;
    }

    int minimizeCost(int k, std::vector<int>& heights) {
        int n = heights.size();

        if (n <= 0) return 0;
        vector<int> dp(n, -1);

        return solve (n-1, k, heights, dp);
    }
};



// tabulation code:
class Solution {
public:
    int minimizeCost(int k, std::vector<int>& heights) {
        int n = heights.size();
        if (n <= 1) return 0;
        // If n = 0 (empty array): There are no stairs at all, so the geek doesn't need to (and can't) go anywhere.
        // If n = 1 (single stair): The geek starts at stair 0, and the destination is also n - 1 (1 - 1 = 0). Because the start and the finish are the same stair, the geek is already at the destination without taking a single jump.

        vector<int> dp(n, -1);
        dp[0] = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < k; j++)
            {
                if (i-j > 0)
                {
                    int jumpCost = dp[i-j] + abs(heights[i] - heights[i-j]);
                    // In the recursive memoized version, we needed a separate local variable called minEnergy because every recursive function call (solve(i)) was its own isolated workspace on the computer stack. It needed a temporary variable to figure out the answer before saving it into dp[i].
                    // In the tabulation version, we don't need a separate minEnergy variable because dp[i] itself does the exact same job!
                    dp[i] = min(dp[i], jumpCost);
                    // The inner loop tests multiple different incoming paths to reach stair i (e.g., jumping from i - 1, i - 2, all the way up to i - k).
                }
            }
        }
        return dp[n-1];;
    }
};