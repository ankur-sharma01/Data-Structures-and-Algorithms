// LC 503

// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]

// BRUTE FORCE METHOD:

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1); // Default to -1 if no greater element exists

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                int circularIdx = (i + j) % n; // Wrap around to the start
                if (nums[circularIdx] > nums[i]) {
                    res[i] = nums[circularIdx];
                    break;
                }
            }
        }
        return res;
    }
};


// OPTIMAL SOL.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> res;

        for(int i = n-1; i >= 0; i--) {
            st.push(nums[i]);
        }

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            if(!st.empty()) {
                res[i] = st.top();
            }

            st.push(nums[i]);
        }
        return res;
    }
};