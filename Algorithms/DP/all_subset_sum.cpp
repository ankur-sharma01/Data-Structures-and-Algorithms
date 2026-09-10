// // Q. No. 416 --- partition subset sum

// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.


// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].

// ---> choice based question: so recursion will be used. Also for memoization dp will be used.

// recursive solution:
class Solution{
public:

    int fun(vector<int> &nums, int &n, int current, int sum, vector<vector<int>> &dp) {
        
        // base case:
        if(current == n) {
            if(sum == 0) {
                return true;
            } else {
                return false;
            }
        }
        if(dp[current][sum] != -1) {
            return dp[current][sum];
        }
        if(nums[current] > sum) {
            return dp[current][sum] = fun(nums, n, current + 1, sum, dp);
        }

        int c1 = fun(nums, n, current+1, sum-nums[current], dp);
        int c2 = fun(nums, n, current+1, sum, dp);

        return dp[current][sum] = c1 || c2;
    }

    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        int current = 0;
        int totalsum = 0;
        for(int i = 0; i < n; i++) {
            totalsum = totalsum + nums[i];
        }
        if(totalsum % 2 != 0) return false;
        int sum = totalsum/2;
        
        vector<vector<int>> dp(n+1);
        for(current = 0; current <= n; current++) {
            vector<int> t(sum+1, -1);
            dp[current] = t;
        }

        return fun(nums, n, 0, sum, dp);
    }
};

// tabulation method:

class Solution{
public:
    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        int totalsum = 0;
        int i = 0, j = 0;
        vector<vector<int>> dp(n+1);

        for(int i = 0; i < n; i++) {
            totalsum += nums[i];
        }

        if(totalsum % 2 != 0) return false;

        int sum = totalsum/2;

        for(i = 0; i <= n; i++) {
            // creating a 2D vector:
            vector<int> t(sum+1, -1);
            dp[i] = t;
        }

        // base case:
        for(j = 0; j <= sum; j++) {
            dp[n][j] = 0;
            dp[n][0] = 1;
        }

        for(i = n-1; i >= 0; i--){
            for(j = 0; j <= sum; j++) {
                if(nums[i] > j) {
                    // skip the current one: (i+1)
                    dp[i][j] = dp[i+1][j];
                } else{
                    dp[i][j] = dp[i+1][j - nums[i]] || dp[i+1][j];
                }
            }
        }
        return dp[0][sum];
    }
};


// count subset sum:    GFG
class Solution{
public:
    int perfectSum(vector<int> &arr, int target) {
        int n = arr.size();
        int i = 0, j = 0;
        int mod = 1e9 + 7; // just for competitve programming and can be ignored in real life.
        vector<vector<int>> dp(n+1);

        for(i = 0; i <= n; i++) {
            // creating a 2D vector:
            vector<int> t(target+1, 0);
            dp[i] = t;
        }

            // base case:
            // dp[n][j] = 0;
            dp[n][0] = 1;
        

        for(i = n-1; i >= 0; i--){
            for(j = 0; j <= target; j++) {
                if(arr[i] > j) {
                    // skip the current one: (i+1)
                    dp[i][j] = dp[i+1][j] % mod;
                } else{
                    dp[i][j] = (dp[i+1][j - arr[i]] + dp[i+1][j]) % mod;
                }
            }
        }
        return dp[0][target];
    }
};


// target sum: 494 leetcode

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int n = nums.size();
        int i = 0, j = 0;
        int mod = 1e9 + 7;
        
        int totalSum = 0;
        for(int x : nums) {
            totalSum += x;
        }

        // 1. Validate edge cases before doing anything else
        if (totalSum < abs(target)) return 0;
        if ((totalSum + target) % 2 != 0) return 0;

        // 2. Safely compute reqSum:
        // using mathematics we get:
        // freq(positive) - freq(negative) = target
        // freq(positive) + freq(negative) = totalSum
        //subtracting these 2 equations we get: where reqSum = freq(positive)
        int reqSum = (totalSum + target) / 2;

        // 3. Allocate the matrix
        vector<vector<int>> dp(n + 1);
        for(i = 0; i <= n; i++) {
            vector<int> t(reqSum + 1, 0);
            dp[i] = t;
        }

        // 4. Seed the base case AFTER allocation is finished
        dp[n][0] = 1;

        // 5. Main loop execution
        for(i = n - 1; i >= 0; i--){
            for(j = 0; j <= reqSum; j++) {
                if(nums[i] > j) {
                    dp[i][j] = dp[i + 1][j] % mod;
                } else {
                    dp[i][j] = (dp[i + 1][j - nums[i]] + dp[i + 1][j]) % mod;
                }
            }
        }
        return dp[0][reqSum];
    }
};