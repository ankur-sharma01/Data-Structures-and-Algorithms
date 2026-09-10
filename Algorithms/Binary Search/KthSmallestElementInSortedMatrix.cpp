// 378. Kth Smallest Element in a Sorted Matrix

// Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// You must find a solution with a memory complexity better than O(n2).

// Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
// Output: 13
// Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13


class Solution {
public:
    int fun(vector<vector<int>>& matrix, int n, int m, int guess) {
        int row = n-1;
        int col = 0;
        int count = 0;

        while(row >= 0 && col < m)
        {
            if(matrix[row][col] <=  guess)
            {
                count = count + row + 1;
                col++;
            } else
            {
                row--;
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = matrix[0][0], high = matrix[n-1][m-1];
        int res = -1;

        while(low <= high)
        {
            int guess = low + (high - low)/2;
            int ans = fun(matrix, n, m, guess);
            if(ans < k)
            {
                low = guess + 1;
            } else
            {
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
};