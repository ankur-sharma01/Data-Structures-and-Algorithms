// LC 153. find minimum in rotated array!

// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.

// no. of times rotated is not given.

// we are creating part 1 and part 2. it can be distinguished easily as every element of part 1 is greater than part 2 if rotated.
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int res = 0;
        
        while(low <= high)
        {
            int guess = low + (high-low)/2;

            if(nums[guess] > nums[n-1]) // can't use nums[high for comparision as will fail for some cases at reaching the very first index.
            // nums = [2, 3, 5, 6, 7, 8, 9] --- dry run this for nums[high] instead of nums[n-1] to find the difference.
            {
                low = guess+1;
            }
            else
            {
                res = guess;
                high = guess-1;
            }
        }
        return nums[res];
    }
};