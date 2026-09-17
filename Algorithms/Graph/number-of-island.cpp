// LC 200. Number of Islands
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
// EXAMPLE:
// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1


class Solution {
public:
    bool valid(int row, int col, int n, int m) {
        if (row < 0 || row >= n || col < 0 || col >= m)
            return false;

        return true;
    }

    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    void dfs(vector<vector<char>>& grid, int n, int m, int i, int j, vector<vector<bool>>& vis) {

        vis[i][j] = 1;
        
        for (int k = 0; k < 4; k++)
        {
            int row = i + x[k];
            int col = j + y[k];

            if (valid(row, col, n, m) && grid[row][col] == '1' && vis[row][col] == 0)
            {
                dfs(grid, n, m, row, col, vis); // making every connected matrix's vis 1 so no duplicate count happens!!
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        int i, j;
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    dfs(grid, n, m, i, j, vis);
                    res++;
                }
            }
        }
        return res;
    }
};