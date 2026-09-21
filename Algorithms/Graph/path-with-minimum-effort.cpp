// LC 1631. Path With Minimum Effort
// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
// EXAMPLE:
// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
// This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.


class Solution {
public:
    bool valid(int r, int c, int n, int m) {
        if (r >= 0 && c >= 0 && r < n && c < m)
            return true;

        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res(n, vector<int> (m, INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};
        res[0][0] = 0;
        pq.push({0, {0,0}});

        while(!pq.empty())
        {
            pair<int, pair<int,int>> p = pq.top();
            pq.pop();
            int d = p.first;
            int row = p.second.first;
            int col = p.second.second;

            // Inside the while loop, right after popping from pq:
            if (row == n - 1 && col == m - 1) 
                return d;

            if (d > res[row][col])
                continue;

            for (int i = 0; i < 4; i++)
            {
                int r = row + x[i];
                int c = col + y[i];

                if (!valid(r, c, n, m))
                    continue;

                int absdiff = abs(heights[row][col] - heights[r][c]);
                int newwt= max(absdiff, d);

                if (newwt < res[r][c])
                {
                    res[r][c] = newwt;
                    pq.push({newwt, {r, c}});
                }
            }
        }
        return res[n-1][m-1];
    }
};