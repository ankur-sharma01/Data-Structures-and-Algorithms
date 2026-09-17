// LC 994. Rotting Oranges
// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
// EXAMPLE:
// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.


// MULTI-SOURCE BFS:
class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    bool isValid(int row, int col, int n, int m) {
        if (row < 0 || row >= n || col < 0|| col >= m)
            return false;

        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        int time = 0;

        // pushing rotten oranges into the queue and counting fresh oranges:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        // main working loop:
        while (!q.empty() && fresh > 0)
        {
            time++;
            int s = q.size();
            while (s--)
            {
                pair<int,int> p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;

                for (int k = 0; k < 4; k++)
                {
                    int row = r + x[k];
                    int col = c + y[k];
                    
                    if (isValid(row, col, n, m) && grid[row][col] == 1)
                    {
                        q.push({row, col});
                        grid[row][col] = 2; // making it rotten
                        fresh--;
                    }
                }
            }
        }

        // outcome:
        if (fresh > 0)
            return -1;

        return time;
    }
};

//write all then prune design for database