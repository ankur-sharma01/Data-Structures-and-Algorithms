// 621. Task Scheduler
// You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

// Return the minimum number of CPU intervals required to complete all tasks.

// Example 1:
// Input: tasks = ["A","A","A","B","B","B"], n = 2

// Output: 8

// Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

// After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

// Example 2:

// Input: tasks = ["A","C","A","B","D","B"], n = 1

// Output: 6

// Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

// With a cooling interval of 1, you can repeat a task after just one other task.



class Solution {
public:
    int leastInterval(vector<char>& tasks, int g) {
        int n = tasks.size();
        unordered_map<char,int> freq;
        unordered_map<char,int> free; // tracks the place where an element can be pushed next.
        priority_queue<pair<int,char>> pq;
        int seat = 1;

        for(int i = 0; i < n; i++)
        {
            freq[tasks[i]]++;
            free[tasks[i]] = 1;
        }

        for(auto i: freq)
        {
            pq.push({i.second, i.first});
        }

        while(!pq.empty())
        {
            // Use vector<pair<A, B>> when you have a fixed pair of elements—especially when they have different data types (like frequency counts and characters). It is faster, uses less memory, and provides type safety. Use vector<vector<T>> when building 2D grids, graphs (adjacency lists), or when inner list sizes vary dynamically.
            vector<pair<int,char>> pulled;
            while(!pq.empty())
            {
                pair<int,char> p = pq.top();
                pq.pop();
                int fr = p.first; // int
                int child = p.second; // char

                if(free[child] <= seat)
                {
                    free[p.second] = seat + g + 1;

                    if(p.first > 1)
                    {
                        pq.push({p.first - 1, p.second});
                    }
                    break;
                } else
                {
                    pulled.push_back(p);
                }
            }
            for(int i = 0; i < pulled.size(); i++)
            {
                pq.push(pulled[i]);
            }
            seat++;

        }
        return seat-1;
    }
};