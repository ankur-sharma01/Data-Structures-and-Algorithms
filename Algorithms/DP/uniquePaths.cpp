// LC: 62

// Example 2:

// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down


// allowed paths are only right(n+1) and down(m+1): start at (0,0)

class Solution {
public:

    int fun(int m, int n, int i, int j, vector<vector<int>> &dp) {
        
        if(i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }

        if(i == m-1 && j == n-1) {
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = fun(m, n, i+1, j) + fun(m, n, i, j+1);
    }

    int uniquePaths(int m, int n) {
        int i = 0, j = 0;
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        
        return fun(m, n, 0, 0, dp);
    }
};

// tabulation:

class Solution {
public:
    int uniquePaths(int m, int n) {
        int i = 0, j = 0;
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        // base case:
        dp[m-1][n-1] = 1;

        for(i = 0; i <= m; i++) {
            dp[i][n] = 0;
        }
        for(j = 0; j <= n; j++) {
            dp[m][j] = 0;
        }

        for(i = m-1; i >= 0; i--) {
            for(j = n-1; j >= 0; j--) {
                if(i == m-1 && j == n-1) continue;
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }

        return dp[0][0];
    }
};