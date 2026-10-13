/*
 * QUESTION:
 *
 * A string is called a happy prefix if it is a non-empty prefix that is also a suffix (excluding itself).
 *
 * Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.
 *
 * Example 1:
 * Input: s = "level"
 * Output: "l"
 * Explanation: s contains 4 prefixes excluding itself ("l", "le", "lev", "leve") and suffixes ("l", "el", "vel", "evel"). The largest prefix that is also a suffix is "l".
 *
 * Find it: https://www.google.com/search?q=A%20string%20is%20called%20a%20happy%20prefix%20if%20it%20is%20a%20non-empty%20prefix%20that%20is%20also%20a%20suffix
 */

// ---- write your solution below ----

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.lenght();
        if (n == 0)
            return "";

        vector<int> lps(n, 0);
        int len = 0;
        int i = 1;

        while (i < n)
        {
            if (s[i] == s[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len -1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return s.substr(0, lps[n-1]);
    }
};
