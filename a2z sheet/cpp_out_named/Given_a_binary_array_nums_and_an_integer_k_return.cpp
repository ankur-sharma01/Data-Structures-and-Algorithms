/*
 * QUESTION:
 *
 * Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
 *
 * Example 1:
 * Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * Output: 6
 * Explanation: [1,1,1,0,0,1,1,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 *
 * Find it: https://www.google.com/search?q=Given%20a%20binary%20array%20nums%20and%20an%20integer%20k%2C%20return%20the%20maximum%20number%20of%20consecutive%201%27s%20in%20the
 */

// ---- write your solution below ----

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // sliding window:
        int left = 0, right = 0;
        int n = nums.size();
        int maxLength = 0;
        int zeroCount = 0;

        for (right = 0; right < n; right++)
        {
            if (nums[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > k)
            {
                if (nums[left] == 0)
                    zeroCount--;

                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
