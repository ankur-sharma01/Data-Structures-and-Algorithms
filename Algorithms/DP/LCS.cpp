// LC 1143:
// LCS --- longest common subsequence(non-contagious with maintained order)
// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.

class Solution{
public:

    int fun(string &text1, string &text2, int n, int m, int i, int j, vector<vector<int>> &dp) {
        // base case:
        if(i == n || j == m) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]) return dp[i][j] = 1+fun(text1, text2, n, m, i+1, j+1, dp);

        int c1 = fun(text1, text2, n, m, i+1, j, dp);
        int c2 = fun(text1, text2, n, m, i, j+1, dp);

        return dp[i][j] = max(c1, c2);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0, j = 0;
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1);
        for(int i = 0; i < n; i++) {
            vector<int> t(m+1, -1);
            dp[i] = t;
        }

        return fun(text1, text2, n, m, 0, 0, dp);
    }
};

// tabulation:
class Solution{
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int i = 0, j = 0;
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        // base case:
        for(i = 0; i <= n; i++) {
            dp[i][m] = 0;
        }
        for(j = 0; j <= m; j++) {
            dp[n][j] = 0;
        }
        
        for(i = n-1; i >= 0; i--) {
            for(j = m-1; j >= 0; j--) {
                if(text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};