// 1752

// 198 --- house robber


int fun(vector<int> &nums, int n, int currentPos, int taken, vector<vector<int>> &dp) {
    n = nums.size();
    if(currentPos == n) return 0;

    if(dp[currentPos][taken] != -1) {
        return dp[currentPos][taken];
    }

    if(taken == 0) return dp[currentPos][taken] = fun(nums, n, currentPos+1, 1);

    int c1 = nums[currentPos] + fun(nums, n, currentPos+1, 0);
    int c2 = nums[currentPos] + fun(nums, n, currentPos+1, 1);

    return dp[currentPos][taken] = max(c1, c2);
}

int rob(vector<int> &nums) {
    int n = nums.size();
    // creating a 2d vector for storing dp(current position(i), and is it taken(freeWill)):
    vector<vector<int>> dp(n);

    // initialising all the dp member to -1.
    for(int i = 0; i < n; i++){
        vector<int> t(2, -1);
        dp[i] = t;
    }

    return fun(nums, n, 0, 1, dp);
}

// fixed version --- from gemini.

// do look for iterations on gemini.

// while passing the function, we take future into consideration(value next to the current position).
// we are storing in dp after getting for each value pair.
class Solution {
public:
    int fun(vector<int> &nums, int currentPos, int prevRobbed, vector<vector<int>> &dp) {
        // 1. FIXED BASE CASE: Safely catches when we cross the finish line
        if(currentPos >= nums.size()) return 0;

        if(dp[currentPos][prevRobbed] != -1) {
            return dp[currentPos][prevRobbed];
        }

        // 2. FIXED TRANSITION: If previous was robbed, we CANNOT rob this one.
        // We must move to next house, and set prevRobbed flag to 0 (since we skipped this one).
        if(prevRobbed == 1) {
            return dp[currentPos][prevRobbed] = fun(nums, currentPos + 1, 0, dp);
        }

        // 3. FIXED CHOICES: If previous was skipped, we have two options:
        // Option 1: Rob this house. Gain cash, move to next, set flag to 1.
        int rob = nums[currentPos] + fun(nums, currentPos + 1, 1, dp);
        
        // Option 2: Skip this house. Gain 0, move to next, set flag to 0.
        int skip = 0 + fun(nums, currentPos + 1, 0, dp);

        return dp[currentPos][prevRobbed] = max(rob, skip);
    }

    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        // Initializing the 2D DP table cleanly
        vector<vector<int>> dp(n, vector<int>(2, -1));

        // Start at house 0, with prevRobbed = 0 (since no house before 0 exists)
        return fun(nums, 0, 0, dp);
    }
};