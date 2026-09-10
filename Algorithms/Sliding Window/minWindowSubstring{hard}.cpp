// 76. Minimum Window Substring

// // Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// // The testcases will be generated such that the answer is unique.

// // Example 1:

// // Input: s = "ADOBECODEBANC", t = "ABC"
// // Output: "BANC"
// // Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

class Solution {
public:
    string minWindow(string s, string t) {
        int min_size = MAX_INT;
        int low = 0, high = 0;
        unordered_map<char, int> freq;

        // increasing freq. of the character from the t so that we can check it while traversing in s.
        for(int i = 0; i < t.size(); i++) {
            freq[t[i] - 'A']++;
        }

        // doing operation in s:
        for(high = 0; high < s.size(); high++){
            if(freq)
            while(freq[s[low] - 'A'] > 1){
                freq[s[low] - 'A']--;
                low++;

            }

            
        }
    }
};


// optimal solution

class Solution{
public:

    bool isRight(vector<int> &have, vector<int> &needed) {
        for(int i = 0; i < 256; i++) {
            if(have[i] < needed[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int high = 0, low = 0;
        int n = s.size();

        // hashmap for storing freq of chars appearing in the t string:
        vector<int> needed(256, 0);

        // vector for watching the freq while traversing string s, so we can have a count of all elements within the range and also finding if we have all the elements:
        vector<int> have(256, 0);

        int start = 0;
        int result = INT_MAX;

        for(int i = 0; i < t.size(); i++) {
            needed[t[i]]++;
        }

        for(high = 0; high < n; high++){
            
            have[s[high]]++;

            while(isRight(have, needed)) {

                int length = high - low + 1;

                if(result > length) {
                    result = length;
                    // how to define string? : starting point + length of string.
                    start = low;
                    
                }
                have[s[low]]--;
                low++;
            }
        }
        if(result == INT_MAX) return "";

        return s.substr(start, result);
    }
};