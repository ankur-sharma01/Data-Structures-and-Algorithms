// LC 496: NEXT GREATER ELEMENT,,,,,, RE

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

// brute force solution:
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> res;

        for(int i = 0; i < n; i++) {
            int target = nums1[i];
            bool found = false;
            int nextGreater = -1;

            for(int j = 0; j < m; j++) {
                if(target == nums2[j]) {
                    found = true;
                }

                if(found && nums2[j] > target) {
                    nextGreater = nums2[j];
                    break;
                }
            }
            res.push_back(nextGreater);
        }
        return res;
    }
};


// optimal solution:
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        unordered_map<int,int> map;
        vector<int> res;

        for(int i = n-1; i >= 0; i--) {

            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if(!st.empty()) {
                map[nums2[i]] = st.top();
            } else {
                map[nums2[i]] = -1;
            }

            st.push(nums2[i]);
            
        }

        for(int i = 0; i < nums1.size(); i++) {
            res.push_back(map[nums1[i]]);
        }

        return res;

    }
};