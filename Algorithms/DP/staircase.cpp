class Solution {
private:
    // 2. 'i' is initialized here via the function parameter when called
    int fib(int i, int n, unordered_map<int, int>& dp) {
        if(i == n) return 1; 
        if(i > n)  return 0;
        
        if(dp.find(i) != dp.end()) return dp[i];
        
        // 3. 'i' changes its initialization value for the next branches!
        int a1 = fib(i + 1, n, dp); // Here, the next 'i' is initialized to i + 1
        int a2 = fib(i + 2, n, dp); // Here, the next 'i' is initialized to i + 2
        
        return dp[i] = a1 + a2;
    }

public:
    int climbStairs(int n) {
        unordered_map<int, int> dp;
        
        // 1. THIS IS WHERE WE INITIALIZE 'i' TO ZERO!
        // We kickstart the recursion by explicitly passing 0 as the starting step.
        return fib(0, n, dp); 
    }
};