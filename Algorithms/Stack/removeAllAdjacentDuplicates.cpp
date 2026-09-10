// LC 1047

// Example 1:

// Input: s = "abbaca"
// Output: "ca"
// Explanation: 
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

class Solution {
public:

    string removeDuplicates(string s) {
        int n = s.size();
        stack<char> st;
        string res;
        int i;
        for(i = 0; i < n; i++) {
            if(st.empty()) {
                st.push(s[i]);
                continue;
            }
            if(st.top() == s[i]) {
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};