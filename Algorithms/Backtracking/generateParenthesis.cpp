// LC 22. Generate Parentheses
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]


class Solution {
public:
    void fun(int open, int close, int n, string& tmp, vector<string>& res) {
        if(open == n && close == n)
        {
            res.push_back(tmp);
            return;
        }
        if(open < n)
        {
            tmp.push_back('(');
            fun(open+1, close, n, tmp, res);
            tmp.pop_back();
        }
        if(close < open)
        {
            tmp.push_back(')');
            fun(open, close+1, n, tmp, res);
            tmp.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string tmp = "";
        fun(0, 0, n, tmp, res);
        return res;
    }
};