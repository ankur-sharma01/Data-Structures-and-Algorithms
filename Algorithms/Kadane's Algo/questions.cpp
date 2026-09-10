// LC 1186 - Maximum Subarray Sum with One Deletion

// Input: arr = [1,-2,0,3]
// Output: 4
// Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int nodelete = arr[0];
        int onedelete = INT_MIN;
        int result = arr[0];

        if(n == 1) {
            return arr[0];
        }

        for(i = 1; i < n; i++) {
            int prevNoDelete = nodelete;
            int prevOneDelete = onedelete;       
            nodelete = max(nodelete + arr[i], arr[i]);
            int v2 = 0;
            if(prevOneDelete == INT_MIN) {
                // But physically, that's impossible! You can't have a deletion at or before index 0 because index 0 is the very first element. If you delete it, you have an empty subarray, which the problem explicitly forbids.

                // Because a past deletion doesn't exist yet, we have to invent a dummy definition for v2 at index 1 so the max() formula doesn't break down.
                v2 = arr[0];
            } else {
                v2 = prevOneDelete + arr[i];
            }
            onedelete = max(v2, prevNoDelete);
            result = max(result, max(onedelete, nodelete));
        }
        return result;
    }
};

// 

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        // 1. Initialize states OUTSIDE the loop so they persist
        int nodelete = arr[0];     // Standard Kadane's max ending here
        int onedelete = arr[0];    // Max ending here with 1 element deleted
        int result = arr[0];       // Global max scoreboard

        for(int i = 1; i < n; i++) {
            int prevNoDelete = nodelete;
            
            // Choice A: Standard Kadane (Extend old streak or start a fresh one here)
            nodelete = max(prevNoDelete + arr[i], arr[i]);
            
            // Choice B: Update the one-deletion state. Two sub-choices:
            // 1. (onedelete + arr[i]) -> Keep the old deletion and accept current element.
            // 2. (prevNoDelete)       -> Keep the old streak up to now, but delete current element.
            onedelete = max(onedelete + arr[i], prevNoDelete);
            
            // Update our overall best maximum found anywhere so far
            result = max(result, max(nodelete, onedelete));
        }
        
        return result;
    }
};

// LC 918: Maximum Sum Circular Subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int bestEnding = nums[0];

        int sumOfAll = 0;
        for(int i = 0; i < n; i++) {
            sumOfAll += nums[i];
        }
        int maxSum = nums[0];
        for(int i = 1; i < n; i++) {
            int c1 = bestEnding + nums[i];
            int c2 = nums[i];
            bestEnding = max(c1, c2);
            maxSum = max(maxSum, bestEnding);
        }
        bestEnding = nums[0];
        int minSum = nums[0];
        for(int i = 1; i < n; i++) {
            int c1 = bestEnding + nums[i];
            int c2 = nums[i];
            bestEnding = min(c1, c2);
            minSum = min(minSum, bestEnding);
        }
        if(maxSum < 0) return maxSum;
        return max((sumOfAll - minSum), maxSum);
    }
};