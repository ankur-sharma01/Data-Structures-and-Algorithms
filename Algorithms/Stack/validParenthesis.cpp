// lc 20

// Example 4:

// Input: s = "([])"

// Output: true

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0; i < n; i++) {

            if(s[i] == '[' || s[i] == '{' || s[i] == '(') {
                st.push(s[i]);
            } else {
                if (st.empty()) return false;
                
                char top = st.top();
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    st.pop(); // Perfect match, remove it
                } else {
                    return false; // Mismatched brackets
                }
            
            }
        }

        return st.empty();
    }
};



// 28 3 * * 1-5 cd /home/ubuntu/pulse && source venv/bin/activate && bash scripts/pulse_start.sh >> logs/cron.log 2>&1