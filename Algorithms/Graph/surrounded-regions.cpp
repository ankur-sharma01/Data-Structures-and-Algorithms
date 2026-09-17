// lC 130. Surrounded Regions
// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
// To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.
// EXAMPLE:
// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]


class Solution {
public:
    bool valid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;

        return true;
    }

    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};

    void dfs(vector<vector<char>>& board, int n, int m, int i, int j) {
        board[i][j] = '#';

        for (int k = 0; k < 4; k++)
        {
            int row = i + x[k];
            int col = j + y[k];

            if (valid(row, col, n, m) && board[row][col] == 'O')
            {
                dfs(board, n, m, row, col);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        // fast I/O Operations:
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = board.size();
        int m = board[0].size();

        // first row:
        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O')
                dfs(board, n, m, 0, j);
        }
        // last row:
        for (int j = 0; j < m; j++)
        {
            if (board[n-1][j] == 'O')
                dfs(board, n, m, (n-1), j);
        }
        // first col:
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
                dfs(board, n, m, i, 0);
        }
        // last col:
        for (int i = 0; i < n; i++)
        {
            if (board[i][m-1] == 'O')
                dfs(board, n, m, i, (m-1));
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
                else
                {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};