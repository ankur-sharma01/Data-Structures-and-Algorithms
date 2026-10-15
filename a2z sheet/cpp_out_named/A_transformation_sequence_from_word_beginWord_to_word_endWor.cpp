/*
 * QUESTION:
 *
 * A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
 * 1. Every adjacent pair of words differs by a single letter.
 * 2. Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
 * 3. sk == endWord
 *
 * Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
 *
 * Find it: https://www.google.com/search?q=A%20transformation%20sequence%20from%20word%20beginWord%20to%20word%20endWord%20using%20a%20dictionary%20wordList%20is%20a%20sequence%20of%20words
 */

// ---- write your solution below ----

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string, int> f;

        for (int i = 0; i < n; i++)
        {
            f[wordList[i]] = 1;
        }
        if (f.find(endWord) == f.end())
            return 0;

        queue<pair<string,int>> q;

        q.push({beginWord, 1});
        // bfs traversal: check for each char in a string if it matches by traversing from a to z:
        while (!q.empty())
        {
            pair<string,int> p = q.front();
            q.pop();
            string s = p.first;
            int steps = p.second;

            if (s == endWord)
                return steps;

            for (int i = 0; i < s.size(); i++)
            {
                char c = s[i];

                for (char k = 'a'; k <= 'z'; k++)
                {
                    if (k == c)
                        continue;

                    s[i] = k;

                    if (s == endWord)
                        return (steps + 1);

                    if (f.find(s) != f.end())
                    {
                        q.push({s, steps+1});
                        f.erase(s);
                    }
                }
                s[i] = c;
            }
        }
        return 0;
    }
};
