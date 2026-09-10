// LC 347. Top K Frequent Elements

// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2

// Output: [1,2]


// will be using hashmap for storing frequencies.
struct cmp
{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b)
    {
        if(a.first != b.first)
        {
            return a.first > b.first; // min. heap
        } else
        {
            return a.second > b.second; // min. heap
        }
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        int n = nums.size();
        unordered_map<int,int> freq;

        for(int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
        }
        for(auto i:freq)
        {
            int element = i.first;
            int frequency = i.second;
            pair<int,int> current = {frequency, element};

            if(pq.size() > k)
            {
                pq.push(current);
                continue;
            } else
            {
                if(current.first < pq.top().first) continue;

                pq.pop();
                pq.push(current);
            }
        }
        vector<int> res;
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};