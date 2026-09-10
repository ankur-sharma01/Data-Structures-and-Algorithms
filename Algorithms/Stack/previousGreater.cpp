// GFG - previous greater

// Input: arr[] = [10, 4, 2, 20, 40, 12]
// Output: [-1, 10, 4, -1, -1, 40]


class Solution {
public:
    vector<int> preGreaterEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;
        stack<int> st;
        
        for(int i = 0; i < n; i++) {

            while(!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            if(!st.empty()) {
                res[i] = st.top();
            }

            st.push(arr[i]);

        }

        return res;
    }
};

// previous smaller

class Solution {
public:
    vector<int> preSmallerEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        
        for(int i = 0; i < n; i++) {

            while(!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            if(!st.empty()) {
                res[i] = st.top();
            }

            st.push(arr[i]);

        }

        return res;
    }
};