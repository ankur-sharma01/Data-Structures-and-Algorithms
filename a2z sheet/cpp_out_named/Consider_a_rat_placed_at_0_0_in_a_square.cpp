/*
 * QUESTION:
 *
 * Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
 *
 * Example 1:
 *
 * Input:
 * N = 4
 * m[][] = {{1, 0, 0, 0},
 *          {1, 1, 0, 1},
 *          {1, 1, 0, 0},
 *          {0, 1, 1, 1}}
 * Output:
 * DDRDRR DRDDRR
 * Explanation:
 * The rat can reach the destination at
 * (3, 3) from (0, 0) by two paths - DRDDRR
 * and DDRDRR, when printed in sorted order
 * we get DDRDRR DRDDRR.
 *
 * Find it: https://www.google.com/search?q=Consider%20a%20rat%20placed%20at%20%280%2C%200%29%20in%20a%20square%20matrix%20of%20order%20N%20%2A%20N.%20It%20has
 */

// ---- write your solution below ----

class Solution{
public:
    void solve(int r, int c, vector<vector<int>>& m, int n, string path, vector<string>& ans, vector<vector<int>>& vis) {

        // base case: reached!
        if (r == n-1 && c == n-1)
        {
            ans.push_back(path);
            return;
        }

        string movDir = "DLRU";
        int x[4] = {1, 0, 0, -1};
        int y[4] = {0, -1, 1, 0};

        vis[r][c] = 1;

        for (int i = 0; i < n; i++)
        {
            int row = r + x[i];
            int col = c + y[i];

            if (row >= 0 && row < n && col >= 0 && col < n && m[row][col] == 1 && vis[r][c] != 1)
            {
                path.push_back[movDir[i]];
                solve(0, 0, m, n, path, ans, vis);
                path.pop_back();
            }
        }
        vis[r][c] = 0;
        return;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;

        // base case:
        if (m[0][0] == 0 || m[n-1][n-1] == 0)
            return ans;
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        string path = "";

        solve(0, 0, m, n, path, ans, vis);
        return ans;
    }
}
