/*
 * QUESTION:
 *
 * A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
 *
 * Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
 *
 * You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
 *
 * You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
 *
 * Example 1:
 * Input: mat = [[1,4],[3,2]]
 * Output: [0,1]
 * Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
 *
 * Example 2:
 * Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
 * Output: [1,1]
 * Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
 *
 * Find it: https://www.google.com/search?q=A%20peak%20element%20in%20a%202D%20grid%20is%20an%20element%20that%20is%20strictly%20greater%20than%20all%20of%20its
 */

// ---- write your solution below ----

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
    }
};


// solution for find peak element in a array: LC 162
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int res = 0;

        while (low < high)
        {
            int guess = low + (high - low)/2;
            if (nums[guess] < nums[guess+1])
            {
                low = guess + 1;
            }
            else
            {
                high = guess;
            }
        }
        return high; // or return left as they will surely point to same index.
    }
};



class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Compare mid with its right neighbor
            if (nums[mid] < nums[mid + 1]) {
                // Slope is rising to the right -> Peak MUST be on the right
                left = mid + 1;
            } else {
                // Slope is falling to the right -> Peak is at mid or to the left
                right = mid;
            }
        }
        
        // When left == right, we are guaranteed to be at a peak element index
        return left;
    }
};
