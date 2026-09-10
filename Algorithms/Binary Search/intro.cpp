// Binary search:

class Solution {
public:
    int binarySearch(vector<int> &nums, int target) {
        
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int res = -1;

        while(low <= high)
        {
            int guess = (low+high)/2;

            if(nums[guess] < target)
            {
                low = guess+1;
            }
            else if(nums[guess] > target)
            {
                high = guess-1;
            }
            else
            {
                res = guess;
                high = guess-1;
            }
            
        }
        return res;
    }
};