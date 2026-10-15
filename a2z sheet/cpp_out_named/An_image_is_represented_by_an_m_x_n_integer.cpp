/*
 * QUESTION:
 *
 * An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
 *
 * You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
 *
 * To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
 *
 * Return the modified image after performing the flood fill.
 *
 * Example:
 *
 * Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 * Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
 * Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
 *
 * Find it: https://www.google.com/search?q=An%20image%20is%20represented%20by%20an%20m%20x%20n%20integer%20grid%20image%20where%20image%5Bi%5D%5Bj%5D%20represents%20the%20pixel%20value
 */

// ---- write your solution below ----

class Solution {
public:
    bool isValid(int r, int c, int n, int m) {
        if (r >= 0 && r < n && c >= 0 && c < m)
            return true;

        return false;
    }

    void dfs(vector<vector<int>>& image, int r, int c, int orignalColor, int color) {
        image[r][c] = color;

        // directional arrays for 4-way movement:
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};

        int n = image.size();
        int m = image[0].size();

        // traversing all the neighbours:
        for (int i = 0; i < 4; i++)
        {
            int rows = r + x[i];
            int cols = c + y[i];
            
            // boundary and visited checks:
            if (isValid(rows, cols, n, m) && image[rows][cols] == orignalColor)
            {
                dfs(image, rows, cols, orignalColor, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orignalColor = image[sr][sc];

        // edge case: if the starting point is already painted:
        if (orignalColor == color)
        {
            return image;
        }

        dfs(image, sr, sc, orignalColor, color);
        return image;
    }
};