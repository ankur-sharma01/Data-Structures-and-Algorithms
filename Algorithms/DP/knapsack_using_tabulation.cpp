class Solution{
public:

    int fun(vector<int> &val, vector<int> &weight, int n, int i, int capacity) {
        if(i == n) {
            return 0;
        }
        if(dp[i][capacity] != -1) {
            return dp[i][capacity];
        }
        if(capacity < weight[i]) {
            return dp[i][capacity] = fun(val, weight, n, i+1, capacity);
        }
    }
};

// for tabulation we will convert the dp logic to for loops:

// dp[i][capacity] = when no choice ---> dp[i][capacity]
//                 = when choice ---> max((val[i] + dp[i+1][capacity - weight[i]]), dp[i+1][capacity])

// we will reverse apply for loop.

int n = val.size();
vector<vector<int>> dp(n+1);
int current, capacity;

for(current = 0; current <= n, current++) {
    vector<int> t(capacity+1);
    dp[current] = t;
}

for(capacity = 0; capacity <= capacity; capacity++) {
    dp[n][capacity] = 0;
}

// we need to reverse fill the for loop as it requires advance values.
for(current = n-1; current >= 0; current--) {
    // you can reverse fill or forward fill as no advance next data is needed like [i+1].
    for(capacity = 0; capacity <= capacity, capacity++) {
        if(capacity < weight[current]) {
            dp[current][capacity] = d[current+1][capacity];
        } else {
            dp[current][capacity] = max((val[current] + dp[current+1][capacity - weight[current]]), dp[current+1][capacity]);
        }
    }
}
return dp[0][capacity];
