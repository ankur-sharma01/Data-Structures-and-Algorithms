/*
 * QUESTION:
 *
 * Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum equal to the goal.
 *
 * Example 1:
 * Input: nums = [1,0,1,0,1], goal = 2
 * Output: 4
 * Explanation: The 4 subarrays are bolded and underlined below:
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 *
 * Find it: https://www.google.com/search?q=Given%20a%20binary%20array%20nums%20and%20an%20integer%20goal%2C%20return%20the%20number%20of%20non-empty%20subarrays%20with%20a%20sum
 */

// ---- write your solution below ----

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // h = {taget, no. of appearance}
        unordered_map<int,int> h;

        h[0] = 1;
        int currSum = 0;
        int count = 0;

        for (int num : nums)
        {
            currSum += num;
            int target = currSum - goal;

            if (h.find(target) != h.end())
                count += h[target];
            
            h[currSum]++;
        }
        return count;
    }
};

// sliding window optimization: using two pointers
class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int left = 0, sum = 0, count = 0;
        for (int right = 0; nums.size(), right++)
        {
            sum = sum + nums[right];
            while (sum > k)
            {
                sum = sum - nums[left];
                left++;
            }
            count = count + (right - left + 1);
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
};