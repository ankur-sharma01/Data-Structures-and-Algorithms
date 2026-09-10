#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();

    // dp[r][c][cost] = max score
    // Initialize with -1 to indicate unreachable states
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

    // Starting cell (0,0)
    int startVal = grid[0][0];
    int startCost = (startVal == 0) ? 0 : 1;
    if (startCost <= k) {
        dp[0][0][startCost] = startVal;
    }

    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            for (int currentCost = 0; currentCost <= k; ++currentCost) {
                if (dp[r][c][currentCost] == -1) continue;

                // Move Right
                if (c + 1 < n) {
                    int nextVal = grid[r][c + 1];
                    int nextCost = currentCost + (nextVal == 0 ? 0 : 1);
                    if (nextCost <= k) {
                        dp[r][c + 1][nextCost] = max(dp[r][c + 1][nextCost], dp[r][c][currentCost] + nextVal);
                    }
                }

                // Move Down
                if (r + 1 < m) {
                    int nextVal = grid[r + 1][c];
                    int nextCost = currentCost + (nextVal == 0 ? 0 : 1);
                    if (nextCost <= k) {
                        dp[r + 1][c][nextCost] = max(dp[r + 1][c][nextCost], dp[r][c][currentCost] + nextVal);
                    }
                }
            }
        }
    }

    // Find the max score at the destination (m-1, n-1) across all possible costs <= k
    int maxScore = -1;
    for (int c = 0; c <= k; ++c) {
        maxScore = max(maxScore, dp[m - 1][n - 1][c]);
    }
s
    return maxScore;
}

int main() {
    vector<vector<int>> mat = {{0, 1, 4}, {1, 2, 1}, {0, 0, 1}};
    int k = 8;
    cout << "Maximum Score: " << solve(mat, k) << endl;
    return 0;
}