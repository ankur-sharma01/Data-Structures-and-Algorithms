// 240. Search a 2D Matrix II
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// Output: true


// elimination technique : eliminate rows and coloumns from one corner which has increasing and decreasing pair of numbers(from left bottom, or upper right).
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = n-1, col = 0;
        while(row >= 0 && col < m)
        {
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] > target)
            {
                row--;
            } else
            {
                col++;
            }
        }
        return false;
    }
};