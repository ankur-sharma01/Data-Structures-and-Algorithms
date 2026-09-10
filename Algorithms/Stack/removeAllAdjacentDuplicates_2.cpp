// LC 1209: REMOVE ALL ADJACENT DUPLICATES 2

// Input: s = "deeedbbcccbdaa", k = 3
// Output: "aa"
// Explanation: 
// First delete "eee" and "ccc", get "ddbbbdaa"
// Then delete "bbb", get "dddaa"
// Finally delete "ddd", get "aa"

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<int> st;
        vector<int> res;
        int count = 0;
        int i = 0;
        
        while(i < n) {

            if(st.empty()) {
                st.push(s[0]);
                continue;
            }

            if(s[i] == s[i-1]) {
                count++;
                if(count == 3) {
                    i = i+3;
                    st.push(s[i]);
                }
                st.push(s[i]);
            } else {
                count = 0;
            }
            i++;
        }

    }
};



for(int i = 1; i < n; i++) {

    if(st.empty()) {
        st.push(s[0]);
    }

    if(s[i] == s[i-1]) {
        count++;
    }

    st.push[s[i]];


}

// optimal solution:

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char, int>> st;
        int i = 0;

        while(i < n) {
            if(st.empty() || st.top().first != s[i]) {
                st.push({s[i], 1});
            } else {
                st.top().second++;

                if(st.top().second == k) {
                    st.pop();
                }
            }

            i++;

        }

        string res = "";

        // while(!st.empty()) {
        //     res.append(st.top().second, st.top().first);
        //     st.pop();
        // }

        // OR

        while(!st.empty()) {
            pair<char, int> p = st.top();
            st.pop();
            
            while(p.second--) {
                res.push_back(p.first);
            }        
        }
        reverse(res.begin(), res.end());
        return res;
    }
};