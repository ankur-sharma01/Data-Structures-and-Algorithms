// used for array/subarray contingous -- sum/product/best/freq.
// sliding window didn't work for negative numbers.

// template:
// index by index --- all answer ending at this index
// two possible answer = previous best ans. + current or just current


// LC 53:

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int i = 0;
        int bestEndingAtI = nums[0], ans = nums[0];
        
        for(i = 1; i < n; i++) {
            
            int c1 = bestEndingAtI + nums[i];
            int c2 = nums[i];
            bestEndingAtI = max(c1, c2);

            ans = max(ans, bestEndingAtI);
        }
        return ans;
        // If you only return bestEnding, your code will only give you the maximum sum of a subarray that ends at the very last element of the array. If the best subarray occurred somewhere in the middle, you lose it.
    }
};


// LC 152:

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // we will create two endings i.e. max and min instead of best single ending. As when we multiply neg. with neg. answer is positive.

        int n = nums.size();
        int ans = nums[0];
        int maxEnding = nums[0];
        int minEnding = nums[0];

        for(int i = 1; i < n; i++) {
            int c1 = nums[i];
            int c2 = minEnding * nums[i];
            int c3 = maxEnding * nums[i];

            maxEnding = max(c1, max(c2, c3));
            minEnding = min(c1, min(c2, c3));

            ans = max(ans, max(maxEnding, minEnding));
        }
        return ans;
    }
};