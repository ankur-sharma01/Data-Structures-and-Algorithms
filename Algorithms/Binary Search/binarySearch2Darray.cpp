// 74. Search a 2D Matrix
// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true


// Sorted matrix -- heap or binary search, Unsorted matrix -- graph

// Brute force approach:
// TODO: find row using binary search and then apply another binary search inside the row.

// Optimal approach: for any number to find if we mod the number by total no. of elements in a row, we get coloumn and by dividing we get row.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = n*m - 1;
        while(low<=high)
        {
            int guess = low + (high - low)/2;
            int row = guess/m;
            int col = guess%m;

            if(matrix[row][col] == target) return true;
            if(matrix[row][col] < target)
            {
                low = guess + 1;
            } else
            {
                high = guess - 1;
            }
        }
        return false;
    }
};