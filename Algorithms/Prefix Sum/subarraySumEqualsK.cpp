// LC 560: Subarray Sum Equals K

// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.


// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2

// brute force approach: make all subarrays, if sum == k increase count.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        // 1. Fix the starting element of the subarray
        for (int start = 0; start < n; start++) {
            int current_sum = 0;
            
            // 2. Expand the subarray to the right from 'start' to 'end'
            for (int end = start; end < n; end++) {
                current_sum += nums[end]; // Accumulate the sum on the fly
                
                // 3. If the current subarray matches the target, increment count
                if (current_sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};

// optimal sol. using prefix sum and hashmap.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int currentSum = 0;
        int count = 0;

        unordered_map<int,int> history;

        history[0] = 1;

        for(int i = 0; i < n; i++) {
            currentSum += nums[i];

            // "What did my total step count need to be in the past so that the distance between then and now is exactly k?"
            int target = currentSum - k;

            if(history.find(target) != history.end()) {
                count += history[target];
            }

            // Why dropping the cone (prefix_history[current_sum]++) is mandatory:Look back at Turn 2. When you were standing on square 7, you looked back and found a cone at square 0.If you had forgotten to drop a new cone on square 7 before moving away, that landmark is lost forever.If the next number in the array had been a 7 instead of a 3, your new position would be 14. To find a 7-step path from 14, you would look back 7 steps ($14 - 7 = 7$) and check your memory for a cone on square 7. If you didn't drop that cone on Turn 2, your code would say "No cone found!"—and you would completely miss a perfectly valid 7-step path.
            history[currentSum]++;
        }
        return count;
    }
};