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

// logic: The Golden RuleAggressive Cows $\rightarrow$ Search space is Possible Answers (numbers/distances).Find Peak Element $\rightarrow$ Search space is Array Indices (positions).Why we use low = guess + 1 in both (The Difference)1. Aggressive Cows (Binary Search on Answer)What guess means: A tested distance (e.g., "Can we place cows 5 units apart?").Why we use low = guess + 1:guess worked! It is a valid answer.But we want to find an even bigger/better distance.We save guess in res, then throw it away and look higher: low = guess + 1.2. Find Peak Element (Slope-Based Search)What guess means: An array index.Why we use low = guess + 1:guess failed! The slope is going uphill to the right (nums[guess] < nums[guess + 1]), meaning guess is definitely not a peak.We throw it away and search the right side: low = guess + 1.

// ---- write your solution below ----

// logic for this question is that we can use linear search for the top to bottom i.e. row & binary search for left to right i.e. colounms.
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0, high = n-1;

        while (low <= high)
        {
            int midCol = low + (high - low)/2;
            int maxRow = 0;
            for (int i = 0; i < m; i++)
            {
                if (mat[i][midCol] > mat[maxRow][midCol])
                {
                    maxRow = r;
                }
            }

            bool leftBigger = (midCol > 0 && mat[maxRow][midCol - 1] > mat[maxRow][midCol]);
            bool rightBigger = (midCol < n-1 && mat[maxRow][midCol + 1] > mat[maxRow][midCol]);

            if (!leftBigger && !rightBigger)
            {
                return {maxRow, midCol};
            }
            else if (rightBigger)
            {
                left = midCol + 1;
            }
            else
            {
                right = midCol - 1;
            }
        }
        return {};
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