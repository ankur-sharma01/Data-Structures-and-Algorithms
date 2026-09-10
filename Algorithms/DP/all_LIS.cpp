// LIS - longest increasing subsequence

// {10, 2, 4, 3, 7, 7, 101, 18} --- valid LIS is {2, 4, 7, 101}, should be strictly increasing --- {2, 4, 7, 7, 101} - not valid

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int i = 0, j = 0;
        
        for(i = 0; i < n; i++) {
            result[i] = 1;
        }
        for(j = 0; j < i; j++) {
            if(a[j] < a[i]) {
                result[i] = max(result[i], result[j] + 1);
            }
        }
    }
};

class Solution{
public:
    int fun(vector<int> &nums, int n, int i, int prev, vector<vector<int>> &dp) {
        if(i == n) return 0;
        if(dp[i][prev+1] != -1) {
            return dp[i][prev+1];
        }

        if(prev == -1 || nums[i] > nums[prev]) {
            int c1 = 1 + fun(nums, n, i+1, i);
            int c2 = fun(nums, n, i+1, prev);

            return dp[i][prev+1] = max(c1, c2);
        }
        return dp[i][prev+1] = fun(nums, n, i+1, prev);
    }

    int lengthofLIS(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1)(n+1);
        return fun(nums, n, 0, prev, dp);
    }
};