// lC 121: BUY AND SELL STOCKS part 1 (EASY)

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

class Solution {
public:

    int fun(vector<int> &prices, int n, int currentPos, int transactionLeft, vector<vector<int>> &dp) {
        
        if(currentPos == n) return 0;
        if(transactionLeft == 0) return 0;
        if(dp[currentPos][transactionLeft] != -1) return dp[currentPos][transactionLeft];
        if(transactionLeft == 2) {
            int c1 = fun(prices, n, currentPos + 1, transactionLeft - 1, dp) - prices[currentPos];
            int c2 = fun(prices, n, currentPos + 1, transactionLeft, dp);
            return dp[currentPos][transactionLeft] = max(c1, c2);
        } else {
            int c1 = fun(prices, n, currentPos + 1, transactionLeft - 1, dp) + prices[currentPos];
            int c2 = fun(prices, n, currentPos + 1, transactionLeft, dp);
            return dp[currentPos][transactionLeft] = max(c1, c2);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int transactionLeft = 2;

        vector<vector<int>> dp(n + 1, vector<int> (transactionLeft + 1, -1));

        int gain = fun(prices, n, 0, transactionLeft, dp);
        
        return gain;
        
    }
};

// tabulation:

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minPrice = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                int currentProfit = prices[i] - minPrice;
                maxProfit = max(currentProfit, maxPorfit);
            }
        }
        return maxProfit;
    }
};

// LC 122:

class Solution {
public:

    int fun(vector<int> &prices, int n, int currentPos, int transactionLeft, vector<vector<int>> &dp) {
        
        if(currentPos == n) return 0;
        if(transactionLeft == 0) return 0;
        if(dp[currentPos][transactionLeft] != -1) return dp[currentPos][transactionLeft];
        if(transactionLeft == 2) {
            int c1 = fun(prices, n, currentPos + 1, transactionLeft - 1, dp) - prices[currentPos];
            int c2 = fun(prices, n, currentPos + 1, transactionLeft, dp);
            return dp[currentPos][transactionLeft] = max(c1, c2);
        } else {
            int c1 = fun(prices, n, currentPos + 1, 2, dp) + prices[currentPos];
            int c2 = fun(prices, n, currentPos + 1, transactionLeft, dp);
            return dp[currentPos][transactionLeft] = max(c1, c2);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int transactionLeft = 2;

        vector<vector<int>> dp(n + 1, vector<int> (transactionLeft + 1, -1));

        int gain = fun(prices, n, 0, transactionLeft, dp);
        
        return gain;
        
    }
};

// LC 123:

class Solution {
public:

    int fun(vector<int> &prices, int n, int currentPos, int transactionLeft, vector<vector<int>> &dp) {
        
        if(currentPos == n) return 0;
        if(transactionLeft == 0) return 0;
        if(dp[currentPos][transactionLeft] != -1) return dp[currentPos][transactionLeft];
        if(transactionLeft % 2 == 0) {
            int c1 = fun(prices, n, currentPos + 1, transactionLeft - 1, dp) - prices[currentPos];
            int c2 = fun(prices, n, currentPos + 1, transactionLeft, dp);
            return dp[currentPos][transactionLeft] = max(c1, c2);
        } else {
            int c1 = fun(prices, n, currentPos + 1, transactionLeft - 1, dp) + prices[currentPos];
            int c2 = fun(prices, n, currentPos + 1, transactionLeft, dp);
            return dp[currentPos][transactionLeft] = max(c1, c2);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int transactionLeft = 4;

        vector<vector<int>> dp(n + 1, vector<int> (transactionLeft + 1, -1));

        int gain = fun(prices, n, 0, transactionLeft, dp);
        
        return gain;
        
    }
};

// LC 188:

class Solution {
public:

    int fun(vector<int> &prices, int n, int currentPos, int transactionLeft, vector<vector<int>> &dp) {
        
        if(currentPos == n) return 0;
        if(transactionLeft == 0) return 0;
        if(dp[currentPos][transactionLeft] != -1) return dp[currentPos][transactionLeft];
        if(transactionLeft % 2 == 0) {
            int c1 = fun(prices, n, currentPos + 1, transactionLeft - 1, dp) - prices[currentPos];
            int c2 = fun(prices, n, currentPos + 1, transactionLeft, dp);
            return dp[currentPos][transactionLeft] = max(c1, c2);
        } else {
            int c1 = fun(prices, n, currentPos + 1, transactionLeft - 1, dp) + prices[currentPos];
            int c2 = fun(prices, n, currentPos + 1, transactionLeft, dp);
            return dp[currentPos][transactionLeft] = max(c1, c2);
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int transactionLeft = k * 2;

        vector<vector<int>> dp(n + 1, vector<int> (transactionLeft + 1, -1));

        int gain = fun(prices, n, 0, transactionLeft, dp);
        
        return gain;
        
    }
};