// LC 525: contagious array

// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

// EXAMPLE:
// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int zero = 0;
        int one = 0;
        unordered_map<int,int> f;
        // f[0] = 1; --- not needed.

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                zero++;
            } else {
                one++;
            }

            int diff = zero - one;

            // f[0] = -1;
                // or
            if(diff == 0) {
                result = max(result, i+1);
            }

            if(f.find(diff) != f.end()) {
                int idx = f[diff];
                int length = i - idx;
                result = max(length, result);
            } else {
                f[diff] = i;
            }
        }
        return result;
    }
};