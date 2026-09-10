// LC 724
// 
// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11

class Solution {
    // main logic is that at any index: prefix[i] + nums[i] + suffix[i] = totalSum, where prefix and suffix are till i-1 and i+1 respectively.
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        int leftSum = 0;
        int rightSum = 0;

        for(int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        for(int i = 0; i < n; i++) {

            rightSum = totalSum - nums[i] - leftSum;

            if(leftSum == rightSum) return i;
            // updating leftSum later as needed to check rightSum at index 0.
            leftSum += nums[i];
        }
        return -1;
    }
};

