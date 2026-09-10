// LC 387: FIRST UNIQUE CHARACTER IN A STRING

// Input: s = "loveleetcode"

// Output: 2


class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        int n = s.size();
        // int count = 0;

        for(int i = 0; i < n; i++) {
            map[s[i]]++;
        }

        for(int i = 0; i < n; i++) {
            if(map[s[i]] == 1) {
                return i;
            }
        }

        return -1;

    }
};


// LC 383: RANSOME NOTE

// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.
// Input: ransomNote = "a", magazine = "b"
// Output: false


class Solution {
public:
    bool fun(unordered_map<char,int> &have, unordered_map<char,int> &need) {
        for(auto i : need) {
            char c = i.first;
            int fhave = have[c];
            int fneed = i.second;

            if(fhave < fneed) return false;
        }
        return true;
    }

    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
            int m = magazine.size();
            unordered_map<char,int> have;
            unordered_map<char,int> need;

            for(int i = 0; i < n; i++) {
                need[ransomNote[i]]++;
            }
            for(int i = 0; i < m; i++) {
                have[magazine[i]]++;
            }

            return fun(have, need);
    }
};


// space optimised solution:

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int counts[26] = {0}; // Fixed-size array for 'a' through 'z'
        
        // Count what we HAVE
        for (char c : magazine) {
            counts[c - 'a']++;
        }
        
        // Check what we NEED
        for (char c : ransomNote) {
            counts[c - 'a']--;
            if (counts[c - 'a'] < 0) {
                return false; // We don't have enough of this character!
            }
        }
        
        return true;
    }
};


// LC 1189: Maximum Number of Balloons

// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that can be formed.
// Input: text = "nlaebolko"
// Output: 1

class Solution {
public:
    int fun(unordered_map<char,int> have, unordered_map<char,int> need) {
        
        int res = INT_MAX;

        for(auto i : need) {
            int c = i.first;
            int fhave = have[c];
            int fneed = i.second;
            int count = fhave/fneed;
            res = min(res, count);
        }
        return res;
    }

    int maxNumberOfBalloons(string text) {
        int n = text.size();
        string b = "balloon";
        int m = b.size();
        unordered_map<char,int> have;
        unordered_map<char,int> need;

        for(int i = 0; i < n; i++) {
            have[text[i]]++;
        }
        for(int i = 0; i < m, i++) {
            need[b[i]]++;
        }

        return fun(have, need);
    }
};

// another solution:
int maxNumberOfBalloons(string text) {
    int count[26] = {0};

    for(auto i : text) {
        count[text[i-'a']]++;
    }

    int b = count['b'-'a'];
    int a = count['a'-'a'];
    int l = count['l'-'a']/2;
    int o = count['o'-'a']/2;
    int n = count['n'-'a'];

    // The std::min Rule
    // In C++, min(a, b) can only compare two items at a time by default. If you want to find the minimum of three or more items, you must wrap them in curly braces {} to turn them into a list.
    int res = min({b,a,l,o,n});

    return res;
}