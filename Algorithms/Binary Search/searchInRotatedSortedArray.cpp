// LC 33. Search in Rotated Sorted Array

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high)
        {
            int guess = low + (high-low)/2;

            if(nums[guess] == target)
            return guess;
            
            // part 1
            if(nums[guess] > nums[n-1])
            {
                if(nums[guess] < target)
                {
                    low = guess+1; // move right
                }
                else
                {
                    if(nums[guess] > target)
                    {
                        // move right
                        low = guess+1;
                    }
                    else
                    {
                        high = guess-1;
                    }
                }
            } 
            // part 2
            else
            {
                if(nums[guess] > target)
                {
                    high = guess-1;
                }
                else
                {
                    if(nums[n-1] < target)
                    {
                        high = guess-1;
                    }
                    else
                    {
                        low = guess+1;
                    }
                }
            }
            return guess;
        }
        return -1;
    }
};