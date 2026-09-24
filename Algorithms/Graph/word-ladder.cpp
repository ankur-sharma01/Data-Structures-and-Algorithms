// 127. Word Ladder
// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
// EXAMPLE:
// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.


// BFS:
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string,int> f;

        for (int i = 0; i < n; i++)
        {
            f[wordList[i]] = 1;
        }

        if (f.find(beginWord) == f.end())
            f[beginWord] = 1;
        if (f.find(endWord) == f.end())
            return 0;

        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        f.erase(beginWord);

        while(!q.empty())
        {
            pair<string,int> p = q.front();
            q.pop();
            string s = p.first;
            int val = p.second;

            if (s == endWord)
                return val;

            for (int k = 0; k < s.size(); k++)
            {
                char c = s[k];
                for (int j = 97; j <= 122; j++)
                {
                    if (c == j)
                        continue;

                    s[k] = j;
                    if (f.find(s) != f.end()) // no early exit condition as we have to calculate hops taken and true or false!
                    {
                        q.push({s, val+1});
                        f.erase(s);
                    }
                }
                s[k] = c;
            }
        }
        return 0;
    }
};