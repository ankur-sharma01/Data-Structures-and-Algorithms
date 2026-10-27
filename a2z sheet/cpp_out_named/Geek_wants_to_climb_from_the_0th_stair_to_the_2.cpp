/*
 * QUESTION:
 *
 * Geek wants to climb from the 0th stair to the (n-1)th stair. At a time, the Geek can climb either one or two steps.
 * A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i] - height[j]), where abs() means the absolute difference.
 * Return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.
 *
 * Find it: https://www.google.com/search?q=Geek%20wants%20to%20climb%20from%20the%200th%20stair%20to%20the%20%28n-1%29th%20stair.%20At%20a%20time%2C%20the%20Geek%20can
 */

// ---- write your solution below ----

int solve(int i, int n, const std::vector<int>& heights, std::vector<int>& dp) {
    // base case: last step don't need to jump further!!!
    if (i == (n-1)) return 0;
    if (i >= n) return INT_MAX;

    if (dp[i] != -1) return dp[i];

    // jumpOne & jumpTwo are two cost calculator:
    int jumpOne = INT_MAX, jumpTwo = INT_MAX;
    int jumpOne = abs(height[i+1] - height[i]) + solve(i+1, n, height, dp);
    int jumpTwo = abs(height[i+2] - height[i]) + solve(i+2, n, height, dp);

    return dp[i] = min(jumpOne, jumpTwo);
}

int minCost(int height[], int n) {
    // code here
    int n = height.size();
    if (n <= 0) return 0;

    vector<int> dp(n, -1);
    
    return solve(0, n, height, dp);
}
