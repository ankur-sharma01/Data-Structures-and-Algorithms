// LC 17. Letter Combinations of a Phone Number

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]



class Solution {
public:
    void fun(string& digits, int n, int idx, string& diary, unordered_map<char, string>& freq,vector<string>& res) {
        if(idx == n)
        {
            res.push_back(diary);
            return;
        }
        string choice = freq[digits[idx]];
        for(int j = 0; j < choice.size(); j++)
        {
            diary.push_back(choice[j]);
            fun(digits, n, idx+1, diary, freq, res);
            diary.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        
        unordered_map<char,string> freq;
        freq['2'] = "abc";
        freq['3'] = "def";
        freq['4'] = "ghi";
        freq['5'] = "jkl";
        freq['6'] = "mno";
        freq['7'] = "pqrs";
        freq['8'] = "tuv";
        freq['9'] = "wxyz";

        int n = digits.size();
        int idx = 0;
        string diary = "";
        vector<string> res;
        fun(digits, n, idx, diary, freq, res);
        return res;
    }
};