// LC 409: Longest Palindrome

// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome.

// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.


class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char,int> f;

        for(int i = 0; i < n; i++) {
            f[s[i]]++;
        }

        bool odd = false;
        int res = 0;

        for(auto i : f) {
            int val = i.second;
            if(val % 2 == 0) {
                res += val;
            } else {
                odd = true;
            }
        }
        if(odd == false) return res;
        for(auto i : f) {
            int val = i.second;
            if(val % 2 == 1) {
                res += val - 1;
            }
        }
        return res + 1;
    }
};


// another short solution:
class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char,int> f;

        for(int i = 0; i < n; i++) {
            f[s[i]]++;
        }

        bool has_odd = false;
        int res = 0;

        for(auto i : f) {
            int val = i.second;
            if(val % 2 == 0) {
                res += val; // Fully use even counts
            } else {
                res += val - 1; // Take the even part out of the odd count (e.g., if 3, take 2)
                has_odd = true; // Mark that we have an extra character available for the center
            }
        }
        
        // FIXED: If we found any odd characters, place exactly ONE of them in the middle
        if(has_odd) {
            res += 1;
        }

        return res;
    }
};