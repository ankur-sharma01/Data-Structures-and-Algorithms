// LC 778. Swim in Rising Water
// You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

// It starts raining, and water gradually rises over time. At time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable.

// You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

// Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).
// EXAMPLE:
// Input: grid = [[0,2],[1,3]]
// Output: 3
// Explanation:
// At time 0, you are in grid location (0, 0).
// You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
// You cannot reach point (1, 1) until time 3.
// When the depth of water is 3, we can swim anywhere inside the grid.


// Approach 1:
// using binary search and BFS, altering boundaries according to conditions!!
class Solution {
public:
    bool valid(int r, int c, int n, int m) {
        if (r >= 0 && c >= 0 && r < n && c < m)
            return true;

        return false;
    }

    bool bfs(vector<vector<int>>& grid, int n, int m, int guess) {
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));
    
        // EDGE CASE MISSED:check whether the guess is bigger than the starting element as it will fail if not: eg. -> {{10,  0},{ 0,  0}}
        if (guess < grid[0][0]) return false;
        
        q.push({0,0});
        vis[0][0] = 1;

        while (!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;

            if (row == n-1 && col == m-1)
                return true;

            // explore neighbour:
            for (int k = 0; k < 4; k++)
            {
                int r = row + x[k];
                int c = col + y[k];

                if (valid(r, c, n, m) && vis[r][c] == 0 && guess >= grid[r][c])
                {
                    q.push({r, c});
                    vis[r][c] = 1;
                } 
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int low = 0; 
        int high = 0;
        // finding greatest element:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                high = max(high, grid[i][j]);
            }
        }
        int res = 0;
        while (low <= high)
        {
            int guess = low + (high - low)/2;
            if (bfs(grid, n, m, guess))
            {
                res = guess;
                high = guess - 1;
            } else
            {
                low = guess + 1;
            }
        }

        return res;
    }
};

// Approach 2:
// using Dijkstra Algorithm!! --> path with minimum effort
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
    }
};