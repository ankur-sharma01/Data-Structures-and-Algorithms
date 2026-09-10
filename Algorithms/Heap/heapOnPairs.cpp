// basically we are starting of with heap with pairs, heap implemented on pair of data provided.

struct cmp
{
    bool operator()(const pair<int,string>& a, const pair<int,string>& b)
    {
        if(a.first != b.first)
        {
            return a.first > b.first; // min. heap
        } else
        {
            return a.second < b.second; // max. heap
        }
    }
};

priority_queue<const pair<int,string>, const vector<pair<int,string>>, cmp> pq;

// cmp --> comparator (is A smaller/larger than B? --> true --> push A down), written using struct.
